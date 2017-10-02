//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_value_end )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str) == str.end()); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_value_end_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end(str.cbegin(), str.cend()) == str.end()); }(sv("- abc =v"));
    }
}
