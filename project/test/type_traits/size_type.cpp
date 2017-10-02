//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/size_type.hpp>

#include <boost/test/unit_test.hpp>

#include <array>
#include <map>
#include <vector>

struct some_size_type {};

struct type_size_type { using size_type = some_size_type; };
struct type_no_size_type {};

BOOST_AUTO_TEST_CASE( has_size_type )
{
    namespace comd = commander::detail;

    static_assert(!comd::has_size_type<bool>::value);
    static_assert(!comd::has_size_type<char>::value);
    static_assert(!comd::has_size_type<int8_t>::value);
    static_assert(!comd::has_size_type<uint8_t>::value);
    static_assert(!comd::has_size_type<int16_t>::value);
    static_assert(!comd::has_size_type<uint16_t>::value);
    static_assert(!comd::has_size_type<char16_t>::value);
    static_assert(!comd::has_size_type<int32_t>::value);
    static_assert(!comd::has_size_type<uint32_t>::value);
    static_assert(!comd::has_size_type<char32_t>::value);
    static_assert(!comd::has_size_type<wchar_t>::value);
    static_assert(!comd::has_size_type<int64_t>::value);
    static_assert(!comd::has_size_type<uint64_t>::value);
    static_assert(!comd::has_size_type<float>::value);
    static_assert(!comd::has_size_type<double>::value);
    static_assert(!comd::has_size_type<long double>::value);

    static_assert(comd::has_size_type<      std::array<int, 5>  >::value);
    static_assert(comd::has_size_type<const std::array<int, 5>  >::value);
    static_assert(comd::has_size_type<      std::array<int, 5>& >::value);
    static_assert(comd::has_size_type<const std::array<int, 5>& >::value);
    static_assert(comd::has_size_type<      std::array<int, 5>&&>::value);
    static_assert(comd::has_size_type<const std::array<int, 5>&&>::value);

    static_assert(comd::has_size_type<      std::map<int, int>  >::value);
    static_assert(comd::has_size_type<const std::map<int, int>  >::value);
    static_assert(comd::has_size_type<      std::map<int, int>& >::value);
    static_assert(comd::has_size_type<const std::map<int, int>& >::value);
    static_assert(comd::has_size_type<      std::map<int, int>&&>::value);
    static_assert(comd::has_size_type<const std::map<int, int>&&>::value);

    static_assert(comd::has_size_type<      std::vector<int>  >::value);
    static_assert(comd::has_size_type<const std::vector<int>  >::value);
    static_assert(comd::has_size_type<      std::vector<int>& >::value);
    static_assert(comd::has_size_type<const std::vector<int>& >::value);
    static_assert(comd::has_size_type<      std::vector<int>&&>::value);
    static_assert(comd::has_size_type<const std::vector<int>&&>::value);

    static_assert(comd::has_size_type<      type_size_type  >::value);
    static_assert(comd::has_size_type<const type_size_type  >::value);
    static_assert(comd::has_size_type<      type_size_type& >::value);
    static_assert(comd::has_size_type<const type_size_type& >::value);
    static_assert(comd::has_size_type<      type_size_type&&>::value);
    static_assert(comd::has_size_type<const type_size_type&&>::value);

    static_assert(!comd::has_size_type<      type_no_size_type  >::value);
    static_assert(!comd::has_size_type<const type_no_size_type  >::value);
    static_assert(!comd::has_size_type<      type_no_size_type& >::value);
    static_assert(!comd::has_size_type<const type_no_size_type& >::value);
    static_assert(!comd::has_size_type<      type_no_size_type&&>::value);
    static_assert(!comd::has_size_type<const type_no_size_type&&>::value);
}

BOOST_AUTO_TEST_CASE( has_size_type_v )
{
    namespace comd = commander::detail;

    static_assert(!comd::has_size_type_v<bool>);
    static_assert(!comd::has_size_type_v<char>);
    static_assert(!comd::has_size_type_v<int8_t>);
    static_assert(!comd::has_size_type_v<uint8_t>);
    static_assert(!comd::has_size_type_v<int16_t>);
    static_assert(!comd::has_size_type_v<uint16_t>);
    static_assert(!comd::has_size_type_v<char16_t>);
    static_assert(!comd::has_size_type_v<int32_t>);
    static_assert(!comd::has_size_type_v<uint32_t>);
    static_assert(!comd::has_size_type_v<char32_t>);
    static_assert(!comd::has_size_type_v<wchar_t>);
    static_assert(!comd::has_size_type_v<int64_t>);
    static_assert(!comd::has_size_type_v<uint64_t>);
    static_assert(!comd::has_size_type_v<float>);
    static_assert(!comd::has_size_type_v<double>);
    static_assert(!comd::has_size_type_v<long double>);

    static_assert(comd::has_size_type_v<      std::array<int, 5>  >);
    static_assert(comd::has_size_type_v<const std::array<int, 5>  >);
    static_assert(comd::has_size_type_v<      std::array<int, 5>& >);
    static_assert(comd::has_size_type_v<const std::array<int, 5>& >);
    static_assert(comd::has_size_type_v<      std::array<int, 5>&&>);
    static_assert(comd::has_size_type_v<const std::array<int, 5>&&>);

    static_assert(comd::has_size_type_v<      std::map<int, int>  >);
    static_assert(comd::has_size_type_v<const std::map<int, int>  >);
    static_assert(comd::has_size_type_v<      std::map<int, int>& >);
    static_assert(comd::has_size_type_v<const std::map<int, int>& >);
    static_assert(comd::has_size_type_v<      std::map<int, int>&&>);
    static_assert(comd::has_size_type_v<const std::map<int, int>&&>);

    static_assert(comd::has_size_type_v<      std::vector<int>  >);
    static_assert(comd::has_size_type_v<const std::vector<int>  >);
    static_assert(comd::has_size_type_v<      std::vector<int>& >);
    static_assert(comd::has_size_type_v<const std::vector<int>& >);
    static_assert(comd::has_size_type_v<      std::vector<int>&&>);
    static_assert(comd::has_size_type_v<const std::vector<int>&&>);

    static_assert(comd::has_size_type_v<      type_size_type  >);
    static_assert(comd::has_size_type_v<const type_size_type  >);
    static_assert(comd::has_size_type_v<      type_size_type& >);
    static_assert(comd::has_size_type_v<const type_size_type& >);
    static_assert(comd::has_size_type_v<      type_size_type&&>);
    static_assert(comd::has_size_type_v<const type_size_type&&>);

    static_assert(!comd::has_size_type_v<      type_no_size_type  >);
    static_assert(!comd::has_size_type_v<const type_no_size_type  >);
    static_assert(!comd::has_size_type_v<      type_no_size_type& >);
    static_assert(!comd::has_size_type_v<const type_no_size_type& >);
    static_assert(!comd::has_size_type_v<      type_no_size_type&&>);
    static_assert(!comd::has_size_type_v<const type_no_size_type&&>);
}

BOOST_AUTO_TEST_CASE( size_type )
{
    namespace comd = commander::detail;

    static_assert(std::is_same_v<comd::size_type<       bool>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<       char>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<     int8_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<    uint8_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<    int16_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<   uint16_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<   char16_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<    int32_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<   uint32_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<   char32_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<    wchar_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<    int64_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<   uint64_t>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<      float>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<     double>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<long double>::type, size_t>);

    static_assert(std::is_same_v<comd::size_type<      std::array<int, 5>  >::type, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::array<int, 5>  >::type, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::array<int, 5>& >::type, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::array<int, 5>& >::type, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::array<int, 5>&&>::type, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::array<int, 5>&&>::type, std::array<int, 5>::size_type>);

    static_assert(std::is_same_v<comd::size_type<      std::map<int, int>  >::type, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::map<int, int>  >::type, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::map<int, int>& >::type, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::map<int, int>& >::type, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::map<int, int>&&>::type, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::map<int, int>&&>::type, std::map<int, int>::size_type>);

    static_assert(std::is_same_v<comd::size_type<      std::vector<int>  >::type, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::vector<int>  >::type, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::vector<int>& >::type, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::vector<int>& >::type, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<      std::vector<int>&&>::type, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type<const std::vector<int>&&>::type, std::vector<int>::size_type>);

    static_assert(std::is_same_v<comd::size_type<      type_size_type  >::type, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_size_type  >::type, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type<      type_size_type& >::type, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_size_type& >::type, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type<      type_size_type&&>::type, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_size_type&&>::type, type_size_type::size_type>);

    static_assert(std::is_same_v<comd::size_type<      type_no_size_type  >::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type  >::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<      type_no_size_type& >::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type& >::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<      type_no_size_type&&>::type, size_t>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type&&>::type, size_t>);

    static_assert(std::is_same_v<comd::size_type<      type_no_size_type  , some_size_type>::type, some_size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type  , some_size_type>::type, some_size_type>);
    static_assert(std::is_same_v<comd::size_type<      type_no_size_type& , some_size_type>::type, some_size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type& , some_size_type>::type, some_size_type>);
    static_assert(std::is_same_v<comd::size_type<      type_no_size_type&&, some_size_type>::type, some_size_type>);
    static_assert(std::is_same_v<comd::size_type<const type_no_size_type&&, some_size_type>::type, some_size_type>);
}

BOOST_AUTO_TEST_CASE( size_type_t )
{
    namespace comd = commander::detail;

    static_assert(std::is_same_v<comd::size_type_t<       bool>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<       char>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<     int8_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<    uint8_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<    int16_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<   uint16_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<   char16_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<    int32_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<   uint32_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<   char32_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<    wchar_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<    int64_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<   uint64_t>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<      float>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<     double>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<long double>, size_t>);

    static_assert(std::is_same_v<comd::size_type_t<      std::array<int, 5>  >, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::array<int, 5>  >, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::array<int, 5>& >, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::array<int, 5>& >, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::array<int, 5>&&>, std::array<int, 5>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::array<int, 5>&&>, std::array<int, 5>::size_type>);

    static_assert(std::is_same_v<comd::size_type_t<      std::map<int, int>  >, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::map<int, int>  >, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::map<int, int>& >, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::map<int, int>& >, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::map<int, int>&&>, std::map<int, int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::map<int, int>&&>, std::map<int, int>::size_type>);

    static_assert(std::is_same_v<comd::size_type_t<      std::vector<int>  >, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::vector<int>  >, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::vector<int>& >, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::vector<int>& >, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      std::vector<int>&&>, std::vector<int>::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const std::vector<int>&&>, std::vector<int>::size_type>);

    static_assert(std::is_same_v<comd::size_type_t<      type_size_type  >, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_size_type  >, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      type_size_type& >, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_size_type& >, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      type_size_type&&>, type_size_type::size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_size_type&&>, type_size_type::size_type>);

    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type  >, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type  >, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type& >, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type& >, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type&&>, size_t>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type&&>, size_t>);

    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type  , some_size_type>, some_size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type  , some_size_type>, some_size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type& , some_size_type>, some_size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type& , some_size_type>, some_size_type>);
    static_assert(std::is_same_v<comd::size_type_t<      type_no_size_type&&, some_size_type>, some_size_type>);
    static_assert(std::is_same_v<comd::size_type_t<const type_no_size_type&&, some_size_type>, some_size_type>);
}
