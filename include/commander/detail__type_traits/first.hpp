//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace commander
{

    namespace detail
    {

        template <typename...>
        struct first;

        template <>
        struct first<>
        {
            using type = void;
        };

        template <typename T, typename... Types>
        struct first<T, Types...>
        {
            using type = T;
        };

        template <typename... Types>
        using first_t = typename first<Types...>::type;

    } // namespace detail

} // namespace commander
