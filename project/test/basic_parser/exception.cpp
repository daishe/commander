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

BOOST_AUTO_TEST_CASE( exception )
{
    namespace com = commander;
    using sv = std::string_view;

    // using mismatch_error      = com::mismatch_error<std::string, std::string>;
    using missing_value_error = com::missing_value_error<std::string, std::string>;
    using input_not_consumed  = com::input_not_consumed<std::string, std::string>;

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

    commander::basic_parser<std::string_view, std::string> parser;

    {
        // -a -ab -abc
        {
            // -a
            {
                const char* arg = "-a";
                // 0 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "-a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "-a", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "-a", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "-a", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // -ab
            {
                const char* arg = "-ab";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "-b");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "-b", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), arg, "-b", "uint64_t 12345");

                    parser();
                }

                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "-b", "int32_t 12345");

                    parser();
                }

                // 2 0 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 2 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // -abc
            {
                const char* arg = "-abc";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 1 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                }

                // 2 0 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-c");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "-c");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), arg, "-c", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-c");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 4);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 5);
                    CHECK_TUPLE_3(res.at(4), arg, "-c", "uint64_t 12345");

                    parser();
                }

                // 2 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "-c");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 3);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), arg, "-c", "int32_t 12345");

                    parser();
                }

                // 3 0 1
                {
                    res.clear();

                    parser(arg, make_callback(3));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 5);
                    CHECK_TUPLE_3(res.at(4), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 3 1
                {
                    res.clear();

                    parser(arg, make_callback(3));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                }
            }
        }

        // -a=v -ab=v -abc=v
        {
            // -a=v
            {
                const char* arg = "-a=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // -ab=v
            {
                const char* arg = "-ab=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), input_not_consumed, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 1 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), input_not_consumed, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                }

                // 2 0 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 2 1
                {
                    res.clear();

                    parser(arg, make_callback(2));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // -abc=v
            {
                const char* arg = "-abc=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), missing_value_error, arg, "-a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 1 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(1)), missing_value_error, arg, "-b");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "int32_t 12345");

                    parser();
                }

                // 2 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(2)), input_not_consumed, arg, "-c");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 5);
                    CHECK_TUPLE_3(res.at(4), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 2 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(2)), input_not_consumed, arg, "-c");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                }

                // 3 0 1
                {
                    res.clear();

                    parser(arg, make_callback(3));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 5);
                    CHECK_TUPLE_3(res.at(4), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 3 1
                {
                    res.clear();

                    parser(arg, make_callback(3));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(0), arg, "-a", "no_value_t");
                    CHECK_TUPLE_3(res.at(1), arg, "-b", "no_value_t");
                    CHECK_TUPLE_3(res.at(2), arg, "-c", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                    CHECK_TUPLE_3(res.at(3), "--", "--", "int32_t 12345");

                    parser();
                }
            }
        }
    }

    {
        // --a --ab --abc
        {
            // --a
            {
                const char* arg = "--a";
                // 0 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "--a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--a", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "--a", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--a");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--a", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // --ab
            {
                const char* arg = "--ab";
                // 0 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--ab");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "--ab");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--ab", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--ab");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "--ab", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--ab");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--ab", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // --abc
            {
                const char* arg = "--abc";
                // 0 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--abc");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, arg, "--abc");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--abc", "int32_t 12345");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--abc");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), arg, "--abc", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    parser(arg, make_callback(0));
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "placeholder_t");

                    CHECK_EXCEPTION_AH(parser(), missing_value_error, arg, "--abc");
                    BOOST_CHECK(parser.value() == arg); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), arg, "--abc", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "placeholder_t");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }
        }

        // --a=v --ab=v --abc=v
        {
            // --a=v
            {
                const char* arg = "--a=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--a");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--a", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // --ab=v
            {
                const char* arg = "--ab=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--ab");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--ab");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--ab", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }

            // --abc=v
            {
                const char* arg = "--abc=v";
                // 0 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--abc");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }

                // 0 1
                {
                    res.clear();

                    CHECK_EXCEPTION_AH(parser(arg, make_callback(0)), input_not_consumed, arg, "--abc");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }

                // 1 0 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    CHECK_EXCEPTION_AH(parser(int32_t(12345), make_callback(0)), input_not_consumed, "--", "--");
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);

                    parser(uint64_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                    CHECK_TUPLE_3(res.at(2), "--", "--", "uint64_t 12345");

                    parser();
                }


                // 1 1
                {
                    res.clear();

                    parser(arg, make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                    CHECK_TUPLE_3(res.at(0), arg, "--abc", "v");

                    parser();
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);

                    parser(int32_t(12345), make_callback(1));
                    BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                    CHECK_TUPLE_3(res.at(1), "--", "--", "int32_t 12345");

                    parser();
                }
            }
        }
    }
}
