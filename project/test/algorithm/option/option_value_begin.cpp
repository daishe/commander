//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_value_begin )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());   }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());   }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());   }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());   }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin());               }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin());               }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin());               }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin());               }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());                 }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());                 }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 8)); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 8)); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 8)); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 8)); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());                 }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end());                 }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.begin()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 3)); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 4)); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == str.end()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 7)); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 5)); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 6)); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str) == std::next(str.begin(), 7)); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_value_begin_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());   }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());   }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());   }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());   }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin());               }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin());               }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin());               }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin());               }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());                 }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());                 }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 8)); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 8)); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 8)); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 8)); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());                 }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end());                 }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 3)); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 4)); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == str.end()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 7)); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 5)); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 6)); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_begin(str.cbegin(), str.cend()) == std::next(str.begin(), 7)); }(sv("- abc =v"));
    }
}
