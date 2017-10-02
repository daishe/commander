//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/type_list.hpp>

#include <boost/test/unit_test.hpp>

#include <tuple>

BOOST_AUTO_TEST_CASE( empty )
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
        static_assert(com::tl::empty<com::type_list<>                                                          >::value == true);
        static_assert(com::tl::empty<com::type_list<t01>                                                       >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02>                                                  >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03>                                             >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04>                                        >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05>                                   >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06>                              >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07>                         >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>                    >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >::value == false);
        static_assert(com::tl::empty<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>                    >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07, t06>                         >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08, t07>                              >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09, t08>                                   >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10, t09>                                        >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11, t10>                                             >::value == false);
        static_assert(com::tl::empty<com::type_list<t12, t11>                                                  >::value == false);
        static_assert(com::tl::empty<com::type_list<t12>                                                       >::value == false);
        static_assert(com::tl::empty<com::type_list<>                                                          >::value == true);
    }

    {
        static_assert(com::tl::empty<std::tuple<>                                                          >::value == true);
        static_assert(com::tl::empty<std::tuple<t01>                                                       >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02>                                                  >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03>                                             >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04>                                        >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05>                                   >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06>                              >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07>                         >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>                    >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >::value == false);
        static_assert(com::tl::empty<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>                    >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07, t06>                         >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08, t07>                              >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09, t08>                                   >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10, t09>                                        >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11, t10>                                             >::value == false);
        static_assert(com::tl::empty<std::tuple<t12, t11>                                                  >::value == false);
        static_assert(com::tl::empty<std::tuple<t12>                                                       >::value == false);
        static_assert(com::tl::empty<std::tuple<>                                                          >::value == true);
    }
}

BOOST_AUTO_TEST_CASE( empty_v )
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
        static_assert(com::tl::empty_v<com::type_list<>                                                          > == true);
        static_assert(com::tl::empty_v<com::type_list<t01>                                                       > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02>                                                  > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03>                                             > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04>                                        > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05>                                   > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06>                              > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07>                         > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>                    > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>               > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     > == false);
        static_assert(com::tl::empty_v<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>> == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>> == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>               > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>                    > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07, t06>                         > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08, t07>                              > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09, t08>                                   > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10, t09>                                        > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11, t10>                                             > == false);
        static_assert(com::tl::empty_v<com::type_list<t12, t11>                                                  > == false);
        static_assert(com::tl::empty_v<com::type_list<t12>                                                       > == false);
        static_assert(com::tl::empty_v<com::type_list<>                                                          > == true);
    }

    {
        static_assert(com::tl::empty_v<std::tuple<>                                                          > == true);
        static_assert(com::tl::empty_v<std::tuple<t01>                                                       > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02>                                                  > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03>                                             > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04>                                        > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05>                                   > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06>                              > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07>                         > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>                    > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>               > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     > == false);
        static_assert(com::tl::empty_v<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>> == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>> == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>               > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>                    > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07, t06>                         > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08, t07>                              > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09, t08>                                   > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10, t09>                                        > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11, t10>                                             > == false);
        static_assert(com::tl::empty_v<std::tuple<t12, t11>                                                  > == false);
        static_assert(com::tl::empty_v<std::tuple<t12>                                                       > == false);
        static_assert(com::tl::empty_v<std::tuple<>                                                          > == true);
    }
}
