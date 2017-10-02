//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/exception.hpp>

#include <boost/test/unit_test.hpp>

#include <stdexcept>
#include <string>
#include <type_traits>

BOOST_AUTO_TEST_CASE( tree_test )
{
    namespace com = commander;

    static_assert(std::is_base_of_v<std::runtime_error, com::argument_error<std::string>>);

    static_assert(std::is_base_of_v<std::runtime_error,               com::option_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::argument_error<std::string>, com::option_error<std::string, std::string>>);

    static_assert(std::is_base_of_v<std::runtime_error,                          com::mismatch_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::argument_error<std::string>,            com::mismatch_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::option_error<std::string, std::string>, com::mismatch_error<std::string, std::string>>);

    static_assert(std::is_base_of_v<std::runtime_error,                          com::input_not_consumed<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::argument_error<std::string>,            com::input_not_consumed<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::option_error<std::string, std::string>, com::input_not_consumed<std::string, std::string>>);

    static_assert(std::is_base_of_v<std::runtime_error,                                com::missing_value_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::argument_error<std::string>,                  com::missing_value_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::option_error<std::string, std::string>,       com::missing_value_error<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::input_not_consumed<std::string, std::string>, com::missing_value_error<std::string, std::string>>);

    static_assert(std::is_base_of_v<std::runtime_error,                                com::bad_value<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::argument_error<std::string>,                  com::bad_value<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::option_error<std::string, std::string>,       com::bad_value<std::string, std::string>>);
    static_assert(std::is_base_of_v<com::input_not_consumed<std::string, std::string>, com::bad_value<std::string, std::string>>);
}