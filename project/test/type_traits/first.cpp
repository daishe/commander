//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/first.hpp>

#include <boost/test/unit_test.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( first )
{
    namespace comd = commander::detail;

    struct t01 {};
    struct t02 {};
    struct t03 {};
    using  t04 = int8_t;
    using  t05 = uint8_t;
    using  t06 = int16_t;
    using  t07 = uint16_t;
    using  t08 = int32_t;
    using  t09 = uint32_t;
    using  t10 = int64_t;
    using  t11 = uint64_t;
    using  t12 = t01;
    using  t13 = t02;
    using  t14 = t03;
    using  t15 = t04;
    using  t16 = t05;
    using  t17 = t06;
    using  t18 = t07;
    using  t19 = t08;
    using  t20 = t09;
    using  t21 = t10;
    using  t22 = t11;

    static_assert(std::is_same_v<comd::first<>::type, void>);
    static_assert(std::is_same_v<comd::first<t01>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21>::type, t01>);
    static_assert(std::is_same_v<comd::first<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22>::type, t01>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15, t14>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16, t15>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17, t16>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18, t17>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19, t18>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20, t19>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21, t20>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22, t21>::type, t22>);
    static_assert(std::is_same_v<comd::first<t22>::type, t22>);
    static_assert(std::is_same_v<comd::first<>::type, void>);
}

BOOST_AUTO_TEST_CASE( first_t )
{
    namespace comd = commander::detail;

    struct t01 {};
    struct t02 {};
    struct t03 {};
    using  t04 = int8_t;
    using  t05 = uint8_t;
    using  t06 = int16_t;
    using  t07 = uint16_t;
    using  t08 = int32_t;
    using  t09 = uint32_t;
    using  t10 = int64_t;
    using  t11 = uint64_t;
    using  t12 = t01;
    using  t13 = t02;
    using  t14 = t03;
    using  t15 = t04;
    using  t16 = t05;
    using  t17 = t06;
    using  t18 = t07;
    using  t19 = t08;
    using  t20 = t09;
    using  t21 = t10;
    using  t22 = t11;

    static_assert(std::is_same_v<comd::first_t<>, void>);
    static_assert(std::is_same_v<comd::first_t<t01>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21>, t01>);
    static_assert(std::is_same_v<comd::first_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22>, t01>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15, t14>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16, t15>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17, t16>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18, t17>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19, t18>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20, t19>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21, t20>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22, t21>, t22>);
    static_assert(std::is_same_v<comd::first_t<t22>, t22>);
    static_assert(std::is_same_v<comd::first_t<>, void>);
}
