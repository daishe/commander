//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <exception>
#include <type_traits>

struct non_comparable {};

struct bool_wrapper
{
    bool value;

    bool_wrapper(bool val) : value(val)
    {};

    bool_wrapper operator !() const
    { return bool_wrapper(!this->value); };

    bool_wrapper operator ==(const bool_wrapper& other) const
    { return bool_wrapper(this->value == other.value); };

    bool_wrapper operator &&(const bool_wrapper& other) const
    { return bool_wrapper(this->value && other.value); };

    bool_wrapper operator ||(const bool_wrapper& other) const
    { return bool_wrapper(this->value || other.value); };
};

struct true_struct {};

template <typename T>
constexpr bool operator ==(const T&, const true_struct&)
{ return true; }

struct false_struct {};

template <typename T>
constexpr bool operator ==(const T&, const false_struct&)
{ return false; }

struct throw_struct {};

template <typename T>
constexpr bool operator ==(const T&, const throw_struct&)
{ throw std::exception(); }
