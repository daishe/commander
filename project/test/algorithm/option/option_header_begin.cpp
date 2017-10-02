//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_header_begin )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str) == str.begin()); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_header_begin_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin(str.cbegin(), str.cend()) == str.begin()); }(sv("- abc =v"));
    }
}
