//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/is_character_like.hpp>

#include <boost/test/unit_test.hpp>

#include "character_helpers.hpp"

BOOST_AUTO_TEST_CASE( is_character_like )
{
    namespace comd = commander::detail;

    static_assert( comd::is_character_like<             bool  >::value);
    static_assert( comd::is_character_like<const        bool  >::value);
    static_assert( comd::is_character_like<             bool& >::value);
    static_assert( comd::is_character_like<const        bool& >::value);
    static_assert( comd::is_character_like<             bool&&>::value);
    static_assert( comd::is_character_like<const        bool&&>::value);
    static_assert( comd::is_character_like<             char  >::value);
    static_assert( comd::is_character_like<const        char  >::value);
    static_assert( comd::is_character_like<             char& >::value);
    static_assert( comd::is_character_like<const        char& >::value);
    static_assert( comd::is_character_like<             char&&>::value);
    static_assert( comd::is_character_like<const        char&&>::value);
    static_assert( comd::is_character_like<           int8_t  >::value);
    static_assert( comd::is_character_like<const      int8_t  >::value);
    static_assert( comd::is_character_like<           int8_t& >::value);
    static_assert( comd::is_character_like<const      int8_t& >::value);
    static_assert( comd::is_character_like<           int8_t&&>::value);
    static_assert( comd::is_character_like<const      int8_t&&>::value);
    static_assert( comd::is_character_like<          uint8_t  >::value);
    static_assert( comd::is_character_like<const     uint8_t  >::value);
    static_assert( comd::is_character_like<          uint8_t& >::value);
    static_assert( comd::is_character_like<const     uint8_t& >::value);
    static_assert( comd::is_character_like<          uint8_t&&>::value);
    static_assert( comd::is_character_like<const     uint8_t&&>::value);
    static_assert( comd::is_character_like<          int16_t  >::value);
    static_assert( comd::is_character_like<const     int16_t  >::value);
    static_assert( comd::is_character_like<          int16_t& >::value);
    static_assert( comd::is_character_like<const     int16_t& >::value);
    static_assert( comd::is_character_like<          int16_t&&>::value);
    static_assert( comd::is_character_like<const     int16_t&&>::value);
    static_assert( comd::is_character_like<         uint16_t  >::value);
    static_assert( comd::is_character_like<const    uint16_t  >::value);
    static_assert( comd::is_character_like<         uint16_t& >::value);
    static_assert( comd::is_character_like<const    uint16_t& >::value);
    static_assert( comd::is_character_like<         uint16_t&&>::value);
    static_assert( comd::is_character_like<const    uint16_t&&>::value);
    static_assert( comd::is_character_like<         char16_t  >::value);
    static_assert( comd::is_character_like<const    char16_t  >::value);
    static_assert( comd::is_character_like<         char16_t& >::value);
    static_assert( comd::is_character_like<const    char16_t& >::value);
    static_assert( comd::is_character_like<         char16_t&&>::value);
    static_assert( comd::is_character_like<const    char16_t&&>::value);
    static_assert( comd::is_character_like<          int32_t  >::value);
    static_assert( comd::is_character_like<const     int32_t  >::value);
    static_assert( comd::is_character_like<          int32_t& >::value);
    static_assert( comd::is_character_like<const     int32_t& >::value);
    static_assert( comd::is_character_like<          int32_t&&>::value);
    static_assert( comd::is_character_like<const     int32_t&&>::value);
    static_assert( comd::is_character_like<         uint32_t  >::value);
    static_assert( comd::is_character_like<const    uint32_t  >::value);
    static_assert( comd::is_character_like<         uint32_t& >::value);
    static_assert( comd::is_character_like<const    uint32_t& >::value);
    static_assert( comd::is_character_like<         uint32_t&&>::value);
    static_assert( comd::is_character_like<const    uint32_t&&>::value);
    static_assert( comd::is_character_like<         char32_t  >::value);
    static_assert( comd::is_character_like<const    char32_t  >::value);
    static_assert( comd::is_character_like<         char32_t& >::value);
    static_assert( comd::is_character_like<const    char32_t& >::value);
    static_assert( comd::is_character_like<         char32_t&&>::value);
    static_assert( comd::is_character_like<const    char32_t&&>::value);
    static_assert( comd::is_character_like<          wchar_t  >::value);
    static_assert( comd::is_character_like<const     wchar_t  >::value);
    static_assert( comd::is_character_like<          wchar_t& >::value);
    static_assert( comd::is_character_like<const     wchar_t& >::value);
    static_assert( comd::is_character_like<          wchar_t&&>::value);
    static_assert( comd::is_character_like<const     wchar_t&&>::value);
    static_assert( comd::is_character_like<          int64_t  >::value);
    static_assert( comd::is_character_like<const     int64_t  >::value);
    static_assert( comd::is_character_like<          int64_t& >::value);
    static_assert( comd::is_character_like<const     int64_t& >::value);
    static_assert( comd::is_character_like<          int64_t&&>::value);
    static_assert( comd::is_character_like<const     int64_t&&>::value);
    static_assert( comd::is_character_like<         uint64_t  >::value);
    static_assert( comd::is_character_like<const    uint64_t  >::value);
    static_assert( comd::is_character_like<         uint64_t& >::value);
    static_assert( comd::is_character_like<const    uint64_t& >::value);
    static_assert( comd::is_character_like<         uint64_t&&>::value);
    static_assert( comd::is_character_like<const    uint64_t&&>::value);
    static_assert( comd::is_character_like<            float  >::value);
    static_assert( comd::is_character_like<const       float  >::value);
    static_assert( comd::is_character_like<            float& >::value);
    static_assert( comd::is_character_like<const       float& >::value);
    static_assert( comd::is_character_like<            float&&>::value);
    static_assert( comd::is_character_like<const       float&&>::value);
    static_assert( comd::is_character_like<           double  >::value);
    static_assert( comd::is_character_like<const      double  >::value);
    static_assert( comd::is_character_like<           double& >::value);
    static_assert( comd::is_character_like<const      double& >::value);
    static_assert( comd::is_character_like<           double&&>::value);
    static_assert( comd::is_character_like<const      double&&>::value);
    static_assert( comd::is_character_like<      long double  >::value);
    static_assert( comd::is_character_like<const long double  >::value);
    static_assert( comd::is_character_like<      long double& >::value);
    static_assert( comd::is_character_like<const long double& >::value);
    static_assert( comd::is_character_like<      long double&&>::value);
    static_assert( comd::is_character_like<const long double&&>::value);

    static_assert( comd::is_character_like<      some_char  >::value);
    static_assert( comd::is_character_like<const some_char  >::value);
    static_assert( comd::is_character_like<      some_char& >::value);
    static_assert( comd::is_character_like<const some_char& >::value);
    static_assert( comd::is_character_like<      some_char&&>::value);
    static_assert( comd::is_character_like<const some_char&&>::value);

    static_assert(!comd::is_character_like<      non_char_constr  >::value);
    static_assert(!comd::is_character_like<const non_char_constr  >::value);
    static_assert(!comd::is_character_like<      non_char_constr& >::value);
    static_assert(!comd::is_character_like<const non_char_constr& >::value);
    static_assert(!comd::is_character_like<      non_char_constr&&>::value);
    static_assert(!comd::is_character_like<const non_char_constr&&>::value);

    static_assert(!comd::is_character_like<      non_const_comp_char  >::value);
    static_assert(!comd::is_character_like<const non_const_comp_char  >::value);
    static_assert(!comd::is_character_like<      non_const_comp_char& >::value);
    static_assert(!comd::is_character_like<const non_const_comp_char& >::value);
    static_assert(!comd::is_character_like<      non_const_comp_char&&>::value);
    static_assert(!comd::is_character_like<const non_const_comp_char&&>::value);

    static_assert(!comd::is_character_like<      non_char  >::value);
    static_assert(!comd::is_character_like<const non_char  >::value);
    static_assert(!comd::is_character_like<      non_char& >::value);
    static_assert(!comd::is_character_like<const non_char& >::value);
    static_assert(!comd::is_character_like<      non_char&&>::value);
    static_assert(!comd::is_character_like<const non_char&&>::value);
}

BOOST_AUTO_TEST_CASE( is_character_like_v )
{
    namespace comd = commander::detail;

    static_assert( comd::is_character_like_v<             bool  >);
    static_assert( comd::is_character_like_v<const        bool  >);
    static_assert( comd::is_character_like_v<             bool& >);
    static_assert( comd::is_character_like_v<const        bool& >);
    static_assert( comd::is_character_like_v<             bool&&>);
    static_assert( comd::is_character_like_v<const        bool&&>);
    static_assert( comd::is_character_like_v<             char  >);
    static_assert( comd::is_character_like_v<const        char  >);
    static_assert( comd::is_character_like_v<             char& >);
    static_assert( comd::is_character_like_v<const        char& >);
    static_assert( comd::is_character_like_v<             char&&>);
    static_assert( comd::is_character_like_v<const        char&&>);
    static_assert( comd::is_character_like_v<           int8_t  >);
    static_assert( comd::is_character_like_v<const      int8_t  >);
    static_assert( comd::is_character_like_v<           int8_t& >);
    static_assert( comd::is_character_like_v<const      int8_t& >);
    static_assert( comd::is_character_like_v<           int8_t&&>);
    static_assert( comd::is_character_like_v<const      int8_t&&>);
    static_assert( comd::is_character_like_v<          uint8_t  >);
    static_assert( comd::is_character_like_v<const     uint8_t  >);
    static_assert( comd::is_character_like_v<          uint8_t& >);
    static_assert( comd::is_character_like_v<const     uint8_t& >);
    static_assert( comd::is_character_like_v<          uint8_t&&>);
    static_assert( comd::is_character_like_v<const     uint8_t&&>);
    static_assert( comd::is_character_like_v<          int16_t  >);
    static_assert( comd::is_character_like_v<const     int16_t  >);
    static_assert( comd::is_character_like_v<          int16_t& >);
    static_assert( comd::is_character_like_v<const     int16_t& >);
    static_assert( comd::is_character_like_v<          int16_t&&>);
    static_assert( comd::is_character_like_v<const     int16_t&&>);
    static_assert( comd::is_character_like_v<         uint16_t  >);
    static_assert( comd::is_character_like_v<const    uint16_t  >);
    static_assert( comd::is_character_like_v<         uint16_t& >);
    static_assert( comd::is_character_like_v<const    uint16_t& >);
    static_assert( comd::is_character_like_v<         uint16_t&&>);
    static_assert( comd::is_character_like_v<const    uint16_t&&>);
    static_assert( comd::is_character_like_v<         char16_t  >);
    static_assert( comd::is_character_like_v<const    char16_t  >);
    static_assert( comd::is_character_like_v<         char16_t& >);
    static_assert( comd::is_character_like_v<const    char16_t& >);
    static_assert( comd::is_character_like_v<         char16_t&&>);
    static_assert( comd::is_character_like_v<const    char16_t&&>);
    static_assert( comd::is_character_like_v<          int32_t  >);
    static_assert( comd::is_character_like_v<const     int32_t  >);
    static_assert( comd::is_character_like_v<          int32_t& >);
    static_assert( comd::is_character_like_v<const     int32_t& >);
    static_assert( comd::is_character_like_v<          int32_t&&>);
    static_assert( comd::is_character_like_v<const     int32_t&&>);
    static_assert( comd::is_character_like_v<         uint32_t  >);
    static_assert( comd::is_character_like_v<const    uint32_t  >);
    static_assert( comd::is_character_like_v<         uint32_t& >);
    static_assert( comd::is_character_like_v<const    uint32_t& >);
    static_assert( comd::is_character_like_v<         uint32_t&&>);
    static_assert( comd::is_character_like_v<const    uint32_t&&>);
    static_assert( comd::is_character_like_v<         char32_t  >);
    static_assert( comd::is_character_like_v<const    char32_t  >);
    static_assert( comd::is_character_like_v<         char32_t& >);
    static_assert( comd::is_character_like_v<const    char32_t& >);
    static_assert( comd::is_character_like_v<         char32_t&&>);
    static_assert( comd::is_character_like_v<const    char32_t&&>);
    static_assert( comd::is_character_like_v<          wchar_t  >);
    static_assert( comd::is_character_like_v<const     wchar_t  >);
    static_assert( comd::is_character_like_v<          wchar_t& >);
    static_assert( comd::is_character_like_v<const     wchar_t& >);
    static_assert( comd::is_character_like_v<          wchar_t&&>);
    static_assert( comd::is_character_like_v<const     wchar_t&&>);
    static_assert( comd::is_character_like_v<          int64_t  >);
    static_assert( comd::is_character_like_v<const     int64_t  >);
    static_assert( comd::is_character_like_v<          int64_t& >);
    static_assert( comd::is_character_like_v<const     int64_t& >);
    static_assert( comd::is_character_like_v<          int64_t&&>);
    static_assert( comd::is_character_like_v<const     int64_t&&>);
    static_assert( comd::is_character_like_v<         uint64_t  >);
    static_assert( comd::is_character_like_v<const    uint64_t  >);
    static_assert( comd::is_character_like_v<         uint64_t& >);
    static_assert( comd::is_character_like_v<const    uint64_t& >);
    static_assert( comd::is_character_like_v<         uint64_t&&>);
    static_assert( comd::is_character_like_v<const    uint64_t&&>);
    static_assert( comd::is_character_like_v<            float  >);
    static_assert( comd::is_character_like_v<const       float  >);
    static_assert( comd::is_character_like_v<            float& >);
    static_assert( comd::is_character_like_v<const       float& >);
    static_assert( comd::is_character_like_v<            float&&>);
    static_assert( comd::is_character_like_v<const       float&&>);
    static_assert( comd::is_character_like_v<           double  >);
    static_assert( comd::is_character_like_v<const      double  >);
    static_assert( comd::is_character_like_v<           double& >);
    static_assert( comd::is_character_like_v<const      double& >);
    static_assert( comd::is_character_like_v<           double&&>);
    static_assert( comd::is_character_like_v<const      double&&>);
    static_assert( comd::is_character_like_v<      long double  >);
    static_assert( comd::is_character_like_v<const long double  >);
    static_assert( comd::is_character_like_v<      long double& >);
    static_assert( comd::is_character_like_v<const long double& >);
    static_assert( comd::is_character_like_v<      long double&&>);
    static_assert( comd::is_character_like_v<const long double&&>);

    static_assert( comd::is_character_like_v<      some_char  >);
    static_assert( comd::is_character_like_v<const some_char  >);
    static_assert( comd::is_character_like_v<      some_char& >);
    static_assert( comd::is_character_like_v<const some_char& >);
    static_assert( comd::is_character_like_v<      some_char&&>);
    static_assert( comd::is_character_like_v<const some_char&&>);

    static_assert(!comd::is_character_like_v<      non_char_constr  >);
    static_assert(!comd::is_character_like_v<const non_char_constr  >);
    static_assert(!comd::is_character_like_v<      non_char_constr& >);
    static_assert(!comd::is_character_like_v<const non_char_constr& >);
    static_assert(!comd::is_character_like_v<      non_char_constr&&>);
    static_assert(!comd::is_character_like_v<const non_char_constr&&>);

    static_assert(!comd::is_character_like_v<      non_const_comp_char  >);
    static_assert(!comd::is_character_like_v<const non_const_comp_char  >);
    static_assert(!comd::is_character_like_v<      non_const_comp_char& >);
    static_assert(!comd::is_character_like_v<const non_const_comp_char& >);
    static_assert(!comd::is_character_like_v<      non_const_comp_char&&>);
    static_assert(!comd::is_character_like_v<const non_const_comp_char&&>);

    static_assert(!comd::is_character_like_v<      non_char  >);
    static_assert(!comd::is_character_like_v<const non_char  >);
    static_assert(!comd::is_character_like_v<      non_char& >);
    static_assert(!comd::is_character_like_v<const non_char& >);
    static_assert(!comd::is_character_like_v<      non_char&&>);
    static_assert(!comd::is_character_like_v<const non_char&&>);
}
