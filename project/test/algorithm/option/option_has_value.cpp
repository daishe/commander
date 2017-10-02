//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_has_value )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true);  }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == false); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str) == true); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_has_value_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true);  }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == false); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_has_value(str.cbegin(), str.cend()) == true); }(sv("- abc =v"));
    }
}
