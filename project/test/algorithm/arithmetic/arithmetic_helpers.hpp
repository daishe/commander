//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>

template <typename T>
using nl = std::numeric_limits<T>;

template <typename To, typename From>
To sc(const From& from)
{ return static_cast<To>(from); }

template <typename To, typename From>
To sc(const From& from, const int& add)
{ return static_cast<To>(static_cast<To>(from) + add); }

class non_arithmetic_true
{};

constexpr bool operator ==(const non_arithmetic_true&, const non_arithmetic_true&)
{ return true; }

template <typename T>
constexpr bool operator ==(const non_arithmetic_true&, const T&)
{ return true; }

template <typename T>
constexpr bool operator ==(const T&, const non_arithmetic_true&)
{ return true; }

class non_arithmetic_false
{};

constexpr bool operator ==(const non_arithmetic_false&, const non_arithmetic_false&)
{ return true; }

template <typename T>
constexpr bool operator ==(const non_arithmetic_false&, const T&)
{ return true; }

template <typename T>
constexpr bool operator ==(const T&, const non_arithmetic_false&)
{ return true; }
