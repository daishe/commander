//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/type_list.hpp>

#include <boost/test/unit_test.hpp>

#include <tuple>

BOOST_AUTO_TEST_CASE( rebase )
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
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<>,                                                           std::tuple>::type, std::tuple<>                                                          >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01>,                                                        std::tuple>::type, std::tuple<t01>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02>,                                                   std::tuple>::type, std::tuple<t01, t02>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03>,                                              std::tuple>::type, std::tuple<t01, t02, t03>                                             >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04>,                                         std::tuple>::type, std::tuple<t01, t02, t03, t04>                                        >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05>,                                    std::tuple>::type, std::tuple<t01, t02, t03, t04, t05>                                   >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06>,                               std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06>                              >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07>                         >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>                    >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, std::tuple>::type, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>                    >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07, t06>                         >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08, t07>,                               std::tuple>::type, std::tuple<t12, t11, t10, t09, t08, t07>                              >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09, t08>,                                    std::tuple>::type, std::tuple<t12, t11, t10, t09, t08>                                   >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10, t09>,                                         std::tuple>::type, std::tuple<t12, t11, t10, t09>                                        >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11, t10>,                                              std::tuple>::type, std::tuple<t12, t11, t10>                                             >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12, t11>,                                                   std::tuple>::type, std::tuple<t12, t11>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<t12>,                                                        std::tuple>::type, std::tuple<t12>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase<com::type_list<>,                                                           std::tuple>::type, std::tuple<>                                                          >);
    }

    {
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<>,                                                           com::type_list>::type, com::type_list<>                                                          >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01>,                                                        com::type_list>::type, com::type_list<t01>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02>,                                                   com::type_list>::type, com::type_list<t01, t02>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03>,                                              com::type_list>::type, com::type_list<t01, t02, t03>                                             >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04>,                                         com::type_list>::type, com::type_list<t01, t02, t03, t04>                                        >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05>,                                    com::type_list>::type, com::type_list<t01, t02, t03, t04, t05>                                   >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06>,                               com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06>                              >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07>,                          com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07>                         >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>,                     com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>                    >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, com::type_list>::type, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>,                     com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>                    >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07, t06>,                          com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07, t06>                         >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08, t07>,                               com::type_list>::type, com::type_list<t12, t11, t10, t09, t08, t07>                              >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09, t08>,                                    com::type_list>::type, com::type_list<t12, t11, t10, t09, t08>                                   >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10, t09>,                                         com::type_list>::type, com::type_list<t12, t11, t10, t09>                                        >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11, t10>,                                              com::type_list>::type, com::type_list<t12, t11, t10>                                             >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12, t11>,                                                   com::type_list>::type, com::type_list<t12, t11>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<t12>,                                                        com::type_list>::type, com::type_list<t12>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase<std::tuple<>,                                                           com::type_list>::type, com::type_list<>                                                          >);
    }
}

BOOST_AUTO_TEST_CASE( rebase_t )
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
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<>,                                                           std::tuple>, std::tuple<>                                                          >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01>,                                                        std::tuple>, std::tuple<t01>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02>,                                                   std::tuple>, std::tuple<t01, t02>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03>,                                              std::tuple>, std::tuple<t01, t02, t03>                                             >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04>,                                         std::tuple>, std::tuple<t01, t02, t03, t04>                                        >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05>,                                    std::tuple>, std::tuple<t01, t02, t03, t04, t05>                                   >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06>,                               std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06>                              >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07>,                          std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07>                         >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>,                     std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>                    >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, std::tuple>, std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>,                     std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>                    >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07, t06>,                          std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07, t06>                         >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08, t07>,                               std::tuple>, std::tuple<t12, t11, t10, t09, t08, t07>                              >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09, t08>,                                    std::tuple>, std::tuple<t12, t11, t10, t09, t08>                                   >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10, t09>,                                         std::tuple>, std::tuple<t12, t11, t10, t09>                                        >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11, t10>,                                              std::tuple>, std::tuple<t12, t11, t10>                                             >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12, t11>,                                                   std::tuple>, std::tuple<t12, t11>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<t12>,                                                        std::tuple>, std::tuple<t12>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase_t<com::type_list<>,                                                           std::tuple>, std::tuple<>                                                          >);
    }

    {
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<>,                                                           com::type_list>, com::type_list<>                                                          >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01>,                                                        com::type_list>, com::type_list<t01>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02>,                                                   com::type_list>, com::type_list<t01, t02>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03>,                                              com::type_list>, com::type_list<t01, t02, t03>                                             >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04>,                                         com::type_list>, com::type_list<t01, t02, t03, t04>                                        >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05>,                                    com::type_list>, com::type_list<t01, t02, t03, t04, t05>                                   >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06>,                               com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06>                              >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07>,                          com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07>                         >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08>,                     com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>                    >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09>,                com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09>               >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>,           com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10>          >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>,      com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11>     >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>, com::type_list>, com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, t12>>);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>, com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02, t01>>);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>,      com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03, t02>     >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>,           com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04, t03>          >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05, t04>,                com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05, t04>               >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06, t05>,                     com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06, t05>                    >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07, t06>,                          com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07, t06>                         >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08, t07>,                               com::type_list>, com::type_list<t12, t11, t10, t09, t08, t07>                              >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09, t08>,                                    com::type_list>, com::type_list<t12, t11, t10, t09, t08>                                   >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10, t09>,                                         com::type_list>, com::type_list<t12, t11, t10, t09>                                        >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11, t10>,                                              com::type_list>, com::type_list<t12, t11, t10>                                             >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12, t11>,                                                   com::type_list>, com::type_list<t12, t11>                                                  >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<t12>,                                                        com::type_list>, com::type_list<t12>                                                       >);
        static_assert(std::is_same_v<com::tl::rebase_t<std::tuple<>,                                                           com::type_list>, com::type_list<>                                                          >);
    }
}
