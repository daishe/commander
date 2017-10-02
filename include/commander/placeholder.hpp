//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>
#include <utility>

namespace commander
{

    struct placeholder_t
    {
        explicit constexpr placeholder_t() = default;
    };

    inline constexpr placeholder_t placeholder = placeholder_t();

    template <typename T>
    struct is_placeholder : std::disjunction<std::is_same<placeholder_t, std::decay_t<T>>, std::is_base_of<placeholder_t, std::decay_t<T>>>
    {};

    template <typename T>
    inline constexpr bool is_placeholder_v = is_placeholder<T>::value;

    constexpr bool operator ==(const placeholder_t&, const placeholder_t&)
    { return true; }

    constexpr bool operator !=(const placeholder_t&, const placeholder_t&)
    { return false; }

    namespace func
    {

        template <typename T>
        constexpr auto is_placeholder(T&&)
        {
            if constexpr (commander::is_placeholder_v<T>)
                return std::true_type();
            else
                return std::false_type();
        }

        template <typename T>
        constexpr bool is_placeholder_v(T&& value)
        { return is_placeholder(std::forward<T>(value)).value; }

    } // namespace func

} // namespace commander
