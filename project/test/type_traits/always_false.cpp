//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/always_false.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( always_false )
{
    namespace comd = commander::detail;

    static_assert(!comd::always_false<>::value);

    static_assert(!comd::always_false<int>::value);
    static_assert(!comd::always_false<volatile int>::value);
    static_assert(!comd::always_false<const int>::value);
    static_assert(!comd::always_false<const volatile int>::value);
    static_assert(!comd::always_false<int&>::value);
    static_assert(!comd::always_false<volatile int&>::value);
    static_assert(!comd::always_false<const int&>::value);
    static_assert(!comd::always_false<const volatile int&>::value);
    static_assert(!comd::always_false<int&&>::value);
    static_assert(!comd::always_false<volatile int&&>::value);
    static_assert(!comd::always_false<const int&&>::value);
    static_assert(!comd::always_false<const volatile int&&>::value);

    static_assert(!comd::always_false<float, double, long double>::value);
}

BOOST_AUTO_TEST_CASE( always_false_v )
{
    namespace comd = commander::detail;

    static_assert(!comd::always_false_v<>);

    static_assert(!comd::always_false_v<int>);
    static_assert(!comd::always_false_v<volatile int>);
    static_assert(!comd::always_false_v<const int>);
    static_assert(!comd::always_false_v<const volatile int>);
    static_assert(!comd::always_false_v<int&>);
    static_assert(!comd::always_false_v<volatile int&>);
    static_assert(!comd::always_false_v<const int&>);
    static_assert(!comd::always_false_v<const volatile int&>);
    static_assert(!comd::always_false_v<int&&>);
    static_assert(!comd::always_false_v<volatile int&&>);
    static_assert(!comd::always_false_v<const int&&>);
    static_assert(!comd::always_false_v<const volatile int&&>);

    static_assert(!comd::always_false_v<float, double, long double>);
}
