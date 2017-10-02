//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "invoke_applier.hpp"

#include <tuple>
#include <utility>

namespace commander
{
    template <typename... Callbacks>
    class applier
    {
        public:
            constexpr explicit applier() = default;

            constexpr explicit applier(const applier<Callbacks...>&) = default;

            constexpr explicit applier(applier<Callbacks...>&&) = default;

            constexpr explicit applier(const Callbacks&... callbacks) : callbacks_(callbacks...)
            {};

            template <typename... OtherCallbacks>
            constexpr explicit applier(OtherCallbacks&&... callbacks) : callbacks_(std::forward<OtherCallbacks>(callbacks)...)
            {}

            constexpr applier<Callbacks...>& operator =(const applier<Callbacks...>&) = default;

            constexpr applier<Callbacks...>& operator =(applier<Callbacks...>&&) = default;

            template <typename... Args>
            constexpr auto apply(Args&&... values)
            {
                if constexpr (sizeof...(Callbacks) == 0) {
                    return false;
                }
                else {
                    auto invoker = [&](auto& callback) -> decltype(auto) {
                        if constexpr (decltype(func::is_invokable_applier(callback, values...))::value)
                            return invoke_applier(callback, values...);
                        else
                            return false;
                    };

                    return tuple_visit_disjunction(std::move(invoker), this->callbacks_);
                }
            }

            template <typename... Args>
            constexpr auto apply(Args&&... values) const
            {
                if constexpr (sizeof...(Callbacks) == 0) {
                    return false;
                }
                else {
                    auto invoker = [&](const auto& callback) -> decltype(auto) {
                        if constexpr (decltype(func::is_invokable_applier(callback, values...))::value)
                            return invoke_applier(callback, values...);
                        else
                            return false;
                    };

                    return tuple_visit_disjunction(std::move(invoker), this->callbacks_);
                }
            }

        private:
            std::tuple<Callbacks...> callbacks_;
    };

    template <typename... Callbacks>
    applier(Callbacks...) -> applier<Callbacks...>;

    template <typename... Callbacks>
    constexpr auto make_applier(Callbacks&&... callbacks)
    { return applier<detail::unwrap_reference_wrapper_t<std::decay_t<Callbacks>>...>(std::forward<Callbacks>(callbacks)...); }

} // namespace commander
