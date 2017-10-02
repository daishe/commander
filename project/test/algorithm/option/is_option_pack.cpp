//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( is_option_pack )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("-"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true);  }(sv("-a"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--a"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---a"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("-="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true);  }(sv("-a="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--a="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---a="));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("-=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true);  }(sv("-a=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("--a=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("---a=v"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("-abc"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("-abc="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("-abc=val"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("-abc=val "));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- abc "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- abc ="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- abc = "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- abc = val"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- abc = val "));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- ="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == true); }(sv("- =val"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv(" -"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv(" -abc"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv(" -abc="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv(" -abc=val"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str) == false); }(sv("  "));
}

BOOST_AUTO_TEST_CASE( is_option_pack_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("-"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true);  }(sv("-a"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--a"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---a"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("-="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true);  }(sv("-a="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--a="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---a="));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("-=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true);  }(sv("-a=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("--a=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---=v"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("---a=v"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("-abc"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("-abc="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("-abc=val"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("-abc=val "));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- abc "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- abc ="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- abc = "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- abc = val"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- abc = val "));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- "));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- ="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == true); }(sv("- =val"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv(" -"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv(" -abc"));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv(" -abc="));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv(" -abc=val"));

    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv(""));
    [](sv str) { BOOST_CHECK(com::is_option_pack(str.cbegin(), str.cend()) == false); }(sv("  "));
}
