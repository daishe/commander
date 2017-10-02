//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/always_true.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( always_true )
{
    namespace comd = commander::detail;

    static_assert(comd::always_true<>::value);

    static_assert(comd::always_true<int>::value);
    static_assert(comd::always_true<volatile int>::value);
    static_assert(comd::always_true<const int>::value);
    static_assert(comd::always_true<const volatile int>::value);
    static_assert(comd::always_true<int&>::value);
    static_assert(comd::always_true<volatile int&>::value);
    static_assert(comd::always_true<const int&>::value);
    static_assert(comd::always_true<const volatile int&>::value);
    static_assert(comd::always_true<int&&>::value);
    static_assert(comd::always_true<volatile int&&>::value);
    static_assert(comd::always_true<const int&&>::value);
    static_assert(comd::always_true<const volatile int&&>::value);

    static_assert(comd::always_true<float, double, long double>::value);
}

BOOST_AUTO_TEST_CASE( always_true_v )
{
    namespace comd = commander::detail;

    static_assert(comd::always_true_v<>);

    static_assert(comd::always_true_v<int>);
    static_assert(comd::always_true_v<volatile int>);
    static_assert(comd::always_true_v<const int>);
    static_assert(comd::always_true_v<const volatile int>);
    static_assert(comd::always_true_v<int&>);
    static_assert(comd::always_true_v<volatile int&>);
    static_assert(comd::always_true_v<const int&>);
    static_assert(comd::always_true_v<const volatile int&>);
    static_assert(comd::always_true_v<int&&>);
    static_assert(comd::always_true_v<volatile int&&>);
    static_assert(comd::always_true_v<const int&&>);
    static_assert(comd::always_true_v<const volatile int&&>);

    static_assert(comd::always_true_v<float, double, long double>);
}
