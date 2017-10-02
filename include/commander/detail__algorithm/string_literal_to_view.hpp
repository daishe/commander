//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "compare_characters.hpp"

#include <cstddef>

namespace commander
{

    template <typename StringView, size_t Size>
    constexpr StringView string_literal_to_view(const typename StringView::value_type (& literal)[Size])
    {
        return StringView(
            literal,
            (Size > 0) ? (compare_characters(literal[Size - 1], '\0') ? Size - 1 : Size) : 0
        );
    }

} // namespace commander
