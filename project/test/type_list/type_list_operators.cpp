//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/type_list.hpp>

#include <boost/test/unit_test.hpp>

#include <utility>

BOOST_AUTO_TEST_CASE( type_list_operator_eq )
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

    {
        static_assert((com::type_list<>()                                      ) == (com::type_list<>()                                      ));
        static_assert((com::type_list<t01>()                                   ) == (com::type_list<t01>()                                   ));
        static_assert((com::type_list<t01, t02>()                              ) == (com::type_list<t01, t02>()                              ));
        static_assert((com::type_list<t01, t02, t03>()                         ) == (com::type_list<t01, t02, t03>()                         ));
        static_assert((com::type_list<t01, t02, t03, t04>()                    ) == (com::type_list<t01, t02, t03, t04>()                    ));
        static_assert((com::type_list<t01, t02, t03, t04, t05>()               ) == (com::type_list<t01, t02, t03, t04, t05>()               ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06>()          ) == (com::type_list<t01, t02, t03, t04, t05, t06>()          ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ) == (com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()) == (com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()) == (com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ) == (com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03>()          ) == (com::type_list<t08, t07, t06, t05, t04, t03>()          ));
        static_assert((com::type_list<t08, t07, t06, t05, t04>()               ) == (com::type_list<t08, t07, t06, t05, t04>()               ));
        static_assert((com::type_list<t08, t07, t06, t05>()                    ) == (com::type_list<t08, t07, t06, t05>()                    ));
        static_assert((com::type_list<t08, t07, t06>()                         ) == (com::type_list<t08, t07, t06>()                         ));
        static_assert((com::type_list<t08, t07>()                              ) == (com::type_list<t08, t07>()                              ));
        static_assert((com::type_list<t08>()                                   ) == (com::type_list<t08>()                                   ));
        static_assert((com::type_list<>()                                      ) == (com::type_list<>()                                      ));
    }

    {
        static_assert((com::type_list<t01>()                                   ) == (com::type_list<t01, t01>()                                                                      ));
        static_assert((com::type_list<t01, t02>()                              ) == (com::type_list<t01, t02, t01, t02>()                                                            ));
        static_assert((com::type_list<t01, t02, t03>()                         ) == (com::type_list<t01, t02, t03, t01, t02, t03>()                                                  ));
        static_assert((com::type_list<t01, t02, t03, t04>()                    ) == (com::type_list<t01, t02, t03, t04, t01, t02, t03, t04>()                                        ));
        static_assert((com::type_list<t01, t02, t03, t04, t05>()               ) == (com::type_list<t01, t02, t03, t04, t05, t01, t02, t03, t04, t05>()                              ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06>()          ) == (com::type_list<t01, t02, t03, t04, t05, t06, t01, t02, t03, t04, t05, t06>()                    ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ) == (com::type_list<t01, t02, t03, t04, t05, t06, t07, t01, t02, t03, t04, t05, t06, t07>()          ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()) == (com::type_list<t01, t02, t03, t04, t05, t06, t07, t08, t01, t02, t03, t04, t05, t06, t07, t08>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()) == (com::type_list<t08, t07, t06, t05, t04, t03, t02, t01, t08, t07, t06, t05, t04, t03, t02, t01>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ) == (com::type_list<t08, t07, t06, t05, t04, t03, t02, t08, t07, t06, t05, t04, t03, t02>()          ));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03>()          ) == (com::type_list<t08, t07, t06, t05, t04, t03, t08, t07, t06, t05, t04, t03>()                    ));
        static_assert((com::type_list<t08, t07, t06, t05, t04>()               ) == (com::type_list<t08, t07, t06, t05, t04, t08, t07, t06, t05, t04>()                              ));
        static_assert((com::type_list<t08, t07, t06, t05>()                    ) == (com::type_list<t08, t07, t06, t05, t08, t07, t06, t05>()                                        ));
        static_assert((com::type_list<t08, t07, t06>()                         ) == (com::type_list<t08, t07, t06, t08, t07, t06>()                                                  ));
        static_assert((com::type_list<t08, t07>()                              ) == (com::type_list<t08, t07, t08, t07>()                                                            ));
        static_assert((com::type_list<t08>()                                   ) == (com::type_list<t08, t08>()                                                                      ));
    }
}

BOOST_AUTO_TEST_CASE( type_list_operator_neq )
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

    {
        static_assert(!((com::type_list<>()                                      ) != (com::type_list<>()                                      )));
        static_assert(!((com::type_list<t01>()                                   ) != (com::type_list<t01>()                                   )));
        static_assert(!((com::type_list<t01, t02>()                              ) != (com::type_list<t01, t02>()                              )));
        static_assert(!((com::type_list<t01, t02, t03>()                         ) != (com::type_list<t01, t02, t03>()                         )));
        static_assert(!((com::type_list<t01, t02, t03, t04>()                    ) != (com::type_list<t01, t02, t03, t04>()                    )));
        static_assert(!((com::type_list<t01, t02, t03, t04, t05>()               ) != (com::type_list<t01, t02, t03, t04, t05>()               )));
        static_assert(!((com::type_list<t01, t02, t03, t04, t05, t06>()          ) != (com::type_list<t01, t02, t03, t04, t05, t06>()          )));
        static_assert(!((com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ) != (com::type_list<t01, t02, t03, t04, t05, t06, t07>()     )));
        static_assert(!((com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()) != (com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>())));
        static_assert(!((com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()) != (com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>())));
        static_assert(!((com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ) != (com::type_list<t08, t07, t06, t05, t04, t03, t02>()     )));
        static_assert(!((com::type_list<t08, t07, t06, t05, t04, t03>()          ) != (com::type_list<t08, t07, t06, t05, t04, t03>()          )));
        static_assert(!((com::type_list<t08, t07, t06, t05, t04>()               ) != (com::type_list<t08, t07, t06, t05, t04>()               )));
        static_assert(!((com::type_list<t08, t07, t06, t05>()                    ) != (com::type_list<t08, t07, t06, t05>()                    )));
        static_assert(!((com::type_list<t08, t07, t06>()                         ) != (com::type_list<t08, t07, t06>()                         )));
        static_assert(!((com::type_list<t08, t07>()                              ) != (com::type_list<t08, t07>()                              )));
        static_assert(!((com::type_list<t08>()                                   ) != (com::type_list<t08>()                                   )));
        static_assert(!((com::type_list<>()                                      ) != (com::type_list<>()                                      )));
    }

    {
        static_assert((com::type_list<t01>()                                   ) != (com::type_list<>()                                 ));
        static_assert((com::type_list<t01, t02>()                              ) != (com::type_list<t01>()                              ));
        static_assert((com::type_list<t01, t02, t03>()                         ) != (com::type_list<t01, t02>()                         ));
        static_assert((com::type_list<t01, t02, t03, t04>()                    ) != (com::type_list<t01, t02, t03>()                    ));
        static_assert((com::type_list<t01, t02, t03, t04, t05>()               ) != (com::type_list<t01, t02, t03, t04>()               ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06>()          ) != (com::type_list<t01, t02, t03, t04, t05>()          ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ) != (com::type_list<t01, t02, t03, t04, t05, t06>()     ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()) != (com::type_list<t01, t02, t03, t04, t05, t06, t07>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()) != (com::type_list<t08, t07, t06, t05, t04, t03, t02>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ) != (com::type_list<t08, t07, t06, t05, t04, t03>()     ));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03>()          ) != (com::type_list<t08, t07, t06, t05, t04>()          ));
        static_assert((com::type_list<t08, t07, t06, t05, t04>()               ) != (com::type_list<t08, t07, t06, t05>()               ));
        static_assert((com::type_list<t08, t07, t06, t05>()                    ) != (com::type_list<t08, t07, t06>()                    ));
        static_assert((com::type_list<t08, t07, t06>()                         ) != (com::type_list<t08, t07>()                         ));
        static_assert((com::type_list<t08, t07>()                              ) != (com::type_list<t08>()                              ));
        static_assert((com::type_list<t08>()                                   ) != (com::type_list<>()                                 ));
    }

    {
        static_assert((com::type_list<t01>()                                   ) != (com::type_list<>()                                                                    ));
        static_assert((com::type_list<t01, t02>()                              ) != (com::type_list<t01, t01>()                                                            ));
        static_assert((com::type_list<t01, t02, t03>()                         ) != (com::type_list<t01, t02, t01, t02>()                                                  ));
        static_assert((com::type_list<t01, t02, t03, t04>()                    ) != (com::type_list<t01, t02, t03, t01, t02, t03>()                                        ));
        static_assert((com::type_list<t01, t02, t03, t04, t05>()               ) != (com::type_list<t01, t02, t03, t04, t01, t02, t03, t04>()                              ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06>()          ) != (com::type_list<t01, t02, t03, t04, t05, t01, t02, t03, t04, t05>()                    ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07>()     ) != (com::type_list<t01, t02, t03, t04, t05, t06, t01, t02, t03, t04, t05, t06>()          ));
        static_assert((com::type_list<t01, t02, t03, t04, t05, t06, t07, t08>()) != (com::type_list<t01, t02, t03, t04, t05, t06, t07, t01, t02, t03, t04, t05, t06, t07>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02, t01>()) != (com::type_list<t08, t07, t06, t05, t04, t03, t02, t08, t07, t06, t05, t04, t03, t02>()));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03, t02>()     ) != (com::type_list<t08, t07, t06, t05, t04, t03, t08, t07, t06, t05, t04, t03>()          ));
        static_assert((com::type_list<t08, t07, t06, t05, t04, t03>()          ) != (com::type_list<t08, t07, t06, t05, t04, t08, t07, t06, t05, t04>()                    ));
        static_assert((com::type_list<t08, t07, t06, t05, t04>()               ) != (com::type_list<t08, t07, t06, t05, t08, t07, t06, t05>()                              ));
        static_assert((com::type_list<t08, t07, t06, t05>()                    ) != (com::type_list<t08, t07, t06, t08, t07, t06>()                                        ));
        static_assert((com::type_list<t08, t07, t06>()                         ) != (com::type_list<t08, t07, t08, t07>()                                                  ));
        static_assert((com::type_list<t08, t07>()                              ) != (com::type_list<t08, t08>()                                                            ));
        static_assert((com::type_list<t08>()                                   ) != (com::type_list<>()                                                                    ));
    }
}
