//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "invoke_matcher.hpp"

#include <tuple>
#include <utility>

namespace commander
{
    template <typename... Types>
    class matcher
    {
        public:
            constexpr explicit matcher() = default;

            constexpr explicit matcher(const matcher<Types...>&) = default;

            constexpr explicit matcher(matcher<Types...>&&) = default;


            template <typename... Others>
            constexpr explicit matcher(Others&&... values) : callbacks_(std::forward<Others>(values)...)
            {}

            constexpr matcher<Types...>& operator =(const matcher<Types...>&) = default;

            constexpr matcher<Types...>& operator =(matcher<Types...>&&) = default;

            template <typename... Args>
            constexpr auto match(Args&&... values)
            {
                if constexpr (sizeof...(Types) == 0) {
                    return false;
                }
                else {
                    auto invoker = [&](auto& callback) -> decltype(auto) {
                        if constexpr (func::is_invokable_matcher_v(callback, values...))
                            return invoke_matcher(callback, values...);
                        else
                            return false;
                    };

                    return tuple_visit_disjunction(std::move(invoker), this->callbacks_);
                }
            }

            template <typename... Args>
            constexpr auto match(Args&&... values) const
            {
                if constexpr (sizeof...(Types) == 0) {
                    return false;
                }
                else {
                    auto invoker = [&](const auto& callback) -> decltype(auto) {
                        if constexpr (func::is_invokable_matcher_v(callback, values...))
                            return invoke_matcher(callback, values...);
                        else
                            return false;
                    };

                    return tuple_visit_disjunction(std::move(invoker), this->callbacks_);
                }
            }

        private:
            std::tuple<Types...> callbacks_;
    };

    template <typename... Types>
    matcher(Types...) -> matcher<Types...>;

    template <typename... Types>
    constexpr auto make_matcher(Types&&... values)
    { return matcher<detail::unwrap_reference_wrapper_t<std::decay_t<Types>>...>(std::forward<Types>(values)...); }

} // namespace commander
