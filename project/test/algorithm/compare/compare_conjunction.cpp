//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include "compare_helpers.hpp"

#include <exception>
#include <type_traits>

BOOST_AUTO_TEST_CASE( compare_conjunction )
{
    namespace com = commander;

    {
        [](auto r) { static_assert(std::is_same_v<non_comparable, decltype(r)>); }(com::compare_conjunction(non_comparable()));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(false, false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(false, false, false));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(true,  true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  false, false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, false, true,  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, false, true,  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, false, false, true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(false, false, false, false));
    }

    {
        [](auto r) { static_assert(std::is_same_v<short, decltype(r)>); BOOST_CHECK(r == short(1)); }(com::compare_conjunction(short(1)));
        [](auto r) { static_assert(std::is_same_v<short, decltype(r)>); BOOST_CHECK(r == short(0)); }(com::compare_conjunction(short(0)));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(short(1), long(1)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(0)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(1)));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(short(0), long(0)));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(short(1), long(1), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(1), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(1), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(1), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(0), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(0), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(0), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(1), long(0), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(1), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(1), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(1), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(1), false_struct(), false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(0), true_struct(),  true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == true);  }(com::compare_conjunction(short(0), long(0), true_struct(),  false));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(0), false_struct(), true));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(short(0), long(0), false_struct(), false));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_conjunction(bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0)));

        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(0)));

        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(1), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(1), bool_wrapper(0), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(1), bool_wrapper(0), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(1), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(1), bool_wrapper(0)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == false); }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(0), bool_wrapper(1)));
        [](auto r) { static_assert(std::is_same_v<bool_wrapper, decltype(r)>); BOOST_CHECK(r.value == true);  }(com::compare_conjunction(bool_wrapper(0), bool_wrapper(0), bool_wrapper(0), bool_wrapper(0)));
    }

    {
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  throw_struct()));

        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  false, throw_struct(), throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(true,  true,  false,          throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, false, true,           throw_struct()));
        [](auto r) { static_assert(std::is_same_v<bool, decltype(r)>); BOOST_CHECK(r == false); }(com::compare_conjunction(false, true,  throw_struct(), throw_struct()));
    }
}
