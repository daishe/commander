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

        struct invoke_matcher_test
        {
            template <typename Matcher, typename... Types>
            static auto check_member(Matcher&& matcher, Types&&... values) -> std::is_convertible<decltype(std::forward<Matcher>(matcher).match(std::forward<Types>(values)...)), bool>;

            static std::false_type check_member(...);

            template <typename Matcher, typename... Types>
            static auto check_operator(Matcher&& matcher, Types&&... values) -> std::is_convertible<decltype(std::forward<Matcher>(matcher)(std::forward<Types>(values)...)), bool>;

            static std::false_type check_operator(...);

            // template <typename Matcher, typename... Types, std::enable_if_t<sizeof...(Types) != 0, bool> = false>
            // static auto check_member(Matcher&& matcher, Types&&... values, decltype(
            //     std::forward<Matcher>(matcher).match(std::forward<Types>(values)...)
            // )* result = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(result)>, bool>;

            // template <typename Matcher, typename... Types, std::enable_if_t<sizeof...(Types) == 0, bool> = false>
            // static auto check_member(Matcher&& matcher, Types&&... values, decltype(
            //     std::forward<Matcher>(matcher).match()
            // )* result = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(result)>, bool>;

            // static std::false_type check_member(...);

            // template <typename Matcher, typename... Types, std::enable_if_t<sizeof...(Types) != 0, bool> = false>
            // static auto check_operator(Matcher&& matcher, Types&&... values, decltype(
            //     std::forward<Matcher>(matcher)(std::forward<Types>(values)...)
            // )* result = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(result)>, bool>;

            // template <typename Matcher, typename... Types, std::enable_if_t<sizeof...(Types) == 0, bool> = false>
            // static auto check_operator(Matcher&& matcher, Types&&... values, decltype(
            //     std::forward<Matcher>(matcher)()
            // )* result = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(result)>, bool>;

            // static std::false_type check_operator(...);

            // template <typename Matcher, typename T1, typename T2, typename T3, typename T4>
            // static auto member_4(Matcher&& matcher, T1&& v1, T2&& v2, T3&& v3, T4&& v4, decltype(
            //     std::forward<Matcher>(matcher).match(std::forward<T1>(v1), std::forward<T2>(v2), std::forward<T3>(v3), std::forward<T4>(v4))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type member_4(...);

            // template <typename Matcher, typename T1, typename T2, typename T3>
            // static auto member_3(Matcher&& matcher, T1&& v1, T2&& v2, T3&& v3, decltype(
            //     std::forward<Matcher>(matcher).match(std::forward<T1>(v1), std::forward<T2>(v2), std::forward<T3>(v3))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type member_3(...);

            // template <typename Matcher, typename T1, typename T2>
            // static auto member_2(Matcher&& matcher, T1&& v1, T2&& v2, decltype(
            //     std::forward<Matcher>(matcher).match(std::forward<T1>(v1), std::forward<T2>(v2))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type member_2(...);

            // template <typename Matcher, typename T1>
            // static auto member_1(Matcher&& matcher, T1&& v1, decltype(
            //     std::forward<Matcher>(matcher).match(std::forward<T1>(v1))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type member_1(...);

            // template <typename Matcher, typename T1, typename T2, typename T3, typename T4>
            // static auto operator_4(Matcher&& matcher, T1&& v1, T2&& v2, T3&& v3, T4&& v4, decltype(
            //     std::forward<Matcher>(matcher)(std::forward<T1>(v1), std::forward<T2>(v2), std::forward<T3>(v3), std::forward<T4>(v4))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type operator_4(...);

            // template <typename Matcher, typename T1, typename T2, typename T3>
            // static auto operator_3(Matcher&& matcher, T1&& v1, T2&& v2, T3&& v3, decltype(
            //     std::forward<Matcher>(matcher)(std::forward<T1>(v1), std::forward<T2>(v2), std::forward<T3>(v3))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type operator_3(...);

            // template <typename Matcher, typename T1, typename T2>
            // static auto operator_2(Matcher&& matcher, T1&& v1, T2&& v2, decltype(
            //     std::forward<Matcher>(matcher)(std::forward<T1>(v1), std::forward<T2>(v2))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type operator_2(...);

            // template <typename Matcher, typename T1>
            // static auto operator_1(Matcher&& matcher, T1&& v1, decltype(
            //     std::forward<Matcher>(matcher)(std::forward<T1>(v1))
            // )* r = nullptr) -> std::is_convertible<std::remove_pointer_t<decltype(r)>, bool>;

            // static std::false_type operator_1(...);
        };

        // template <typename Matcher, typename... Types>
        // constexpr auto is_member_invokable_matcher(Matcher&& matcher, Types&&... values)
        // {
        //     return std::integral_constant<bool,
        //         decltype(detail::invoke_matcher_test::member_4(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::member_3(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::member_2(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::member_1(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value
        //     >();
        // }

        // template <typename Matcher, typename... Types>
        // constexpr bool is_member_invokable_matcher_v(Matcher&& matcher, Types&&... values)
        // { return is_member_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Types>(values)...).value; }

        // template <typename Matcher, typename... Types>
        // constexpr auto is_operator_invokable_matcher(Matcher&& matcher, Types&&... values)
        // {
        //     return std::integral_constant<bool,
        //         decltype(detail::invoke_matcher_test::operator_4(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::operator_3(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::operator_2(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::operator_1(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value
        //     >();
        // }

        // template <typename Matcher, typename... Types>
        // constexpr bool is_operator_invokable_matcher_v(Matcher&& matcher, Types&&... values)
        // { return is_member_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Types>(values)...).value; }

    } // namespace detail

    namespace func
    {

        template <typename Matcher>
        constexpr auto is_invokable_matcher(Matcher&& matcher)
        {
            return std::integral_constant<bool,
                decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher)))::value ||
                decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher)))::value
            >();
        }

        template <typename Matcher, typename T, typename... Types>
        constexpr auto is_invokable_matcher(Matcher&& matcher, T&& value, Types&&... values)
        {
            if constexpr (decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher), std::forward<T>(value), std::forward<Types>(values)...))::value || decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher), std::forward<T>(value), std::forward<Types>(values)...))::value)
                return std::true_type();
            else
                return is_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Types>(values)...);
        }

        // template <typename Matcher, typename... Types, std::enable_if_t<sizeof...(Types) == 0, bool> = false>
        // constexpr auto is_invokable_matcher(Matcher&& matcher, Types&&... values)
        // {
        //     return std::integral_constant<bool,
        //         decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value ||
        //         decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher), std::forward<Types>(values)...))::value
        //     >();
        // }

        template <typename Matcher, typename... Types>
        constexpr bool is_invokable_matcher_v(Matcher&& matcher, Types&&... values)
        { return is_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Types>(values)...).value; }

    } // namespace func

    template <typename Matcher, typename... Types>
    struct is_invokable_matcher : decltype(func::is_invokable_matcher(std::declval<Matcher>(), std::declval<Types>()...))
    {};

    template <typename Matcher, typename... Types>
    inline constexpr bool is_invokable_matcher_v = is_invokable_matcher<Matcher, Types...>::value;

    template <typename Matcher>
    constexpr decltype(auto) invoke_matcher(Matcher&& matcher)
    {
        if constexpr (decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher)))::value)
            return matcher.match();
        else if constexpr (decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher)))::value)
            return matcher();
        else
            static_assert(detail::always_false_v<Matcher>, "No kown way to invoke given matcher");
    }

    template <typename Matcher, typename T, typename... Types>
    constexpr decltype(auto) invoke_matcher(Matcher&& matcher, T&& value, Types&&... values)
    {
        if constexpr (decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher), std::forward<T>(value), std::forward<Types>(values)...))::value)
            return matcher.match(std::forward<T>(value), std::forward<Types>(values)...);
        else if constexpr (decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher), std::forward<T>(value), std::forward<Types>(values)...))::value)
            return matcher(std::forward<T>(value), std::forward<Types>(values)...);
        else {
            if constexpr (sizeof...(values) != 0)
                return invoke_matcher(std::forward<Matcher>(matcher), std::forward<Types>(values)...);
            else if constexpr (decltype(detail::invoke_matcher_test::check_member(std::forward<Matcher>(matcher)))::value)
                return matcher.match();
            else if constexpr (decltype(detail::invoke_matcher_test::check_operator(std::forward<Matcher>(matcher)))::value)
                return matcher();
            else
                static_assert(detail::always_false_v<Matcher>, "No kown way to invoke given matcher");
        }
    }

    // template <typename Matcher, typename Command, typename Storage, typename Argument, typename Header>
    // constexpr decltype(auto) invoke_matcher(Matcher&& matcher, Command&& command, Storage&& storage, Argument&& argument, Header&& header)
    // {
    //     if constexpr (decltype(detail::invoke_matcher_test::member_4(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //         return matcher.match(std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header));
    //     else if constexpr (decltype(detail::invoke_matcher_test::member_3(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //         return matcher.match(std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header));
    //     else if constexpr (decltype(detail::invoke_matcher_test::member_2(std::forward<Matcher>(matcher), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //         return matcher.match(std::forward<Argument>(argument), std::forward<Header>(header));
    //     else if constexpr (decltype(detail::invoke_matcher_test::member_1(std::forward<Matcher>(matcher), std::forward<Header>(header)))::value)
    //         return matcher.match(std::forward<Header>(header));
    //     else
    //     {
    //         if constexpr (decltype(detail::invoke_matcher_test::operator_4(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //             return matcher(std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header));
    //         else if constexpr (decltype(detail::invoke_matcher_test::operator_3(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //             return matcher(std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header));
    //         else if constexpr (decltype(detail::invoke_matcher_test::operator_2(std::forward<Matcher>(matcher), std::forward<Argument>(argument), std::forward<Header>(header)))::value)
    //             return matcher(std::forward<Argument>(argument), std::forward<Header>(header));
    //         else if constexpr (decltype(detail::invoke_matcher_test::operator_1(std::forward<Matcher>(matcher), std::forward<Header>(header)))::value)
    //             return matcher(std::forward<Header>(header));
    //         else
    //             static_assert(detail::always_false_v<Matcher>, "No kown way to invoke given matcher");
    //     }
    // }

    // template <typename Matcher, typename Command, typename Storage, typename Option>
    // constexpr decltype(auto) invoke_matcher(Matcher&& matcher, Command&& command, Storage&& storage, Option&& option)
    // {
    //     if constexpr (decltype(detail::invoke_matcher_test::member_3(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option)))::value)
    //         return matcher.match(std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option));
    //     else if constexpr (decltype(detail::invoke_matcher_test::member_2(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Option>(option)))::value)
    //         return matcher.match(std::forward<Storage>(storage), std::forward<Option>(option));
    //     else if constexpr (decltype(detail::invoke_matcher_test::member_1(std::forward<Matcher>(matcher), std::forward<Option>(option)))::value)
    //         return matcher.match(std::forward<Option>(option));
    //     else {
    //         if constexpr (decltype(detail::invoke_matcher_test::operator_3(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option)))::value)
    //             return matcher(std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option));
    //         else if constexpr (decltype(detail::invoke_matcher_test::operator_2(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Option>(option)))::value)
    //             return matcher(std::forward<Storage>(storage), std::forward<Option>(option));
    //         else if constexpr (decltype(detail::invoke_matcher_test::operator_1(std::forward<Matcher>(matcher), std::forward<Option>(option)))::value)
    //             return matcher(std::forward<Option>(option));
    //         else
    //             static_assert(detail::always_false_v<Matcher>, "No kown way to invoke given matcher");
    //     }
    // }


    // template <typename Matcher, typename Command, typename Storage, typename Argument, typename Header>
    // constexpr auto is_invokable_matcher(Matcher&& matcher, Command&& command, Storage&& storage, Argument&& argument, Header&& header)
    // {
    //     return std::integral_constant<bool,
    //         decltype(detail::invoke_matcher_test::member_4(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::member_3(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::member_2(std::forward<Matcher>(matcher), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::member_1(std::forward<Matcher>(matcher), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_4(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_3(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_2(std::forward<Matcher>(matcher), std::forward<Argument>(argument), std::forward<Header>(header)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_1(std::forward<Matcher>(matcher), std::forward<Header>(header)))::value
    //     >();
    // }

    // template <typename Matcher, typename Command, typename Storage, typename Option>
    // constexpr auto is_invokable_matcher(Matcher&& matcher, Command&& command, Storage&& storage, Option&& option)
    // {
    //     return std::integral_constant<bool,
    //         decltype(detail::invoke_matcher_test::member_3(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option)))::value ||
    //         decltype(detail::invoke_matcher_test::member_2(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Option>(option)))::value ||
    //         decltype(detail::invoke_matcher_test::member_1(std::forward<Matcher>(matcher), std::forward<Option>(option)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_3(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_2(std::forward<Matcher>(matcher), std::forward<Storage>(storage), std::forward<Option>(option)))::value ||
    //         decltype(detail::invoke_matcher_test::operator_1(std::forward<Matcher>(matcher), std::forward<Option>(option)))::value
    //     >();
    // }

    // template <typename Matcher, typename Command, typename Storage, typename Argument, typename Header>
    // constexpr bool is_invokable_matcher_v(Matcher&& matcher, Command&& command, Storage&& storage, Argument&& argument, Header&& header)
    // { return is_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Argument>(argument), std::forward<Header>(header)).value; }

    // template <typename Matcher, typename Command, typename Storage, typename Option>
    // constexpr bool is_invokable_matcher_v(Matcher&& matcher, Command&& command, Storage&& storage, Option&& option)
    // { return is_invokable_matcher(std::forward<Matcher>(matcher), std::forward<Command>(command), std::forward<Storage>(storage), std::forward<Option>(option)).value; }

} // namespace commander
