//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../../pack_position.hpp"
#include "../option.hpp"

#include <array>
#include <iterator>
#include <tuple>

namespace commander
{

    template <typename StringView, typename String, typename Callback>
    constexpr Callback for_each_in_pack(const String& candidate, Callback callback)
    {
        using size_type = typename StringView::size_type;

        std::tuple<StringView, StringView, pack_position<size_type>> option = {
            {candidate.data(), candidate.size()},
            {candidate.data() + option_header_begin_offset(candidate), option_header_size(candidate)},
            {true, size_type(0), true}
        };
        const auto& const_option = option;

        if (is_long_option(candidate) || option_pack_size(candidate) == 1) {
            callback(const_option);
            return callback;
        }

        if (is_option_pack(candidate)) {
            using character = typename StringView::value_type;
            std::array<character, 3> header_storage = {character('-'), character(0), character(0)};
            std::get<1>(option) = StringView(header_storage.data(), 2);
            std::get<2>(option) = pack_position<size_type>({false, size_type(-1), false});

            auto pack_begin = std::next(option_header_begin(candidate));
            auto pack_it    = pack_begin;
            auto pack_next  = std::next(pack_begin);
            auto pack_end   = option_header_end(candidate);

            auto update_pack_position = [&pack_begin, &pack_it, &pack_next, &pack_end](pack_position<size_type>& ppos) {
                ppos.is_first = (pack_begin == pack_it);
                ppos.exact    += 1;
                ppos.is_last  = (pack_next == pack_end);
            };

            for (; pack_it != pack_end; ++pack_it, ++pack_next) {
                header_storage[1] = *pack_it;
                update_pack_position(std::get<2>(option));
                callback(const_option);
            }

            return callback;
        }

        {
            using character = typename StringView::value_type;
            std::array<character, 3> header_storage = {character('-'), character('-'), character(0)};
            std::get<1>(option) = StringView(header_storage.data(), 2);

            callback(const_option);
            return callback;
        }

    }

} // namespace commander
