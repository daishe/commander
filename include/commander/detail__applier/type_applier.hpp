//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../detail__type_traits/last.hpp"
#include "../type_list.hpp"
#include "invoke_applier.hpp"

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{
    template <typename TypeList, typename... Callbacks>
    class type_applier
    {
        public:
            constexpr explicit type_applier() = default;

            constexpr explicit type_applier(const type_applier<TypeList, Callbacks...>&) = default;

            constexpr explicit type_applier(type_applier<TypeList, Callbacks...>&&) = default;

            constexpr explicit type_applier(const Callbacks&... callbacks) : callbacks_(callbacks...)
            {};

            template <typename... OtherCallbacks>
            constexpr explicit type_applier(OtherCallbacks&&... callbacks) : callbacks_(std::forward<OtherCallbacks>(callbacks)...)
            {}

            constexpr type_applier<TypeList, Callbacks...>& operator =(const type_applier<TypeList, Callbacks...>&) = default;

            constexpr type_applier<TypeList, Callbacks...>& operator =(type_applier<TypeList, Callbacks...>&&) = default;

            template <typename... Types>
            constexpr auto apply(Types&&... values)
            {
                using list = std::conditional_t<is_type_list_v<TypeList>, TypeList, type_list<TypeList>>;

                if constexpr (sizeof...(Types) != 0 && tl::index_of_v<list, std::decay_t<detail::last_t<Types...>>> != tl::npos) {
                    return tuple_visit_disjunction(
                        [&](auto& callback) -> decltype(auto) {
                            if constexpr (decltype(func::is_invokable_applier(callback, values...))::value)
                                return invoke_applier(callback, values...);
                            else
                                return false;
                        },
                        this->callbacks_
                    );
                }
                else {
                    return false;
                }
            }

            template <typename... Types>
            constexpr auto apply(Types&&... values) const
            {
                using list = std::conditional_t<is_type_list_v<TypeList>, TypeList, type_list<TypeList>>;

                if constexpr (sizeof...(Types) != 0 && tl::index_of_v<list, std::decay_t<detail::last_t<Types...>>> != tl::npos) {
                    return tuple_visit_disjunction(
                        [&](const auto& callback) -> decltype(auto) {
                            if constexpr (decltype(func::is_invokable_applier(callback, values...))::value)
                                return invoke_applier(callback, values...);
                            else
                                return false;
                        },
                        this->callbacks_
                    );
                }
                else {
                    return false;
                }
            }

        private:
            std::tuple<Callbacks...> callbacks_;
    };

    template <typename TypeList, typename... Callbacks>
    constexpr auto make_type_applier(Callbacks&&... callbacks)
    {
        using return_type = type_applier<
            detail::unwrap_reference_wrapper_t<std::decay_t<TypeList>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Callbacks>>...
        >;
        return return_type(std::forward<Callbacks>(callbacks)...);
    }

} // namespace commander
