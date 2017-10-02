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

BOOST_AUTO_TEST_CASE( value_accept )
{
    namespace com = commander;
    using sv = std::string_view;

    std::vector<std::tuple<std::string, std::string, std::string>> res;

    auto true_callback = [&res](sv argument, sv header, auto value) -> bool {
        if constexpr (com::is_placeholder_v<decltype(value)>)
            res.emplace_back(argument, header, "placeholder_t");
        else if constexpr (com::is_no_value_v<decltype(value)>)
            res.emplace_back(argument, header, "no_value_t");
        else if constexpr (std::is_same_v<decltype(value), int32_t>)
            res.emplace_back(argument, header, std::string("int32_t ") + std::to_string(value));
        else if constexpr (std::is_same_v<decltype(value), uint64_t>)
            res.emplace_back(argument, header, std::string("uint64_t ") + std::to_string(value));
        else
            res.emplace_back(argument, header, value);
        return true;
    };

    auto false_callback = [&true_callback](sv argument, sv header, auto value) -> bool {
        return !true_callback(argument, header, value);
    };

    auto make_callback = [&true_callback, &false_callback](size_t count) -> auto {
        return make_splited_callback(count, true_callback, false_callback);
    };

    commander::basic_parser<std::string_view, std::string> other_parser;

    {
        {
            res.clear();

            other_parser("-a", make_callback(1));
            BOOST_CHECK(other_parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "-a", "-a", "placeholder_t");

            other_parser();
        }

        {
            res.clear();

            other_parser("-a", make_callback(0));
            BOOST_CHECK(other_parser.value() == "-a"); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "-a", "-a", "placeholder_t");

            other_parser(int32_t(12345), make_callback(1));
            BOOST_CHECK(other_parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
            CHECK_TUPLE_3(res.at(1), "-a", "-a", "int32_t 12345");

            other_parser();
        }

        {
            res.clear();

            other_parser("--", make_callback(0));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 0);

            other_parser();

            other_parser(uint64_t(12345), make_callback(1));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "uint64_t 12345");

            other_parser();
        }

        {
            res.clear();

            other_parser("-a", make_callback(1));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "-a");

            other_parser();

            other_parser(uint64_t(12345), make_callback(1));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 2);
            CHECK_TUPLE_3(res.at(1), "--", "--", "uint64_t 12345");

            other_parser();
        }
    }

    commander::basic_parser<std::string_view, std::string> parser;

    {
        {
            {
                res.clear();

                parser("-a", make_callback(0));
                BOOST_CHECK(parser.value() == "-a"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a", "-a", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "-a", "-a", "int32_t 12345");

                parser();
            }

            {
                res.clear();

                parser("-ab", make_callback(1));
                BOOST_CHECK(parser.value() == "-ab"); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab", "-b", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(2), "-ab", "-b", "int32_t 12345");

                parser();
            }

            {
                res.clear();

                parser("-abc", make_callback(2));
                BOOST_CHECK(parser.value() == "-abc"); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc", "-c", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                CHECK_TUPLE_3(res.at(3), "-abc", "-c", "int32_t 12345");

                parser();
            }
        }

        {
            {
                res.clear();

                parser("-a=v", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a=v", "-a", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "uint64_t 12345");

                parser();
            }

            {
                res.clear();

                parser("-ab=v", make_callback(2));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab=v", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab=v", "-b", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                parser();
            }

            {
                res.clear();

                parser("-abc=v", make_callback(3));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc=v", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc=v", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc=v", "-c", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                parser();
            }
        }
    }

    {
        {
            {
                res.clear();

                parser("--a", make_callback(0));
                BOOST_CHECK(parser.value() == "--a"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a", "--a", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--a", "--a", "int32_t 12345");

                parser();
            }

            {
                res.clear();

                parser("--ab", make_callback(0));
                BOOST_CHECK(parser.value() == "--ab"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab", "--ab", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--ab", "--ab", "int32_t 12345");

                parser();
            }

            {
                res.clear();

                parser("--abc", make_callback(0));
                BOOST_CHECK(parser.value() == "--abc"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc", "--abc", "placeholder_t");

                parser(int32_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--abc", "--abc", "int32_t 12345");

                parser();
            }
        }

        {
            {
                res.clear();

                parser("--a=v", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a=v", "--a", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "uint64_t 12345");

                parser();
            }

            {
                res.clear();

                parser("--ab=v", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab=v", "--ab", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "uint64_t 12345");

                parser();
            }

            {
                res.clear();

                parser("--abc=v", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc=v", "--abc", "v");

                parser();

                parser(uint64_t(12345), make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "uint64_t 12345");

                parser();
            }
        }
    }
}
