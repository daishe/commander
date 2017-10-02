//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/index_of.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( index_of )
{
    namespace comd = commander::detail;

    struct t01 {};
    struct t02 {};
    using  t03 = const t01;
    using  t04 = const t02;
    using  t05 = volatile t01;
    using  t06 = volatile t02;
    using  t07 = const volatile t01;
    using  t08 = const volatile t02;
    using  t09 = int8_t;
    using  t10 = uint8_t;
    using  t11 = const t09;
    using  t12 = const t10;

    {
        static_assert(comd::index_of<t01                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t01, t01                                                       >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02                                                  >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03                                             >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04                                        >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05                                   >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06                              >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 0));
        static_assert(comd::index_of<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 0));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t(11));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t01, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t01                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t02                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t02, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t02, t01, t02                                                  >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03                                             >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04                                        >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05                                   >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06                              >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 1));
        static_assert(comd::index_of<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t(10));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t(10));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t02, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t02                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t03                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t03, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t03, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t03, t01, t02, t03                                             >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04                                        >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05                                   >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06                              >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 2));
        static_assert(comd::index_of<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 2));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 9));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 9));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 9));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t03, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t03                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t04                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t04, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t04, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t04, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t04, t01, t02, t03, t04                                        >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05                                   >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06                              >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 3));
        static_assert(comd::index_of<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 3));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 8));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 8));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 8));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 8));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t04, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t04                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t05                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t05, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t05, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t05, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t05, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05                                   >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06                              >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 4));
        static_assert(comd::index_of<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 4));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 7));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 7));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 7));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 7));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 7));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t05, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t05                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t06                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06                              >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 5));
        static_assert(comd::index_of<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 5));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 6));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08, t07                              >::value == size_t(-1));
        static_assert(comd::index_of<t06, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t06, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t06, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t06, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t06, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t06                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t07                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t( 6));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 6));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 6));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 6));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 6));
        static_assert(comd::index_of<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 6));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08, t07                              >::value == size_t( 5));
        static_assert(comd::index_of<t07, t12, t11, t10, t09, t08                                   >::value == size_t(-1));
        static_assert(comd::index_of<t07, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t07, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t07, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t07, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t07                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t08                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t(-1));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t( 7));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 7));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 7));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 7));
        static_assert(comd::index_of<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 7));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08, t07                              >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09, t08                                   >::value == size_t( 4));
        static_assert(comd::index_of<t08, t12, t11, t10, t09                                        >::value == size_t(-1));
        static_assert(comd::index_of<t08, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t08, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t08, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t08                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t09                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t(-1));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t( 8));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 8));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 8));
        static_assert(comd::index_of<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 8));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08, t07                              >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09, t08                                   >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10, t09                                        >::value == size_t( 3));
        static_assert(comd::index_of<t09, t12, t11, t10                                             >::value == size_t(-1));
        static_assert(comd::index_of<t09, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t09, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t09                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t10                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t(-1));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t( 9));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t( 9));
        static_assert(comd::index_of<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t( 9));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08, t07                              >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09, t08                                   >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10, t09                                        >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11, t10                                             >::value == size_t( 2));
        static_assert(comd::index_of<t10, t12, t11                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t10, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t10                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t11                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t(-1));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t(10));
        static_assert(comd::index_of<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t(10));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08, t07                              >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09, t08                                   >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10, t09                                        >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11, t10                                             >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12, t11                                                  >::value == size_t( 1));
        static_assert(comd::index_of<t11, t12                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t11                                                            >::value == size_t(-1));
    }

    {
        static_assert(comd::index_of<t12                                                            >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01                                                       >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02                                                  >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03                                             >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04                                        >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05                                   >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06                              >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07                         >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07, t08                    >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09               >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     >::value == size_t(-1));
        static_assert(comd::index_of<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>::value == size_t(11));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04               >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06, t05                    >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07, t06                         >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08, t07                              >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09, t08                                   >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10, t09                                        >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11, t10                                             >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12, t11                                                  >::value == size_t( 0));
        static_assert(comd::index_of<t12, t12                                                       >::value == size_t( 0));
        static_assert(comd::index_of<t12                                                            >::value == size_t(-1));
    }
}

BOOST_AUTO_TEST_CASE( index_of_v )
{
    namespace comd = commander::detail;

    struct t01 {};
    struct t02 {};
    using  t03 = const t01;
    using  t04 = const t02;
    using  t05 = volatile t01;
    using  t06 = volatile t02;
    using  t07 = const volatile t01;
    using  t08 = const volatile t02;
    using  t09 = int8_t;
    using  t10 = uint8_t;
    using  t11 = const t09;
    using  t12 = const t10;

    {
        static_assert(comd::index_of_v<t01                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t01, t01                                                       > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02                                                  > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03                                             > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04                                        > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05                                   > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06                              > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 0));
        static_assert(comd::index_of_v<t01, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 0));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t(11));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07, t06                         > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t01, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t01                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t02                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t02, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t02, t01, t02                                                  > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03                                             > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04                                        > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05                                   > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06                              > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 1));
        static_assert(comd::index_of_v<t02, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t(10));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t(10));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07, t06                         > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t02, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t02                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t03                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t03, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t03, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t03, t01, t02, t03                                             > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04                                        > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05                                   > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06                              > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 2));
        static_assert(comd::index_of_v<t03, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 2));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 9));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 9));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 9));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07, t06                         > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t03, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t03                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t04                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t04, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t04, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t04, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04                                        > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05                                   > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06                              > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 3));
        static_assert(comd::index_of_v<t04, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 3));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 8));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 8));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 8));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 8));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07, t06                         > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t04, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t04                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t05                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t05, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t05, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t05, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05                                   > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06                              > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 4));
        static_assert(comd::index_of_v<t05, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 4));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 7));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 7));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 7));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 7));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 7));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07, t06                         > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t05, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t05                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t06                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06                              > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 5));
        static_assert(comd::index_of_v<t06, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 5));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 6));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08, t07                              > == size_t(-1));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t06, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t06, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t06, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t06, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t06                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t07                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07                         > == size_t( 6));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 6));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 6));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 6));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 6));
        static_assert(comd::index_of_v<t07, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 6));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08, t07                              > == size_t( 5));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09, t08                                   > == size_t(-1));
        static_assert(comd::index_of_v<t07, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t07, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t07, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t07, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t07                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t08                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07                         > == size_t(-1));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t( 7));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 7));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 7));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 7));
        static_assert(comd::index_of_v<t08, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 7));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08, t07                              > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09, t08                                   > == size_t( 4));
        static_assert(comd::index_of_v<t08, t12, t11, t10, t09                                        > == size_t(-1));
        static_assert(comd::index_of_v<t08, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t08, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t08, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t08                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t09                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07                         > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t(-1));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t( 8));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 8));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 8));
        static_assert(comd::index_of_v<t09, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 8));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08, t07                              > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09, t08                                   > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10, t09                                        > == size_t( 3));
        static_assert(comd::index_of_v<t09, t12, t11, t10                                             > == size_t(-1));
        static_assert(comd::index_of_v<t09, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t09, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t09                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t10                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07                         > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t(-1));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t( 9));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t( 9));
        static_assert(comd::index_of_v<t10, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t( 9));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08, t07                              > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09, t08                                   > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10, t09                                        > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11, t10                                             > == size_t( 2));
        static_assert(comd::index_of_v<t10, t12, t11                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t10, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t10                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t11                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07                         > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t(-1));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t(10));
        static_assert(comd::index_of_v<t11, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t(10));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08, t07                              > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09, t08                                   > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10, t09                                        > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11, t10                                             > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12, t11                                                  > == size_t( 1));
        static_assert(comd::index_of_v<t11, t12                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t11                                                            > == size_t(-1));
    }

    {
        static_assert(comd::index_of_v<t12                                                            > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01                                                       > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02                                                  > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03                                             > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04                                        > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05                                   > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06                              > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07                         > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07, t08                    > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09               > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10          > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11     > == size_t(-1));
        static_assert(comd::index_of_v<t12, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12> == size_t(11));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01> == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02     > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04, t03          > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06, t05, t04               > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06, t05                    > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07, t06                         > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08, t07                              > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09, t08                                   > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10, t09                                        > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11, t10                                             > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12, t11                                                  > == size_t( 0));
        static_assert(comd::index_of_v<t12, t12                                                       > == size_t( 0));
        static_assert(comd::index_of_v<t12                                                            > == size_t(-1));
    }
}
