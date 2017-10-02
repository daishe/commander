//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../detail__type_traits/is_traversable.hpp"
#include "../no_value.hpp"
#include "../placeholder.hpp"
#include "arithmetic.hpp"
#include "option.hpp"

#include <cmath>
#include <limits>
#include <optional>
#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename To, typename From>
        constexpr std::optional<To> as_impl(const From& value)
        {
            using T1 = std::decay_t<To>;
            using T2 = std::decay_t<From>;

            if constexpr (commander::is_no_value_v<T2> || commander::is_placeholder_v<T2>)
                return std::nullopt;
            else if constexpr (std::is_same_v<T1, T2>)
                return value;
            else if constexpr (std::is_constructible_v<T1, T2> || std::is_convertible_v<T2, T1>)
                return std::optional<To>(std::in_place, value);

            return std::nullopt;
        }

        template <typename To, typename From>
        constexpr std::optional<To> as_arithmetic__inf(const From& value)
        {
            using T1 = std::decay_t<To>;

            if constexpr (std::numeric_limits<T1>::has_infinity) {
                if constexpr (std::numeric_limits<T1>::is_signed)
                    return (value < 0) ? -std::numeric_limits<T1>::infinity() : std::numeric_limits<T1>::infinity();
                else
                    return (value < 0) ? std::nullopt : std::numeric_limits<T1>::infinity();
            }

            return std::nullopt;
        }

        template <typename To, typename From>
        constexpr std::optional<To> as_arithmetic__in_range(const From& value)
        { return detail::in_arithmetic_range<To>(value) ? static_cast<To>(value) : std::nullopt; }

        template <typename To, typename From>
        constexpr std::optional<To> as_arithmetic(const From& value)
        {
            using T1 = std::decay_t<To>;
            using T2 = std::decay_t<From>;

            if constexpr (commander::is_no_value_v<T2> || commander::is_placeholder_v<T2>) {
                return std::nullopt;
            }
            else if constexpr (std::is_same_v<T1, T2>) {
                return value;
            }
            else if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>) {
                if (std::is_integral_v<T1> && std::is_floating_point_v<T2>) {
                    if constexpr (std::numeric_limits<T2>::has_infinity)
                        if (std::isinf(value))
                            return as_arithmetic__inf<To>(value);

                    if (std::isfinite(value) && value == std::round(value))
                        return as_arithmetic__in_range<To>(value);

                    return std::nullopt;
                }
                else {
                    if constexpr (std::numeric_limits<T2>::has_infinity)
                        if (std::isinf(value))
                            return as_arithmetic__inf<To>(value);

                    if (std::isfinite(value))
                        return as_arithmetic__in_range<To>(value);

                    return std::nullopt;
                }
            }

            return as_impl<To>(value);
        }

        template <typename From>
        constexpr std::optional<bool> as_bool(const From& value)
        {
            using T2 = std::decay_t<From>;

            if constexpr (commander::is_no_value_v<T2> || commander::is_placeholder_v<T2>)
                return false;
            else if constexpr (std::is_same_v<bool, T2>)
                return value;
            else if constexpr (std::is_arithmetic_v<T2>)
                return detail::in_arithmetic_range<bool>(value) ? detail::arithmetic_compare(value, true) : std::nullopt;
            else if constexpr (std::is_constructible_v<bool, T2> || std::is_convertible_v<T2, bool>)
                return std::optional<bool>(std::in_place, value);
            else if constexpr (is_traversable_v<T2>) {
                if (commander::is_boolean(value))
                    return commander::is_boolean_true(value);
            }

            return as_impl<bool>(value);
        }

    } // namespace detail

    template <typename To, typename From>
    constexpr std::optional<To> as(const From& value)
    {
        using T1 = std::decay_t<To>;
        using T2 = std::decay_t<From>;

        if constexpr (std::is_same_v<bool, T1>)
            return as_bool(value);

        if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>)
            return detail::as_arithmetic<To>(value);

        return detail::as_impl<To>(value);
    }

} // namespace commander
