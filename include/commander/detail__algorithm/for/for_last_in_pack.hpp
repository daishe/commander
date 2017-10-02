//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../../pack_position.hpp"
#include "../option.hpp"
#include "for_each_in_pack.hpp"

#include <array>
#include <iterator>
#include <tuple>

namespace commander
{

    template <typename StringView, typename String, typename Callback>
    constexpr Callback for_last_in_pack(const String& candidate, Callback callback)
    {
        if (is_option_pack(candidate) && option_pack_size(candidate) > 1) {
            using size_type = typename StringView::size_type;

            using character = typename StringView::value_type;
            std::array<character, 3> header_storage = {character('-'), character(0), character(0)};

            std::tuple<StringView, StringView, pack_position<size_type>> option = {
                {candidate.data(), candidate.size()},
                {header_storage.data(), 2},
                {false, size_type(option_pack_size(candidate) - 1), true}
            };
            const auto& const_option = option;

            auto pack_it   = std::next(option_header_begin(candidate));
            auto pack_next = std::next(pack_it);
            auto pack_end  = option_header_end(candidate);

            for (; pack_next != pack_end; ++pack_it, ++pack_next) {
                continue;
            }

            header_storage[1] = *pack_it;
            callback(const_option);
            return callback;
        }
        else {
            return for_each_in_pack<StringView>(candidate, callback);
        }
    }

} // namespace commander
