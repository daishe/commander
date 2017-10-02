//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/type_list.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( index_of )
{
    namespace com = commander;

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
        static_assert(com::tl::index_of<com::type_list<>,                                                           t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t01>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t01>::value == size_t(11));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t01>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t01>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t02>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t02>::value == size_t(10));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t02>::value == size_t(10));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t02>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t02>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t03>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t03>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t03>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t03>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t03>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t03>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t04>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t04>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t04>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t04>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t04>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t04>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t04>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t05>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t05>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t05>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t05>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t05>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t05>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t05>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t05>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t06>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t06>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t06>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t06>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t07>::value == size_t( 6));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t07>::value == size_t( 5));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t07>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t07>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t08>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t08>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t08>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t08>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t08>::value == size_t( 7));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t08>::value == size_t( 4));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t08>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t08>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t09>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t09>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t09>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t09>::value == size_t( 8));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t09>::value == size_t( 3));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t09>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t09>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t10>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t10>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t10>::value == size_t( 9));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t10>::value == size_t( 2));
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t10>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t10>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t11>::value == size_t(10));
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t11>::value == size_t(10));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t11>::value == size_t( 1));
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t11>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<>,                                                           t11>::value == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of<com::type_list<>,                                                           t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01>,                                                        t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02>,                                                   t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03>,                                              t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04>,                                         t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05>,                                    t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06>,                               t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t12>::value == com::tl::npos);
        static_assert(com::tl::index_of<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t12>::value == size_t(11));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08, t07>,                               t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09, t08>,                                    t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10, t09>,                                         t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11, t10>,                                              t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12, t11>,                                                   t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<t12>,                                                        t12>::value == size_t( 0));
        static_assert(com::tl::index_of<com::type_list<>,                                                           t12>::value == com::tl::npos);
    }
}

BOOST_AUTO_TEST_CASE( index_of_v )
{
    namespace com = commander;

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
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t01> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t01> == size_t(11));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t01> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t01> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t02> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t02> == size_t(10));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t02> == size_t(10));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t02> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t02> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t03> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t03> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t03> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t03> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t03> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t03> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t04> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t04> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t04> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t04> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t04> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t04> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t04> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t05> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t05> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t05> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t05> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t05> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t05> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t05> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t05> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t06> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t06> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t06> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t06> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t07> == size_t( 6));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t07> == size_t( 5));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t07> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t07> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t08> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t08> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t08> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t08> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t08> == size_t( 7));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t08> == size_t( 4));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t08> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t08> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t09> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t09> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t09> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t09> == size_t( 8));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t09> == size_t( 3));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t09> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t09> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t10> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t10> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t10> == size_t( 9));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t10> == size_t( 2));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t10> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t10> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t11> == size_t(10));
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t11> == size_t(10));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t11> == size_t( 1));
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t11> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t11> == com::tl::npos);
    }

    {
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01>,                                                        t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02>,                                                   t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03>,                                              t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04>,                                         t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05>,                                    t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06>,                               t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      t12> == com::tl::npos);
        static_assert(com::tl::index_of_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, t12> == size_t(11));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08, t07>,                               t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09, t08>,                                    t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10, t09>,                                         t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11, t10>,                                              t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12, t11>,                                                   t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<t12>,                                                        t12> == size_t( 0));
        static_assert(com::tl::index_of_v<com::type_list<>,                                                           t12> == com::tl::npos);
    }
}
