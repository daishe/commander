//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_header )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--a");  }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---");  }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---a"); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--a");  }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---");  }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---a"); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "");     }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--a");  }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---");  }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "---a"); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "--abc"); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--abc"); }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--abc"); }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "--abc"); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- abc "); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- abc "); }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- abc "); }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- abc "); }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- abc "); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- "); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- "); }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- "); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- "); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- "); }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-- "); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header(str) == ""); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-ab");  }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-abc"); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-ab");  }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-abc"); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "-a");   }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-ab");  }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "-abc"); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a");   }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab");  }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc"); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a");   }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab");  }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc"); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a");   }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab");  }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc"); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a ");   }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab ");  }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc "); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a ");   }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab ");  }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc "); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header(str) == "- a ");   }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- ab ");  }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header(str) == "- abc "); }(sv("- abc =v"));
    }
}
