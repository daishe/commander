//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_value_size )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0);          }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1);          }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1);          }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1);          }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1);          }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 3); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 4); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 4); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 5); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 3); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 3); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == str.size()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 0); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_size(str) == 1); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_value_size_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1);          }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1);          }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1);          }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1);          }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 5); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_size<size_t>(str.cbegin(), str.cend()) == 1); }(sv("- abc =v"));
    }
}
