//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename...>
        struct always_false : std::false_type
        {};

        template <typename... Types>
        inline constexpr bool always_false_v = always_false<Types...>::value;

    } // namespace detail

} // namespace commander
