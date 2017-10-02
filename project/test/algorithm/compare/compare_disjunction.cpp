//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include "compare_helpers.hpp"

#include <exception>
#include <type_traits>

BOOST_AUTO_TEST_CASE( compare_disjunction )
{
    namespace com = commander;

    {
        [](auto r) { static_assert(std::is_same_v<non_comparable, decltype(r)>); }(com::compare_disjunction(non_comparable()));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(true,  false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(true,  false, false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(false, true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(false, false, false, false));
    }

    {
        [](auto r) { static_assert(std::is_same_v<short, decltype(r)>); BOOST_CHECK(r == short(1)); }(com::compare_disjunction(short(1)));
        [](auto r) { static_assert(std::is_same_v<short, decltype(r)>); BOOST_CHECK(r == short(0)); }(com::compare_disjunction(short(0)));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(1)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(short(1), long(0)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(short(0), long(1)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(0)));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(1), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(1), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(1), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(1), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(0), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(0), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(1), long(0), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(short(1), long(0), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(1), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(1), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_disjunction(short(0), long(1), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(1), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(0), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(0), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(0), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_disjunction(short(0), long(0), false_struct(), false));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_disjunction(bool_wrapper(0)));

        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(0)));

        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_disjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_disjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(0), bool_wrapper(0)));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(true,  true,  throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(false, false, throw_struct()));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(true,  true,  throw_struct(), throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(true,  false, true,           throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(false, true,  false,          throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true); }(com::compare_disjunction(false, false, throw_struct(), throw_struct()));
    }
}
