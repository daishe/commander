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

BOOST_AUTO_TEST_CASE( for_parse_stop )
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
            auto callback_res_0 = commander::for_parse_stop<sv>(callback);
            auto callback_res_1 = commander::for_parse_stop<sv>(callback_res_0);
            static_assert(std::is_same_v<decltype(callback), decltype(callback_res_0)>);
            static_assert(std::is_same_v<decltype(callback), decltype(callback_res_1)>);
            BOOST_CHECK(results.size() == 2);
            BOOST_CHECK(results.at(0) == option("--", "--", {true, 0, true}));
            BOOST_CHECK(results.at(1) == option("--", "--", {true, 0, true}));
        }
    }

    {
        results.clear();
        commander::for_parse_stop<sv>(callback);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == option("--", "--", {true, 0, true}));
    }
}
