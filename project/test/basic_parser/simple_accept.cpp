//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/parser.hpp>

#include <boost/test/unit_test.hpp>

#include "helpers.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <vector>

BOOST_AUTO_TEST_CASE( simple_accept )
{
    namespace com = commander;
    using sv = std::string_view;

    std::vector<std::tuple<std::string, std::string, std::string>> res;

    auto callback = [&res](sv argument, sv header, auto value) -> bool {
        if constexpr (com::is_placeholder_v<decltype(value)>)
            res.emplace_back(argument, header, "placeholder_t");
        else if constexpr (com::is_no_value_v<decltype(value)>)
            res.emplace_back(argument, header, "no_value_t");
        else
            res.emplace_back(argument, header, value);
        return true;
    };

    commander::basic_parser<std::string_view, std::string> parser;

    {
        res.clear();

        auto parser_res_0 = parser("", callback);
        auto parser_res_1 = parser("", parser_res_0);
        static_assert(std::is_same_v<decltype(callback), decltype(parser_res_0)>);
        static_assert(std::is_same_v<decltype(callback), decltype(parser_res_1)>);
        BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
        CHECK_TUPLE_3(res.at(0), "--", "--", "");
        CHECK_TUPLE_3(res.at(1), "--", "--", "");
    }

    {
        {
            {
                res.clear();

                parser("-a", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a", "-a", "placeholder_t");
            }

            {
                res.clear();

                parser("-ab", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab", "-b", "placeholder_t");
            }

            {
                res.clear();

                parser("-abc", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc", "-c", "placeholder_t");
            }
        }

        {

            {
                res.clear();

                parser("-a=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a=", "-a", "");
            }

            {
                res.clear();

                parser("-ab=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab=", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab=", "-b", "");
            }

            {
                res.clear();

                parser("-abc=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc=", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc=", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc=", "-c", "");
            }
        }

        {

            {
                res.clear();

                parser("-a=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a=val", "-a", "val");
            }

            {
                res.clear();

                parser("-ab=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab=val", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab=val", "-b", "val");
            }

            {
                res.clear();

                parser("-abc=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc=val", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc=val", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc=val", "-c", "val");
            }
        }
    }

    {
        {

            {
                res.clear();

                parser("--a", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a", "--a", "placeholder_t");
            }

            {
                res.clear();

                parser("--ab", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab", "--ab", "placeholder_t");
            }

            {
                res.clear();

                parser("--abc", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc", "--abc", "placeholder_t");
            }
        }

        {

            {
                res.clear();

                parser("--a=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a=", "--a", "");
            }

            {
                res.clear();

                parser("--ab=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab=", "--ab", "");
            }

            {
                res.clear();

                parser("--abc=", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc=", "--abc", "");
            }
        }

        {

            {
                res.clear();

                parser("--a=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a=val", "--a", "val");
            }

            {
                res.clear();

                parser("--ab=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab=val", "--ab", "val");
            }

            {
                res.clear();

                parser("--abc=val", callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc=val", "--abc", "val");
            }
        }
    }
}