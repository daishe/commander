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
        struct last;

        template <>
        struct last<>
        {
            using type = void;
        };

        template <typename T>
        struct last<T>
        {
            using type = T;
        };

        template <typename T1, typename T2, typename... Types>
        struct last<T1, T2, Types...>
        {
            using type = typename last<T2, Types...>::type;
        };

        template <typename... Types>
        using last_t = typename last<Types...>::type;

    } // namespace detail

} // namespace commander
