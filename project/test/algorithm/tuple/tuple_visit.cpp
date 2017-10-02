//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <tuple>
#include <vector>

BOOST_AUTO_TEST_CASE( tuple_visit )
{
    std::vector<uint32_t> results;

    auto call = [&results](const auto& item) -> void {
        results.emplace_back(item);
        return;
    };

    std::tuple<>                            empty_tuple;
    std::tuple<uint8_t, uint16_t, uint32_t> tuple_of_ints   = {0, 1, 2};
    std::tuple<float, double, long double>  tuple_of_floats = {3.3, 4.4, 5.5};
    std::tuple<uint64_t>                    tuple_uint64_t  = {6};

    {
        results.clear();
        commander::tuple_visit(call, empty_tuple);
        BOOST_CHECK(results.size() == 0);

        results.clear();
        commander::tuple_visit(call, empty_tuple, tuple_uint64_t);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == 6);

        results.clear();
        commander::tuple_visit(call, tuple_uint64_t, empty_tuple);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == 6);
    }

    {
        results.clear();
        commander::tuple_visit(call, tuple_of_ints);
        BOOST_CHECK(results.size() == 3);
        BOOST_CHECK(results.at(0) == 0);
        BOOST_CHECK(results.at(1) == 1);
        BOOST_CHECK(results.at(2) == 2);

        results.clear();
        commander::tuple_visit(call, tuple_of_ints, tuple_of_floats);
        BOOST_CHECK(results.size() == 6);
        BOOST_CHECK(results.at(0) == 0);
        BOOST_CHECK(results.at(1) == 1);
        BOOST_CHECK(results.at(2) == 2);
        BOOST_CHECK(results.at(3) == 3);
        BOOST_CHECK(results.at(4) == 4);
        BOOST_CHECK(results.at(5) == 5);
    }

    {
        results.clear();
        commander::tuple_visit(call, tuple_uint64_t);
        BOOST_CHECK(results.size() == 1);
        BOOST_CHECK(results.at(0) == 6);

        results.clear();
        commander::tuple_visit(call, tuple_uint64_t, tuple_of_ints);
        BOOST_CHECK(results.size() == 4);
        BOOST_CHECK(results.at(0) == 6);
        BOOST_CHECK(results.at(1) == 0);
        BOOST_CHECK(results.at(2) == 1);
        BOOST_CHECK(results.at(3) == 2);

        results.clear();
        commander::tuple_visit(call, tuple_of_ints, tuple_uint64_t);
        BOOST_CHECK(results.size() == 4);
        BOOST_CHECK(results.at(0) == 0);
        BOOST_CHECK(results.at(1) == 1);
        BOOST_CHECK(results.at(2) == 2);
        BOOST_CHECK(results.at(3) == 6);
    }
}
