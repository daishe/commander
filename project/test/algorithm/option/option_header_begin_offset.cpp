//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_header_begin_offset )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset(str) == 0); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_header_begin_offset_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_begin_offset<size_t>(str.cbegin(), str.cend()) == 0); }(sv("- abc =v"));
    }
}
