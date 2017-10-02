//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>
#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <size_t, typename, typename...>
        struct index_of_impl;

        template <size_t Idx, typename T>
        struct index_of_impl<Idx, T> : std::integral_constant<size_t, size_t(-1)>
        {};

        template <size_t Idx, typename T, typename First, typename... Others>
        struct index_of_impl<Idx, T, First, Others...>
            : std::conditional_t<std::is_same_v<T, First>, std::integral_constant<size_t, Idx>, index_of_impl<Idx + 1, T, Others...>>
        {};

        template <typename T, typename... Types>
        struct index_of : index_of_impl<size_t(0), T, Types...>
        {};

        template <typename T, typename... Types>
        inline constexpr size_t index_of_v = index_of<T, Types...>::value;

    } // namespace detail

} // namespace commander
