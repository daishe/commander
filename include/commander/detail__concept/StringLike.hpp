//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../detail__type_traits/is_string_like.hpp"

namespace commander
{

    template <typename T>
    struct is_string_like : detail::is_string_like<T>
    {};

    template <typename T>
    inline constexpr bool is_string_like_v = is_string_like<T>::value;

    #ifndef COMMANDER_DISABLE_CONCEPTS

        // Let's wait for C++20
        // template <typename T>
        // concept StringLike = is_string_like<T>::value;

    #endif

} // namespace commander
