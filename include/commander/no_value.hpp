//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>
#include <utility>

namespace commander
{

    struct no_value_t
    {
        explicit constexpr no_value_t() = default;
    };

    inline constexpr no_value_t no_value = no_value_t();

    template <typename T>
    struct is_no_value : std::disjunction<std::is_same<no_value_t, std::decay_t<T>>, std::is_base_of<no_value_t, std::decay_t<T>>>
    {};

    template <typename T>
    inline constexpr bool is_no_value_v = is_no_value<T>::value;

    constexpr bool operator ==(const no_value_t&, const no_value_t&)
    { return true; }

    constexpr bool operator !=(const no_value_t&, const no_value_t&)
    { return false; }

    namespace func
    {

        template <typename T>
        constexpr auto is_no_value(T&&)
        {
            if constexpr (commander::is_no_value_v<T>)
                return std::true_type();
            else
                return std::false_type();
        }

        template <typename T>
        constexpr bool is_no_value_v(T&& value)
        { return is_no_value(std::forward<T>(value)).value; }

    } // namespace func

} // namespace commander
