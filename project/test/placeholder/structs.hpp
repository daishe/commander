//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <commander/placeholder.hpp>

#include <type_traits>

struct custom_placeholder : commander::placeholder_t {};
struct custom_struct : std::true_type {};
