//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/is_implicitly_default_constructible.hpp>

#include <boost/test/unit_test.hpp>

struct implic {          implic() {}; };
struct explic { explicit explic() {}; };

BOOST_AUTO_TEST_CASE( is_implicitly_default_constructible )
{
    namespace comd = commander::detail;

    static_assert(comd::is_implicitly_default_constructible<bool>::value);
    static_assert(comd::is_implicitly_default_constructible<char>::value);
    static_assert(comd::is_implicitly_default_constructible<int8_t>::value);
    static_assert(comd::is_implicitly_default_constructible<uint8_t>::value);
    static_assert(comd::is_implicitly_default_constructible<int16_t>::value);
    static_assert(comd::is_implicitly_default_constructible<uint16_t>::value);
    static_assert(comd::is_implicitly_default_constructible<char16_t>::value);
    static_assert(comd::is_implicitly_default_constructible<int32_t>::value);
    static_assert(comd::is_implicitly_default_constructible<uint32_t>::value);
    static_assert(comd::is_implicitly_default_constructible<char32_t>::value);
    static_assert(comd::is_implicitly_default_constructible<wchar_t>::value);
    static_assert(comd::is_implicitly_default_constructible<int64_t>::value);
    static_assert(comd::is_implicitly_default_constructible<uint64_t>::value);
    static_assert(comd::is_implicitly_default_constructible<float>::value);
    static_assert(comd::is_implicitly_default_constructible<double>::value);
    static_assert(comd::is_implicitly_default_constructible<long double>::value);

    static_assert( comd::is_implicitly_default_constructible<      implic   >::value);
    static_assert( comd::is_implicitly_default_constructible<const implic   >::value);
    static_assert( comd::is_implicitly_default_constructible<      implic[5]>::value);
    static_assert( comd::is_implicitly_default_constructible<const implic[5]>::value);
    static_assert(!comd::is_implicitly_default_constructible<      implic&  >::value);
    static_assert(!comd::is_implicitly_default_constructible<const implic&  >::value);
    static_assert(!comd::is_implicitly_default_constructible<      implic&& >::value);
    static_assert(!comd::is_implicitly_default_constructible<const implic&& >::value);

    static_assert(!comd::is_implicitly_default_constructible<      explic   >::value);
    static_assert(!comd::is_implicitly_default_constructible<const explic   >::value);
    static_assert(!comd::is_implicitly_default_constructible<      explic[5]>::value);
    static_assert(!comd::is_implicitly_default_constructible<const explic[5]>::value);
    static_assert(!comd::is_implicitly_default_constructible<      explic&  >::value);
    static_assert(!comd::is_implicitly_default_constructible<const explic&  >::value);
    static_assert(!comd::is_implicitly_default_constructible<      explic&& >::value);
    static_assert(!comd::is_implicitly_default_constructible<const explic&& >::value);
}

BOOST_AUTO_TEST_CASE( is_implicitly_default_constructible_v )
{
    namespace comd = commander::detail;

    static_assert(comd::is_implicitly_default_constructible_v<bool>);
    static_assert(comd::is_implicitly_default_constructible_v<char>);
    static_assert(comd::is_implicitly_default_constructible_v<int8_t>);
    static_assert(comd::is_implicitly_default_constructible_v<uint8_t>);
    static_assert(comd::is_implicitly_default_constructible_v<int16_t>);
    static_assert(comd::is_implicitly_default_constructible_v<uint16_t>);
    static_assert(comd::is_implicitly_default_constructible_v<char16_t>);
    static_assert(comd::is_implicitly_default_constructible_v<int32_t>);
    static_assert(comd::is_implicitly_default_constructible_v<uint32_t>);
    static_assert(comd::is_implicitly_default_constructible_v<char32_t>);
    static_assert(comd::is_implicitly_default_constructible_v<wchar_t>);
    static_assert(comd::is_implicitly_default_constructible_v<int64_t>);
    static_assert(comd::is_implicitly_default_constructible_v<uint64_t>);
    static_assert(comd::is_implicitly_default_constructible_v<float>);
    static_assert(comd::is_implicitly_default_constructible_v<double>);
    static_assert(comd::is_implicitly_default_constructible_v<long double>);

    static_assert( comd::is_implicitly_default_constructible_v<      implic   >);
    static_assert( comd::is_implicitly_default_constructible_v<const implic   >);
    static_assert( comd::is_implicitly_default_constructible_v<      implic[5]>);
    static_assert( comd::is_implicitly_default_constructible_v<const implic[5]>);
    static_assert(!comd::is_implicitly_default_constructible_v<      implic&  >);
    static_assert(!comd::is_implicitly_default_constructible_v<const implic&  >);
    static_assert(!comd::is_implicitly_default_constructible_v<      implic&& >);
    static_assert(!comd::is_implicitly_default_constructible_v<const implic&& >);

    static_assert(!comd::is_implicitly_default_constructible_v<      explic   >);
    static_assert(!comd::is_implicitly_default_constructible_v<const explic   >);
    static_assert(!comd::is_implicitly_default_constructible_v<      explic[5]>);
    static_assert(!comd::is_implicitly_default_constructible_v<const explic[5]>);
    static_assert(!comd::is_implicitly_default_constructible_v<      explic&  >);
    static_assert(!comd::is_implicitly_default_constructible_v<const explic&  >);
    static_assert(!comd::is_implicitly_default_constructible_v<      explic&& >);
    static_assert(!comd::is_implicitly_default_constructible_v<const explic&& >);
}
