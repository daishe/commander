//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( is_boolean )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_boolean(str) == true); }(sv("true"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == true); }(sv("TRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == true); }(sv("false"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == true); }(sv("FALSE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("ttrue"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("TTRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("trrue"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("TRRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("truee"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("TRUEE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("ffalse"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("FFALSE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("fallse"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("FALLSE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("falsee"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("FALSEE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_boolean(str) == false); }(sv("  "));
}

BOOST_AUTO_TEST_CASE( is_boolean_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == true); }(sv("true"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == true); }(sv("TRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == true); }(sv("false"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == true); }(sv("FALSE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("ttrue"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("TTRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("trrue"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("TRRUE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("truee"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("TRUEE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("ffalse"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("FFALSE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("fallse"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("FALLSE"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("falsee"));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("FALSEE"));

    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_boolean(str.cbegin(), str.cend()) == false); }(sv("  "));
}
