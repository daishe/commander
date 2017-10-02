//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "is_character_like.hpp"
#include "is_traversable.hpp"
#include "traversable_value_type.hpp"

#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename T>
        struct is_string_like : std::conjunction<is_traversable<T>, is_character_like<traversable_value_type_t<T>>>
        {};

        template <typename T>
        inline constexpr bool is_string_like_v = is_string_like<T>::value;

    } // namespace detail

} // namespace commander
