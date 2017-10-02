//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_pack_contains )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true);  }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true);  }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true);  }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abc"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abc="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abc=val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abc=val "));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("- abc "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("- abc ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("- abc = "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, ' ') == true);  }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, ' ') == true);  }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("- =val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, ' ') == true);  }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == false); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, '\0') == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, '-')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, ' ')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'b')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'c')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'd')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, '=')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'v')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, '=')  == false); }(sv("- abc=val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'v')  == false); }(sv("- abc=val"));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abaaca"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abaaca="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str, 'a') == true); }(sv("-abaaca=val"));
    }
}

BOOST_AUTO_TEST_CASE( option_pack_contains_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true);  }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true);  }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true);  }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abc"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abc="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abc=val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abc=val "));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("- abc "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("- abc ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("- abc = "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), ' ') == true);  }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), ' ') == true);  }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("- =val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), ' ') == true);  }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == false); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), '\0') == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), '-')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), ' ')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'b')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'c')  == true);  }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'd')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), '=')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'v')  == false); }(sv("- abc = val "));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), '=')  == false); }(sv("- abc=val"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'v')  == false); }(sv("- abc=val"));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abaaca"));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abaaca="));
        [](sv str) { BOOST_CHECK(com::option_pack_contains(str.cbegin(), str.cend(), 'a') == true); }(sv("-abaaca=val"));
    }
}
