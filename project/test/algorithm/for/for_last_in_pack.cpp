//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <vector>

BOOST_AUTO_TEST_CASE( for_last_in_pack )
{
    using sv             = std::string_view;
    using option         = std::tuple<sv, sv, commander::pack_position<sv::size_type>>;
    using option_storage = std::tuple<std::string, std::string, commander::pack_position<std::string::size_type>>;

    std::vector<option_storage> results;

    auto callback = [&results](const option& opt) {
        results.emplace_back(opt);
    };

    {
        {
            results.clear();
            auto callback_res_0 = commander::for_last_in_pack<sv>(sv("callback"),       callback);
            auto callback_res_1 = commander::for_last_in_pack<sv>(sv("callback_res_0"), callback_res_0);
            static_assert(std::is_same_v<decltype(callback), decltype(callback_res_0)>);
            static_assert(std::is_same_v<decltype(callback), decltype(callback_res_1)>);
            BOOST_CHECK(results.size() == 2);
            BOOST_CHECK(results.at(0) == option("callback",       "--", {true, 0, true}));
            BOOST_CHECK(results.at(1) == option("callback_res_0", "--", {true, 0, true}));
        }
    }

    {
        {
            results.clear();
            commander::for_last_in_pack<sv>(sv(""), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("", "--", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-", "--", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--", "--", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("---"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("---", "---", {true, 0, true}));
        }
    }

    {
        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-a"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-a", "-a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-ab"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-ab", "-b", {false, 1, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-abc"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-abc", "-c", {false, 2, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-a="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-a=", "-a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-ab="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-ab=", "-b", {false, 1, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-abc="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-abc=", "-c", {false, 2, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-a=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-a=val", "-a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-ab=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-ab=val", "-b", {false, 1, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("-abc=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("-abc=val", "-c", {false, 2, true}));
        }
    }

    {
        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--a"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--a", "--a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--ab"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--ab", "--ab", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--abc"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--abc", "--abc", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--a="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--a=", "--a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--ab="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--ab=", "--ab", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--abc="), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--abc=", "--abc", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--a=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--a=val", "--a", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--ab=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--ab=val", "--ab", {true, 0, true}));
        }

        {
            results.clear();
            commander::for_last_in_pack<sv>(sv("--abc=val"), callback);
            BOOST_CHECK(results.size() == 1);
            BOOST_CHECK(results.at(0) == option("--abc=val", "--abc", {true, 0, true}));
        }
    }
}
