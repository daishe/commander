//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

namespace commander
{

    template <typename T>
    constexpr T&& compare_conjunction(T&& base)
    { return std::forward<T>(base); }

    template <typename T, typename U, typename... Values>
    constexpr decltype(auto) compare_conjunction(T&& base, U&& value, Values&&... values)
    { return (base == std::forward<U>(value)) && ((base == std::forward<Values>(values)) && ...); }

    template <typename T>
    constexpr T&& compare_disjunction(T&& base)
    { return std::forward<T>(base); }

    template <typename T, typename U, typename... Values>
    constexpr decltype(auto) compare_disjunction(T&& base, U&& value, Values&&... values)
    { return (base == std::forward<U>(value)) || ((base == std::forward<Values>(values)) || ...); }

} // namespace commander
