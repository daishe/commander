//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_value_end_offset )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset(str) == str.size()); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_value_end_offset_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value_end_offset<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc =v"));
    }
}
