//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/last.hpp>

#include <boost/test/unit_test.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( last )
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

    static_assert(std::is_same_v<comd::last<>::type, void>);
    static_assert(std::is_same_v<comd::last<t01>::type, t01>);
    static_assert(std::is_same_v<comd::last<t01, t02>::type, t02>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03>::type, t03>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04>::type, t04>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05>::type, t05>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06>::type, t06>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07>::type, t07>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08>::type, t08>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09>::type, t09>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>::type, t10>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>::type, t11>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::type, t12>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13>::type, t13>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14>::type, t14>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15>::type, t15>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16>::type, t16>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17>::type, t17>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18>::type, t18>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19>::type, t19>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20>::type, t20>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21>::type, t21>);
    static_assert(std::is_same_v<comd::last<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22>::type, t22>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::type, t01>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>::type, t02>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>::type, t03>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04>::type, t04>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05>::type, t05>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06>::type, t06>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07>::type, t07>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08>::type, t08>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09>::type, t09>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10>::type, t10>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11>::type, t11>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12>::type, t12>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13>::type, t13>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15, t14>::type, t14>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16, t15>::type, t15>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17, t16>::type, t16>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18, t17>::type, t17>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19, t18>::type, t18>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20, t19>::type, t19>);
    static_assert(std::is_same_v<comd::last<t22, t21, t20>::type, t20>);
    static_assert(std::is_same_v<comd::last<t22, t21>::type, t21>);
    static_assert(std::is_same_v<comd::last<t22>::type, t22>);
    static_assert(std::is_same_v<comd::last<>::type, void>);
}

BOOST_AUTO_TEST_CASE( last_t )
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

    static_assert(std::is_same_v<comd::last_t<>, void>);
    static_assert(std::is_same_v<comd::last_t<t01>, t01>);
    static_assert(std::is_same_v<comd::last_t<t01, t02>, t02>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03>, t03>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04>, t04>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05>, t05>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06>, t06>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07>, t07>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08>, t08>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09>, t09>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>, t10>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>, t11>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t12>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13>, t13>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14>, t14>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15>, t15>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16>, t16>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17>, t17>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18>, t18>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19>, t19>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20>, t20>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21>, t21>);
    static_assert(std::is_same_v<comd::last_t<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22>, t22>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t01>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>, t02>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>, t03>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05, t04>, t04>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06, t05>, t05>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07, t06>, t06>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08, t07>, t07>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09, t08>, t08>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t09>, t09>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10>, t10>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11>, t11>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12>, t12>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14, t13>, t13>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15, t14>, t14>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16, t15>, t15>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17, t16>, t16>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18, t17>, t17>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19, t18>, t18>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20, t19>, t19>);
    static_assert(std::is_same_v<comd::last_t<t22, t21, t20>, t20>);
    static_assert(std::is_same_v<comd::last_t<t22, t21>, t21>);
    static_assert(std::is_same_v<comd::last_t<t22>, t22>);
    static_assert(std::is_same_v<comd::last_t<>, void>);
}
