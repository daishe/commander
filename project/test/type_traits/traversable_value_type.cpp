//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/traversable_value_type.hpp>

#include <boost/test/unit_test.hpp>

#include "traversable_helpers.hpp"

#include <array>
#include <map>
#include <utility>
#include <vector>

BOOST_AUTO_TEST_CASE( traversable_value_type )
{
    namespace comd = commander::detail;

    {
        static_assert(std::is_same_v<comd::traversable_value_type<      std::array<int, 5>  >::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::array<int, 5>  >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::array<int, 5>& >::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::array<int, 5>& >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::array<int, 5>&&>::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::array<int, 5>&&>::type, const int&>);

        static_assert(std::is_same_v<comd::traversable_value_type<      std::map<int, int>  >::type,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::map<int, int>  >::type, const std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::map<int, int>& >::type,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::map<int, int>& >::type, const std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::map<int, int>&&>::type,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::map<int, int>&&>::type, const std::pair<const int, int>&>);

        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<int>  >::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<int>  >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<int>& >::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<int>& >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<int>&&>::type,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<int>&&>::type, const int&>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<std::vector<int>>  >::type,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<std::vector<int>>  >::type, const std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<std::vector<int>>& >::type,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<std::vector<int>>& >::type, const std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      std::vector<std::vector<int>>&&>::type,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const std::vector<std::vector<int>>&&>::type, const std::vector<int>&>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type<      bound_array  >::type,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const bound_array  >::type, const uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      bound_array& >::type,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const bound_array& >::type, const uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      bound_array&&>::type,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const bound_array&&>::type, const uint8_t&>);

        static_assert(std::is_same_v<comd::traversable_value_type<      unbound_array  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const unbound_array  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      unbound_array& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const unbound_array& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      unbound_array&&>::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const unbound_array&&>::type, void>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin_end  >::type,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin_end  >::type, void >);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin_end& >::type,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin_end& >::type, void >);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin_end&&>::type,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin_end&&>::type, void >);

        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin_cend  >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin_cend  >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin_cend& >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin_cend& >::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin_cend&&>::type, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin_cend&&>::type, const int&>);

        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_begin&&>::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_begin&&>::type, void>);

        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cbegin&&>::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cbegin&&>::type, void>);

        static_assert(std::is_same_v<comd::traversable_value_type<      container_end  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_end  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_end& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_end& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_end&&>::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_end&&>::type, void>);

        static_assert(std::is_same_v<comd::traversable_value_type<      container_cend  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cend  >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cend& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cend& >::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<      container_cend&&>::type, void>);
        static_assert(std::is_same_v<comd::traversable_value_type<const container_cend&&>::type, void>);
    }
}

BOOST_AUTO_TEST_CASE( traversable_value_type_t )
{
    namespace comd = commander::detail;

    {
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::array<int, 5>  >,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::array<int, 5>  >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::array<int, 5>& >,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::array<int, 5>& >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::array<int, 5>&&>,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::array<int, 5>&&>, const int&>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::map<int, int>  >,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::map<int, int>  >, const std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::map<int, int>& >,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::map<int, int>& >, const std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::map<int, int>&&>,       std::pair<const int, int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::map<int, int>&&>, const std::pair<const int, int>&>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<int>  >,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<int>  >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<int>& >,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<int>& >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<int>&&>,       int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<int>&&>, const int&>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<std::vector<int>>  >,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<std::vector<int>>  >, const std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<std::vector<int>>& >,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<std::vector<int>>& >, const std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      std::vector<std::vector<int>>&&>,       std::vector<int>&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const std::vector<std::vector<int>>&&>, const std::vector<int>&>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type_t<      bound_array  >,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const bound_array  >, const uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      bound_array& >,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const bound_array& >, const uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      bound_array&&>,       uint8_t&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const bound_array&&>, const uint8_t&>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      unbound_array  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const unbound_array  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      unbound_array& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const unbound_array& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      unbound_array&&>, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const unbound_array&&>, void>);
    }

    {
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin_end  >,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin_end  >, void >);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin_end& >,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin_end& >, void >);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin_end&&>,  int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin_end&&>, void >);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin_cend  >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin_cend  >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin_cend& >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin_cend& >, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin_cend&&>, const int&>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin_cend&&>, const int&>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_begin&&>, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_begin&&>, void>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cbegin&&>, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cbegin&&>, void>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_end  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_end  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_end& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_end& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_end&&>, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_end&&>, void>);

        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cend  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cend  >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cend& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cend& >, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<      container_cend&&>, void>);
        static_assert(std::is_same_v<comd::traversable_value_type_t<const container_cend&&>, void>);
    }
}
