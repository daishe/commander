//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../concept.hpp"
#include "../detail__type_traits/size_type.hpp"
#include "compare_characters.hpp"

#include <cstddef>
#include <iterator>
#include <type_traits>

namespace commander
{

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_boolean_true(BeginIterator it, const EndIterator end)
    {
        return (it != end) && (compare_characters(*it, 't') || compare_characters(*it, 'T')) &&
            ((++it) != end) && (compare_characters(*it, 'r') || compare_characters(*it, 'R')) &&
            ((++it) != end) && (compare_characters(*it, 'u') || compare_characters(*it, 'U')) &&
            ((++it) != end) && (compare_characters(*it, 'e') || compare_characters(*it, 'E')) &&
            ((++it) == end);
    }

    template <typename String>
    constexpr bool is_boolean_true(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_boolean_true(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_boolean_false(BeginIterator it, const EndIterator end)
    {
        return (it != end) && (compare_characters(*it, 'f') || compare_characters(*it, 'F')) &&
            ((++it) != end) && (compare_characters(*it, 'a') || compare_characters(*it, 'A')) &&
            ((++it) != end) && (compare_characters(*it, 'l') || compare_characters(*it, 'L')) &&
            ((++it) != end) && (compare_characters(*it, 's') || compare_characters(*it, 'S')) &&
            ((++it) != end) && (compare_characters(*it, 'e') || compare_characters(*it, 'E')) &&
            ((++it) == end);
    }

    template <typename String>
    constexpr bool is_boolean_false(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_boolean_false(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_boolean(BeginIterator it, const EndIterator end)
    { return is_boolean_true(it, end) || is_boolean_false(it, end); }

    template <typename String>
    constexpr bool is_boolean(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_boolean(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_parse_stop(BeginIterator it, const EndIterator end)
    {
        return (it != end) && compare_characters(*it, '-') &&
            ((++it) != end) && compare_characters(*it, '-') &&
            ((++it) == end);
    }

    template <typename String>
    constexpr bool is_parse_stop(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_parse_stop(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_long_option(BeginIterator it, const EndIterator end)
    {
        return (it != end) && compare_characters(*it, '-') &&
            ((++it) != end) && compare_characters(*it, '-') &&
            ((++it) != end) && !compare_characters(*it, '=');
    }

    template <typename String>
    constexpr bool is_long_option(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_long_option(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_option_pack(BeginIterator it, const EndIterator end)
    {
        return (it != end) && compare_characters(*it, '-') &&
            ((++it) != end) && (!compare_characters(*it, '-') && !compare_characters(*it, '='));
    }

    template <typename String>
    constexpr bool is_option_pack(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_option_pack(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator, typename Char>
    constexpr bool option_pack_contains(BeginIterator it, const EndIterator end, const Char& character)
    {
        static_assert(is_character_like_v<Char>);

        if (!is_option_pack(it, end))
            return false;

        ++it;
        for (; it != end; ++it) {
            if (compare_characters(*it, '='))
                return false;

            if (compare_characters(*it, character))
                return true;
        }

        return false;
    }

    template <typename String, typename Char>
    constexpr bool option_pack_contains(const String& candidate, const Char& character)
    {
        static_assert(is_string_like_v<String>);
        static_assert(is_character_like_v<Char>);

        return option_pack_contains(std::begin(candidate), std::end(candidate), character);
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_pack_size(BeginIterator it, const EndIterator end)
    {
        if (is_long_option(it, end))
            return Size(1);

        if (!is_option_pack(it, end))
            return Size(0);

        Size size = 0;

        for (; it != end; ++it, ++size)
            if (compare_characters(*it, '='))
                break;

        return (size > 0) ? (size - 1) : (Size(0));
    }

    template <typename String>
    constexpr auto option_pack_size(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_pack_size<detail::size_type_t<String, size_t>>(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool is_option(BeginIterator it, const EndIterator end)
    { return is_long_option(it, end) || is_option_pack(it, end); }

    template <typename String>
    constexpr bool is_option(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return is_option(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr auto option_header_begin(const BeginIterator begin, const EndIterator)
    { return begin; }

    template <typename String>
    constexpr auto option_header_begin(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_header_begin(std::begin(candidate), std::end(candidate));
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_header_begin_offset(const BeginIterator, const EndIterator)
    { return Size(0); }

    template <typename String>
    constexpr auto option_header_begin_offset(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_header_begin_offset<detail::size_type_t<String, size_t>>(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr auto option_header_end(BeginIterator it, const EndIterator end)
    {
        if (!is_option(it, end))
            return it;

        for (; it != end; ++it)
            if (compare_characters(*it, '='))
                break;

        return it;
    }

    template <typename String>
    constexpr auto option_header_end(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_header_end(std::begin(candidate), std::end(candidate));
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_header_end_offset(BeginIterator it, const EndIterator end)
    {
        if (!is_option(it, end))
            return Size(0);

        Size off(0);

        for (; it != end; ++it, ++off)
            if (compare_characters(*it, '='))
                break;

        return off;
    }

    template <typename String>
    constexpr auto option_header_end_offset(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_header_end_offset<detail::size_type_t<String, size_t>>(std::begin(candidate), std::end(candidate));
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_header_size(const BeginIterator begin, const EndIterator end)
    { return option_header_end_offset<Size>(begin, end) - option_header_begin_offset<Size>(begin, end); }

    template <typename String>
    constexpr auto option_header_size(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_header_size<detail::size_type_t<String, size_t>>(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr bool option_has_value(BeginIterator it, const EndIterator end)
    {
        if (!is_option(it, end))
            return false;

        for (; it != end; ++it)
            if (compare_characters(*it, '='))
                return true;

        return false;
    }

    template <typename String>
    constexpr bool option_has_value(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_has_value(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr auto option_value_begin(BeginIterator it, const EndIterator end)
    {
        if (!is_option(it, end))
            return it;

        for (; it != end; ++it)
            if (compare_characters(*it, '='))
                break;

        if (it != end)
            ++it;

        return it;
    }

    template <typename String>
    constexpr auto option_value_begin(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_value_begin(std::begin(candidate), std::end(candidate));
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_value_begin_offset(BeginIterator it, const EndIterator end)
    {
        if (!is_option(it, end))
            return Size(0);

        Size off(0);

        for (; it != end; ++it, ++off)
            if (compare_characters(*it, '='))
                break;

        if (it != end)
            ++off;

        return off;
    }

    template <typename String>
    constexpr auto option_value_begin_offset(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_value_begin_offset<detail::size_type_t<String, size_t>>(std::begin(candidate), std::end(candidate));
    }

    template <typename BeginIterator, typename EndIterator>
    constexpr auto option_value_end(const BeginIterator, const EndIterator end)
    { return end; }

    template <typename String>
    constexpr auto option_value_end(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_value_end(std::begin(candidate), std::end(candidate));
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_value_end_offset(const BeginIterator begin, const EndIterator end)
    { return static_cast<Size>(std::distance(begin, end)); }

    template <typename String>
    constexpr auto option_value_end_offset(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return std::size(candidate);
    }

    template <typename Size, typename BeginIterator, typename EndIterator>
    constexpr auto option_value_size(const BeginIterator begin, const EndIterator end)
    { return option_value_end_offset<Size>(begin, end) - option_value_begin_offset<Size>(begin, end); }

    template <typename String>
    constexpr auto option_value_size(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return option_value_end_offset(candidate) - option_value_begin_offset(candidate);
    }

    template <typename String>
    constexpr auto option_header(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return String(candidate.data() + option_header_begin_offset(candidate), option_header_size(candidate));
    }

    template <typename String>
    constexpr auto option_value(const String& candidate)
    {
        static_assert(is_string_like_v<String>);

        return String(candidate.data() + option_value_begin_offset(candidate), option_value_size(candidate));
    }

} // namespace commander
