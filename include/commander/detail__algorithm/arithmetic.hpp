//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <limits>
#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename First, typename Second>
        constexpr bool arithmetic_compare(const First& first, const Second& second)
        {
            using T1 = std::decay_t<First>;
            using T2 = std::decay_t<Second>;

            if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>) {
                if constexpr (std::is_same_v<T1, bool> || std::is_same_v<T2, bool>) {
                    return first == second;
                }
                else if constexpr (std::is_integral_v<T1> && std::is_integral_v<T2>) {
                    if constexpr ((std::is_signed_v<T1> && std::is_signed_v<T2>) || (!std::is_signed_v<T1> && !std::is_signed_v<T2>))
                        return first == second;
                    else if constexpr (!std::is_signed_v<T1> && std::is_signed_v<T2>)
                        return second >= 0 && first == static_cast<std::make_unsigned_t<T2>>(second);
                    else // if constexpr (std::is_signed_v<T1> && !std::is_signed_v<T2>)
                        return first >= 0 && static_cast<std::make_unsigned_t<T1>>(first) == second;
                }
                else {
                    return first == second;
                }
            }

            return false;
        }

        template <typename Range, typename Value>
        constexpr bool in_arithmetic_range(const Value& value)
        {
            using T1 = std::decay_t<Range>;
            using T2 = std::decay_t<Value>;

            if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>) {
                if constexpr (std::is_same_v<T1, bool> || std::is_same_v<T2, bool>) {
                    return true;
                }
                else if constexpr (std::is_integral_v<T1> && std::is_integral_v<T2>) {
                    if constexpr ((std::is_signed_v<T1> && std::is_signed_v<T2>) || (!std::is_signed_v<T1> && !std::is_signed_v<T2>))
                        return value >= std::numeric_limits<T1>::lowest() && value <= std::numeric_limits<T1>::max();
                    else if constexpr (!std::is_signed_v<T1> && std::is_signed_v<T2>)
                        return value >= 0 && static_cast<std::make_unsigned_t<T2>>(value) <= std::numeric_limits<T1>::max();
                    else // if constexpr (std::is_signed_v<T1> && !std::is_signed_v<T2>)
                        return value <= static_cast<std::make_unsigned_t<T1>>(std::numeric_limits<T1>::max());
                }
                else {
                    return value >= std::numeric_limits<T1>::lowest() && value <= std::numeric_limits<T1>::max();
                }
            }

            return false;
        }

    } // namespace detail

} // namespace commander
