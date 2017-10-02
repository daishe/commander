//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( is_parse_stop )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("-"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == true);  }(sv("--"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("---"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("--="));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("--=a"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("-- "));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv(" --"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("--a"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("a--"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str) == false); }(sv("  "));
}

BOOST_AUTO_TEST_CASE( is_parse_stop_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("-"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == true);  }(sv("--"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("---"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("--="));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("--=a"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("-- "));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv(" --"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("--a"));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("a--"));

    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_parse_stop(str.cbegin(), str.cend()) == false); }(sv("  "));
}
