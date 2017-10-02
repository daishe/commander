//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string_view>

BOOST_AUTO_TEST_CASE( string_literal_to_view )
{
    namespace com = commander;
    using sv = std::string_view;

    {
        {
            auto view = com::string_literal_to_view<sv>("");
            BOOST_CHECK(view.size() == 0); BOOST_CHECK(view == "");
        }

        {
            auto view = com::string_literal_to_view<sv>(" ");
            BOOST_CHECK(view.size() == 1); BOOST_CHECK(view == " ");
        }

        {
            auto view = com::string_literal_to_view<sv>("  ");
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view == "  ");
        }

        {
            auto view = com::string_literal_to_view<sv>("\0");
            BOOST_CHECK(view.size() == 1); BOOST_CHECK(view[0] == '\0');
        }

        {
            auto view = com::string_literal_to_view<sv>("\0\0");
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view[0] == '\0' && view[1] == '\0');
        }
    }

    {
        {
            char literal[1] = {'\0'};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 0); BOOST_CHECK(view == "");
        }

        {
            char literal[2] = {' ', '\0'};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 1); BOOST_CHECK(view == " ");
        }

        {
            char literal[3] = {' ', ' ', '\0'};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view == "  ");
        }

        {
            char literal[2] = {'\0', '\0'};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 1); BOOST_CHECK(view[0] == '\0');
        }

        {
            char literal[3] = {'\0', '\0', '\0'};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view[0] == '\0' && view[1] == '\0');
        }
    }

    {
        {
            char literal[1] = {' '};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 1); BOOST_CHECK(view == " ");
        }

        {
            char literal[2] = {' ', ' '};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view == "  ");
        }

        {
            char literal[3] = {' ', ' ', ' '};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 3); BOOST_CHECK(view == "   ");
        }

        {
            char literal[2] = {'\0', ' '};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 2); BOOST_CHECK(view[0] == '\0' && view[1] == ' ');
        }

        {
            char literal[3] = {'\0', '\0', ' '};
            auto view = com::string_literal_to_view<sv>(literal);
            BOOST_CHECK(view.size() == 3); BOOST_CHECK(view[0] == '\0' && view[1] == '\0' && view[2] == ' ');
        }
    }
}
