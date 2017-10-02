//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../detail__type_traits/always_false.hpp"

#include <utility>

namespace commander
{

    namespace detail
    {

        struct invoke_applier_test
        {
            template <typename Applier, typename... Types>
            static auto check_member(Applier&& applier, Types&&... values) -> std::is_convertible<decltype(std::forward<Applier>(applier).apply(std::forward<Types>(values)...)), bool>;

            static std::false_type check_member(...);

            template <typename Applier, typename... Types>
            static auto check_operator(Applier&& applier, Types&&... values) -> std::is_convertible<decltype(std::forward<Applier>(applier)(std::forward<Types>(values)...)), bool>;

            static std::false_type check_operator(...);
        };

    } // namespace detail

    namespace func
    {

        template <typename Applier>
        constexpr auto is_invokable_applier(Applier&& applier)
        {
            return std::integral_constant<bool,
                decltype(detail::invoke_applier_test::check_member(std::forward<Applier>(applier)))::value ||
                decltype(detail::invoke_applier_test::check_operator(std::forward<Applier>(applier)))::value
            >();
        }

        template <typename Applier, typename T, typename... Types>
        constexpr auto is_invokable_applier(Applier&& applier, T&& value, Types&&... values)
        {
            if constexpr (decltype(detail::invoke_applier_test::check_member(std::forward<Applier>(applier), std::forward<T>(value), std::forward<Types>(values)...))::value || decltype(detail::invoke_applier_test::check_operator(std::forward<Applier>(applier), std::forward<T>(value), std::forward<Types>(values)...))::value)
                return std::true_type();
            else
                return is_invokable_applier(std::forward<Applier>(applier), std::forward<Types>(values)...);
        }

        template <typename Applier, typename... Types>
        constexpr bool is_invokable_applier_v(Applier&& applier, Types&&... values)
        { return is_invokable_applier(std::forward<Applier>(applier), std::forward<Types>(values)...).value; }

    } // namespace func

    template <typename Applier, typename... Types>
    struct is_invokable_applier : decltype(func::is_invokable_applier(std::declval<Applier>(), std::declval<Types>()...))
    {};

    template <typename Applier, typename... Types>
    inline constexpr bool is_invokable_applier_v = is_invokable_applier<Applier, Types...>::value;

    template <typename Applier>
    constexpr decltype(auto) invoke_applier(Applier&& applier)
    {
        if constexpr (decltype(detail::invoke_applier_test::check_member(std::forward<Applier>(applier)))::value)
            return applier.apply();
        else if constexpr (decltype(detail::invoke_applier_test::check_operator(std::forward<Applier>(applier)))::value)
            return applier();
        else
            static_assert(detail::always_false_v<Applier>, "No kown way to invoke given applier");
    }

    template <typename Applier, typename T, typename... Types>
    constexpr decltype(auto) invoke_applier(Applier&& applier, T&& value, Types&&... values)
    {
        if constexpr (decltype(detail::invoke_applier_test::check_member(std::forward<Applier>(applier), std::forward<T>(value), std::forward<Types>(values)...))::value)
            return applier.apply(std::forward<T>(value), std::forward<Types>(values)...);
        else if constexpr (decltype(detail::invoke_applier_test::check_operator(std::forward<Applier>(applier), std::forward<T>(value), std::forward<Types>(values)...))::value)
            return applier(std::forward<T>(value), std::forward<Types>(values)...);
        else {
            if constexpr (sizeof...(values) != 0)
                return invoke_applier(std::forward<Applier>(applier), std::forward<Types>(values)...);
            else if constexpr (decltype(detail::invoke_applier_test::check_member(std::forward<Applier>(applier)))::value)
                return applier.apply();
            else if constexpr (decltype(detail::invoke_applier_test::check_operator(std::forward<Applier>(applier)))::value)
                return applier();
            else
                static_assert(detail::always_false_v<Applier>, "No kown way to invoke given applier");
        }
    }

} // namespace commander
