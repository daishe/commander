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

BOOST_AUTO_TEST_CASE( state_check )
{
    namespace com = commander;
    using sv = std::string_view;

    std::vector<std::tuple<std::string, std::string, std::string>> res;

    auto true_callback = [&res](sv argument, sv header, auto value) -> bool {
        if constexpr (com::is_placeholder_v<decltype(value)>)
            res.emplace_back(argument, header, "placeholder_t");
        else if constexpr (com::is_no_value_v<decltype(value)>)
            res.emplace_back(argument, header, "no_value_t");
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

            other_parser("", make_callback(1));
            BOOST_CHECK(other_parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "");

            BOOST_CHECK(bool(other_parser) == true && other_parser.is_finalizable() == true); other_parser(); other_parser.finalize();
        }

        {
            res.clear();

            other_parser("-", make_callback(1));
            BOOST_CHECK(other_parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "-");

            BOOST_CHECK(bool(other_parser) == true && other_parser.is_finalizable() == true); other_parser(); other_parser.finalize();
        }

        {
            res.clear();

            other_parser("--", make_callback(0));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 0);

            BOOST_CHECK(bool(other_parser) == true && other_parser.is_finalizable() == true); other_parser(); other_parser.finalize();

            other_parser("--", make_callback(1));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "--");

            BOOST_CHECK(bool(other_parser) == true && other_parser.is_finalizable() == true); other_parser(); other_parser.finalize();
        }

        {
            res.clear();

            other_parser("---", make_callback(1));
            BOOST_CHECK(other_parser.value() == "--"); BOOST_CHECK(res.size() == 1);
            CHECK_TUPLE_3(res.at(0), "--", "--", "---");

            BOOST_CHECK(bool(other_parser) == true && other_parser.is_finalizable() == true); other_parser(); other_parser.finalize();
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

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "-a", "-a", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-ab", make_callback(1));
                BOOST_CHECK(parser.value() == "-ab"); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab", "-b", "placeholder_t");

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(2), "-ab", "-b", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-abc", make_callback(2));
                BOOST_CHECK(parser.value() == "-abc"); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc", "-c", "placeholder_t");

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                CHECK_TUPLE_3(res.at(3), "-abc", "-c", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }
        }

        {
            {
                res.clear();

                parser("-a=", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a=", "-a", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-ab=", make_callback(2));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab=", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab=", "-b", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(2), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-abc=", make_callback(3));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc=", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc=", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc=", "-c", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                CHECK_TUPLE_3(res.at(3), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }
        }

        {
            {
                res.clear();

                parser("-a=val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "-a=val", "-a", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-ab=val", make_callback(2));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(0), "-ab=val", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-ab=val", "-b", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(2), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("-abc=val", make_callback(3));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 3);
                CHECK_TUPLE_3(res.at(0), "-abc=val", "-a", "no_value_t");
                CHECK_TUPLE_3(res.at(1), "-abc=val", "-b", "no_value_t");
                CHECK_TUPLE_3(res.at(2), "-abc=val", "-c", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", true_callback);
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 4);
                CHECK_TUPLE_3(res.at(3), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
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

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--a", "--a", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--ab", make_callback(0));
                BOOST_CHECK(parser.value() == "--ab"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab", "--ab", "placeholder_t");

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--ab", "--ab", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--abc", make_callback(0));
                BOOST_CHECK(parser.value() == "--abc"); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc", "--abc", "placeholder_t");

                BOOST_CHECK(bool(parser) == false && parser.is_finalizable() == false);

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--abc", "--abc", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }
        }

        {
            {
                res.clear();

                parser("--a=", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a=", "--a", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--ab=", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab=", "--ab", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--abc=", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc=", "--abc", "");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }
        }

        {
            {
                res.clear();

                parser("--a=val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--a=val", "--a", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--ab=val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--ab=val", "--ab", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }

            {
                res.clear();

                parser("--abc=val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 1);
                CHECK_TUPLE_3(res.at(0), "--abc=val", "--abc", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();

                parser("val", make_callback(1));
                BOOST_CHECK(parser.value() == std::nullopt); BOOST_CHECK(res.size() == 2);
                CHECK_TUPLE_3(res.at(1), "--", "--", "val");

                BOOST_CHECK(bool(parser) == true && parser.is_finalizable() == true); parser(); parser.finalize();
            }
        }
    }
}
