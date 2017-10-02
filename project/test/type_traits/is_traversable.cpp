//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/is_traversable.hpp>

#include <boost/test/unit_test.hpp>

#include "traversable_helpers.hpp"

#include <array>
#include <map>
#include <vector>

BOOST_AUTO_TEST_CASE( is_traversable )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_traversable<bool>::value);
        static_assert(!comd::is_traversable<char>::value);
        static_assert(!comd::is_traversable<int8_t>::value);
        static_assert(!comd::is_traversable<uint8_t>::value);
        static_assert(!comd::is_traversable<int16_t>::value);
        static_assert(!comd::is_traversable<uint16_t>::value);
        static_assert(!comd::is_traversable<char16_t>::value);
        static_assert(!comd::is_traversable<int32_t>::value);
        static_assert(!comd::is_traversable<uint32_t>::value);
        static_assert(!comd::is_traversable<char32_t>::value);
        static_assert(!comd::is_traversable<wchar_t>::value);
        static_assert(!comd::is_traversable<int64_t>::value);
        static_assert(!comd::is_traversable<uint64_t>::value);
        static_assert(!comd::is_traversable<float>::value);
        static_assert(!comd::is_traversable<double>::value);
        static_assert(!comd::is_traversable<long double>::value);
    }

    {
        static_assert( comd::is_traversable<      std::array<int, 5>  >::value);
        static_assert( comd::is_traversable<const std::array<int, 5>  >::value);
        static_assert( comd::is_traversable<      std::array<int, 5>& >::value);
        static_assert( comd::is_traversable<const std::array<int, 5>& >::value);
        static_assert( comd::is_traversable<      std::array<int, 5>&&>::value);
        static_assert( comd::is_traversable<const std::array<int, 5>&&>::value);

        static_assert( comd::is_traversable<      std::map<int, int>  >::value);
        static_assert( comd::is_traversable<const std::map<int, int>  >::value);
        static_assert( comd::is_traversable<      std::map<int, int>& >::value);
        static_assert( comd::is_traversable<const std::map<int, int>& >::value);
        static_assert( comd::is_traversable<      std::map<int, int>&&>::value);
        static_assert( comd::is_traversable<const std::map<int, int>&&>::value);

        static_assert( comd::is_traversable<      std::vector<int>  >::value);
        static_assert( comd::is_traversable<const std::vector<int>  >::value);
        static_assert( comd::is_traversable<      std::vector<int>& >::value);
        static_assert( comd::is_traversable<const std::vector<int>& >::value);
        static_assert( comd::is_traversable<      std::vector<int>&&>::value);
        static_assert( comd::is_traversable<const std::vector<int>&&>::value);
    }

    {
        static_assert( comd::is_traversable<      bound_array  >::value);
        static_assert( comd::is_traversable<const bound_array  >::value);
        static_assert( comd::is_traversable<      bound_array& >::value);
        static_assert( comd::is_traversable<const bound_array& >::value);
        static_assert( comd::is_traversable<      bound_array&&>::value);
        static_assert( comd::is_traversable<const bound_array&&>::value);

        static_assert(!comd::is_traversable<      unbound_array  >::value);
        static_assert(!comd::is_traversable<const unbound_array  >::value);
        static_assert(!comd::is_traversable<      unbound_array& >::value);
        static_assert(!comd::is_traversable<const unbound_array& >::value);
        static_assert(!comd::is_traversable<      unbound_array&&>::value);
        static_assert(!comd::is_traversable<const unbound_array&&>::value);
    }

    {
        static_assert( comd::is_traversable<      container_begin_end  >::value);
        static_assert(!comd::is_traversable<const container_begin_end  >::value);
        static_assert( comd::is_traversable<      container_begin_end& >::value);
        static_assert(!comd::is_traversable<const container_begin_end& >::value);
        static_assert( comd::is_traversable<      container_begin_end&&>::value);
        static_assert(!comd::is_traversable<const container_begin_end&&>::value);

        static_assert( comd::is_traversable<      container_cbegin_cend  >::value);
        static_assert( comd::is_traversable<const container_cbegin_cend  >::value);
        static_assert( comd::is_traversable<      container_cbegin_cend& >::value);
        static_assert( comd::is_traversable<const container_cbegin_cend& >::value);
        static_assert( comd::is_traversable<      container_cbegin_cend&&>::value);
        static_assert( comd::is_traversable<const container_cbegin_cend&&>::value);

        static_assert(!comd::is_traversable<      container_begin  >::value);
        static_assert(!comd::is_traversable<const container_begin  >::value);
        static_assert(!comd::is_traversable<      container_begin& >::value);
        static_assert(!comd::is_traversable<const container_begin& >::value);
        static_assert(!comd::is_traversable<      container_begin&&>::value);
        static_assert(!comd::is_traversable<const container_begin&&>::value);

        static_assert(!comd::is_traversable<      container_cbegin  >::value);
        static_assert(!comd::is_traversable<const container_cbegin  >::value);
        static_assert(!comd::is_traversable<      container_cbegin& >::value);
        static_assert(!comd::is_traversable<const container_cbegin& >::value);
        static_assert(!comd::is_traversable<      container_cbegin&&>::value);
        static_assert(!comd::is_traversable<const container_cbegin&&>::value);

        static_assert(!comd::is_traversable<      container_end  >::value);
        static_assert(!comd::is_traversable<const container_end  >::value);
        static_assert(!comd::is_traversable<      container_end& >::value);
        static_assert(!comd::is_traversable<const container_end& >::value);
        static_assert(!comd::is_traversable<      container_end&&>::value);
        static_assert(!comd::is_traversable<const container_end&&>::value);

        static_assert(!comd::is_traversable<      container_cend  >::value);
        static_assert(!comd::is_traversable<const container_cend  >::value);
        static_assert(!comd::is_traversable<      container_cend& >::value);
        static_assert(!comd::is_traversable<const container_cend& >::value);
        static_assert(!comd::is_traversable<      container_cend&&>::value);
        static_assert(!comd::is_traversable<const container_cend&&>::value);
    }
}

BOOST_AUTO_TEST_CASE( is_traversable_v )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_traversable_v<bool>);
        static_assert(!comd::is_traversable_v<char>);
        static_assert(!comd::is_traversable_v<int8_t>);
        static_assert(!comd::is_traversable_v<uint8_t>);
        static_assert(!comd::is_traversable_v<int16_t>);
        static_assert(!comd::is_traversable_v<uint16_t>);
        static_assert(!comd::is_traversable_v<char16_t>);
        static_assert(!comd::is_traversable_v<int32_t>);
        static_assert(!comd::is_traversable_v<uint32_t>);
        static_assert(!comd::is_traversable_v<char32_t>);
        static_assert(!comd::is_traversable_v<wchar_t>);
        static_assert(!comd::is_traversable_v<int64_t>);
        static_assert(!comd::is_traversable_v<uint64_t>);
        static_assert(!comd::is_traversable_v<float>);
        static_assert(!comd::is_traversable_v<double>);
        static_assert(!comd::is_traversable_v<long double>);
    }

    {
        static_assert( comd::is_traversable_v<      std::array<int, 5>  >);
        static_assert( comd::is_traversable_v<const std::array<int, 5>  >);
        static_assert( comd::is_traversable_v<      std::array<int, 5>& >);
        static_assert( comd::is_traversable_v<const std::array<int, 5>& >);
        static_assert( comd::is_traversable_v<      std::array<int, 5>&&>);
        static_assert( comd::is_traversable_v<const std::array<int, 5>&&>);

        static_assert( comd::is_traversable_v<      std::map<int, int>  >);
        static_assert( comd::is_traversable_v<const std::map<int, int>  >);
        static_assert( comd::is_traversable_v<      std::map<int, int>& >);
        static_assert( comd::is_traversable_v<const std::map<int, int>& >);
        static_assert( comd::is_traversable_v<      std::map<int, int>&&>);
        static_assert( comd::is_traversable_v<const std::map<int, int>&&>);

        static_assert( comd::is_traversable_v<      std::vector<int>  >);
        static_assert( comd::is_traversable_v<const std::vector<int>  >);
        static_assert( comd::is_traversable_v<      std::vector<int>& >);
        static_assert( comd::is_traversable_v<const std::vector<int>& >);
        static_assert( comd::is_traversable_v<      std::vector<int>&&>);
        static_assert( comd::is_traversable_v<const std::vector<int>&&>);
    }

    {
        static_assert( comd::is_traversable_v<      bound_array  >);
        static_assert( comd::is_traversable_v<const bound_array  >);
        static_assert( comd::is_traversable_v<      bound_array& >);
        static_assert( comd::is_traversable_v<const bound_array& >);
        static_assert( comd::is_traversable_v<      bound_array&&>);
        static_assert( comd::is_traversable_v<const bound_array&&>);

        static_assert(!comd::is_traversable_v<      unbound_array  >);
        static_assert(!comd::is_traversable_v<const unbound_array  >);
        static_assert(!comd::is_traversable_v<      unbound_array& >);
        static_assert(!comd::is_traversable_v<const unbound_array& >);
        static_assert(!comd::is_traversable_v<      unbound_array&&>);
        static_assert(!comd::is_traversable_v<const unbound_array&&>);
    }

    {
        static_assert( comd::is_traversable_v<      container_begin_end  >);
        static_assert(!comd::is_traversable_v<const container_begin_end  >);
        static_assert( comd::is_traversable_v<      container_begin_end& >);
        static_assert(!comd::is_traversable_v<const container_begin_end& >);
        static_assert( comd::is_traversable_v<      container_begin_end&&>);
        static_assert(!comd::is_traversable_v<const container_begin_end&&>);

        static_assert( comd::is_traversable_v<      container_cbegin_cend  >);
        static_assert( comd::is_traversable_v<const container_cbegin_cend  >);
        static_assert( comd::is_traversable_v<      container_cbegin_cend& >);
        static_assert( comd::is_traversable_v<const container_cbegin_cend& >);
        static_assert( comd::is_traversable_v<      container_cbegin_cend&&>);
        static_assert( comd::is_traversable_v<const container_cbegin_cend&&>);

        static_assert(!comd::is_traversable_v<      container_begin  >);
        static_assert(!comd::is_traversable_v<const container_begin  >);
        static_assert(!comd::is_traversable_v<      container_begin& >);
        static_assert(!comd::is_traversable_v<const container_begin& >);
        static_assert(!comd::is_traversable_v<      container_begin&&>);
        static_assert(!comd::is_traversable_v<const container_begin&&>);

        static_assert(!comd::is_traversable_v<      container_cbegin  >);
        static_assert(!comd::is_traversable_v<const container_cbegin  >);
        static_assert(!comd::is_traversable_v<      container_cbegin& >);
        static_assert(!comd::is_traversable_v<const container_cbegin& >);
        static_assert(!comd::is_traversable_v<      container_cbegin&&>);
        static_assert(!comd::is_traversable_v<const container_cbegin&&>);

        static_assert(!comd::is_traversable_v<      container_end  >);
        static_assert(!comd::is_traversable_v<const container_end  >);
        static_assert(!comd::is_traversable_v<      container_end& >);
        static_assert(!comd::is_traversable_v<const container_end& >);
        static_assert(!comd::is_traversable_v<      container_end&&>);
        static_assert(!comd::is_traversable_v<const container_end&&>);

        static_assert(!comd::is_traversable_v<      container_cend  >);
        static_assert(!comd::is_traversable_v<const container_cend  >);
        static_assert(!comd::is_traversable_v<      container_cend& >);
        static_assert(!comd::is_traversable_v<const container_cend& >);
        static_assert(!comd::is_traversable_v<      container_cend&&>);
        static_assert(!comd::is_traversable_v<const container_cend&&>);
    }
}
