//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../concept.hpp"
#include "arithmetic.hpp"

#include <type_traits>

namespace commander
{

    template <typename FirstChar, typename SecondChar>
    constexpr bool compare_characters(const FirstChar& first_char, const SecondChar& second_char)
    {
        static_assert(is_character_like_v<FirstChar>);
        static_assert(is_character_like_v<SecondChar>);

        if constexpr (std::is_arithmetic_v<FirstChar> && std::is_arithmetic_v<SecondChar>)
            return detail::arithmetic_compare(first_char, second_char);
        else
            return first_char == second_char;
    }

} // namespace commander
