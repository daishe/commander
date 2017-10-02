//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( option_header_size )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0);          }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0);          }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5);          }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5);          }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5);          }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 7);          }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 7);          }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 7);          }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 7);          }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2);          }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2);          }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3);          }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3);          }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 0); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 2); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 3); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == str.size()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 6); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 4); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 5); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_size(str) == 6); }(sv("- abc =v"));
    }
}

BOOST_AUTO_TEST_CASE( option_header_size_iterator )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("-"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0);          }(sv("--"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--a"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("---a"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("--a="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("---="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("---a="));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("-=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("--=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("--a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("---=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("---a=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("--abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5);          }(sv("--abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5);          }(sv("--abc=val"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5);          }(sv("--abc=val "));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- abc "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 7);          }(sv("-- abc ="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 7);          }(sv("-- abc = "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 7);          }(sv("-- abc = val"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 7);          }(sv("-- abc = val "));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2);          }(sv("- ="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2);          }(sv("- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-- "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3);          }(sv("-- ="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3);          }(sv("-- =val"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" -abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(" --abc=val"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv(""));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 0); }(sv("  "));
    }

    {
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-a"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-ab"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("-abc"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2); }(sv("-a="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("-ab="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("-abc="));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 2); }(sv("-a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("-ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("-abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("- a="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("- ab="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5); }(sv("- abc="));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 3); }(sv("- a=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("- ab=v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5); }(sv("- abc=v"));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- a "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- ab "));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == str.size()); }(sv("- abc "));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("- a ="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5); }(sv("- ab ="));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 6); }(sv("- abc ="));

        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 4); }(sv("- a =v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 5); }(sv("- ab =v"));
        [](sv str) { BOOST_CHECK(com::option_header_size<size_t>(str.cbegin(), str.cend()) == 6); }(sv("- abc =v"));
    }
}
