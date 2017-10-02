//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <tuple>
#include <utility>
#include <vector>

BOOST_AUTO_TEST_CASE( tuple_visit_conjunction )
{
    std::vector<std::tuple<bool, uint32_t>> results;

    auto call_always_true = [&results](const auto& item) -> bool {
        results.emplace_back(true, item);
        return true;
    };
    auto call_not_4 = [&results](const auto& item) -> bool {
        results.emplace_back((uint32_t(item) != 4), item);
        return (uint32_t(item) != 4);
    };
    auto call_not_6 = [&results](const auto& item) -> bool {
        results.emplace_back((uint32_t(item) != 6), item);
        return (uint32_t(item) != 6);
    };

    std::tuple<uint8_t, uint16_t, uint32_t> tuple_of_ints   = {0, 1, 2};
    std::tuple<float, double, long double>  tuple_of_floats = {3.3, 4.4, 5.5};
    std::tuple<uint64_t>                    tuple_uint64_t  = {6};

    {
        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_always_true, tuple_of_ints) == true);
        BOOST_CHECK(results.size() == 3);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_always_true, tuple_of_ints, tuple_of_floats) == true);
        BOOST_CHECK(results.size() == 6);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));
        BOOST_CHECK(results.at(3) == std::forward_as_tuple(true, 3));
        BOOST_CHECK(results.at(4) == std::forward_as_tuple(true, 4));
        BOOST_CHECK(results.at(5) == std::forward_as_tuple(true, 5));
    }

    {
        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_not_4, tuple_of_ints) == true);
        BOOST_CHECK(results.size() == 3);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_not_4, tuple_of_ints, tuple_of_floats) == false);
        BOOST_CHECK(results.size() == 5);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));
        BOOST_CHECK(results.at(3) == std::forward_as_tuple(true, 3));
        BOOST_CHECK(results.at(4) == std::forward_as_tuple(false, 4));
    }

    {
        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_always_true, tuple_uint64_t) == true);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 6));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_always_true, tuple_uint64_t, tuple_of_ints) == true);
        BOOST_CHECK(results.size() == 4);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 6));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(3) == std::forward_as_tuple(true, 2));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_always_true, tuple_of_ints, tuple_uint64_t) == true);
        BOOST_CHECK(results.size() == 4);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));
        BOOST_CHECK(results.at(3) == std::forward_as_tuple(true, 6));
    }

    {
        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_not_6, tuple_uint64_t) == false);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(false, 6));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_not_6, tuple_uint64_t, tuple_of_ints) == false);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(false, 6));

        results.clear();
        BOOST_CHECK(commander::tuple_visit_conjunction(call_not_6, tuple_of_ints, tuple_uint64_t) == false);
        BOOST_CHECK(results.size() == 4);
        BOOST_CHECK(results.at(0) == std::forward_as_tuple(true, 0));
        BOOST_CHECK(results.at(1) == std::forward_as_tuple(true, 1));
        BOOST_CHECK(results.at(2) == std::forward_as_tuple(true, 2));
        BOOST_CHECK(results.at(3) == std::forward_as_tuple(false, 6));
    }
}
