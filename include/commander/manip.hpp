//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "detail__manip/exec.hpp"

#include <type_traits>

namespace commander
{

    template <typename T>
    struct is_manipulator : std::false_type
    {};

    template <typename... Types>
    struct is_manipulator<exec<Types...>> : std::true_type
    {};

    template <typename T>
    inline constexpr bool is_manipulator_v = is_manipulator<T>::value;

} // namespace commander
