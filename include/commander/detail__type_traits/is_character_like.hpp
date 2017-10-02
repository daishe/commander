//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "is_equality_comparable.hpp"

#include <type_traits>
#include <utility>

namespace commander
{

    namespace detail
    {

        // template <typename T>
        // struct is_character_like_comparable
        // {
        //     private:
        //         static char     char8_type();
        //         static char16_t char16_type();
        //         static char32_t char32_type();
        //         static wchar_t  wchar_type();

        //         template <typename U>
        //         static auto test(const U& character, const char& c8 = char(0), const char16_t& c16 = char16_t(0), const char32_t& c32 = char32_t(0), const wchar_t& wc = wchar_t(0)) -> std::conjunction<
        //             std::is_convertible<decltype(character == c8),  bool>, std::is_convertible<decltype(c8  == character), bool>,
        //             std::is_convertible<decltype(character == c16), bool>, std::is_convertible<decltype(c16 == character), bool>,
        //             std::is_convertible<decltype(character == c32), bool>, std::is_convertible<decltype(c32 == character), bool>,
        //             std::is_convertible<decltype(character == wc),  bool>, std::is_convertible<decltype(wc  == character), bool>
        //         >;

        //         static std::false_type test(...);

        //     public:
        //         using type = decltype(test(std::declval<T>()));
        // };

        template <typename T>
        struct is_character_like : std::conjunction<
            // typename is_character_like_comparable<T>::type,
            is_equality_comparable<const std::decay_t<T>&, const char&>,
            is_equality_comparable<const std::decay_t<T>&, const char16_t&>,
            is_equality_comparable<const std::decay_t<T>&, const char32_t&>,
            is_equality_comparable<const std::decay_t<T>&, const wchar_t&>,
            std::is_constructible<std::decay_t<T>, char>,
            std::is_constructible<std::decay_t<T>, char16_t>,
            std::is_constructible<std::decay_t<T>, char32_t>,
            std::is_constructible<std::decay_t<T>, wchar_t>
        >
        {};

        template <typename T>
        inline constexpr bool is_character_like_v = is_character_like<T>::value;

    } // namespace detail

} // namespace commander
