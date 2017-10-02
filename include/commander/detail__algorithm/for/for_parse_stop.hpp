//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../../pack_position.hpp"

#include <array>
#include <iterator>
#include <tuple>

namespace commander
{

    template <typename StringView, typename Callback>
    constexpr Callback for_parse_stop(Callback callback)
    {
        using size_type = typename StringView::size_type;

        using character = typename StringView::value_type;
        std::array<character, 3> header_storage = {character('-'), character('-'), character(0)};

        std::tuple<StringView, StringView, pack_position<size_type>> option = {
            {header_storage.data(), 2},
            {header_storage.data(), 2},
            {true, size_type(0), true}
        };
        const auto& const_option = option;

        callback(const_option);
        return callback;
    }

} // namespace commander
