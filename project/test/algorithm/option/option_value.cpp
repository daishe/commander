//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_value )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_value(str) == "-");  }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");   }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "--"); }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");   }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");   }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");   }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "-=");  }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "--="); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "-=v");  }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v");    }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "--=v"); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v");    }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v");    }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v");    }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "");     }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");     }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "val");  }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "val "); }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "");      }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");      }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " ");     }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " val");  }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " val "); }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "val"); }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "");    }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "val"); }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == " -");        }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " -abc");     }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " -abc=");    }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " -abc=val"); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == " --");        }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " --abc");     }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " --abc=");    }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == " --abc=val"); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "");   }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "  "); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_value(str) == ""); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_value(str) == "v"); }(sv("- abc =v"));
    }
}
