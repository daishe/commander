//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/is_string_like.hpp>

#include <boost/test/unit_test.hpp>

#include "character_helpers.hpp"
#include "traversable_helpers.hpp"

#include <array>
#include <string>
#include <string_view>
#include <vector>

BOOST_AUTO_TEST_CASE( is_string_like )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_string_like<bool>::value);
        static_assert(!comd::is_string_like<char>::value);
        static_assert(!comd::is_string_like<int8_t>::value);
        static_assert(!comd::is_string_like<uint8_t>::value);
        static_assert(!comd::is_string_like<int16_t>::value);
        static_assert(!comd::is_string_like<uint16_t>::value);
        static_assert(!comd::is_string_like<char16_t>::value);
        static_assert(!comd::is_string_like<int32_t>::value);
        static_assert(!comd::is_string_like<uint32_t>::value);
        static_assert(!comd::is_string_like<char32_t>::value);
        static_assert(!comd::is_string_like<wchar_t>::value);
        static_assert(!comd::is_string_like<int64_t>::value);
        static_assert(!comd::is_string_like<uint64_t>::value);
        static_assert(!comd::is_string_like<float>::value);
        static_assert(!comd::is_string_like<double>::value);
        static_assert(!comd::is_string_like<long double>::value);
    }

    {
        static_assert( comd::is_string_like<      std::string  >::value);
        static_assert( comd::is_string_like<const std::string  >::value);
        static_assert( comd::is_string_like<      std::string& >::value);
        static_assert( comd::is_string_like<const std::string& >::value);
        static_assert( comd::is_string_like<      std::string&&>::value);
        static_assert( comd::is_string_like<const std::string&&>::value);

        static_assert( comd::is_string_like<      std::wstring  >::value);
        static_assert( comd::is_string_like<const std::wstring  >::value);
        static_assert( comd::is_string_like<      std::wstring& >::value);
        static_assert( comd::is_string_like<const std::wstring& >::value);
        static_assert( comd::is_string_like<      std::wstring&&>::value);
        static_assert( comd::is_string_like<const std::wstring&&>::value);

        static_assert( comd::is_string_like<      std::u16string  >::value);
        static_assert( comd::is_string_like<const std::u16string  >::value);
        static_assert( comd::is_string_like<      std::u16string& >::value);
        static_assert( comd::is_string_like<const std::u16string& >::value);
        static_assert( comd::is_string_like<      std::u16string&&>::value);
        static_assert( comd::is_string_like<const std::u16string&&>::value);

        static_assert( comd::is_string_like<      std::u32string  >::value);
        static_assert( comd::is_string_like<const std::u32string  >::value);
        static_assert( comd::is_string_like<      std::u32string& >::value);
        static_assert( comd::is_string_like<const std::u32string& >::value);
        static_assert( comd::is_string_like<      std::u32string&&>::value);
        static_assert( comd::is_string_like<const std::u32string&&>::value);
    }

    {
        static_assert( comd::is_string_like<      std::string_view  >::value);
        static_assert( comd::is_string_like<const std::string_view  >::value);
        static_assert( comd::is_string_like<      std::string_view& >::value);
        static_assert( comd::is_string_like<const std::string_view& >::value);
        static_assert( comd::is_string_like<      std::string_view&&>::value);
        static_assert( comd::is_string_like<const std::string_view&&>::value);

        static_assert( comd::is_string_like<      std::wstring_view  >::value);
        static_assert( comd::is_string_like<const std::wstring_view  >::value);
        static_assert( comd::is_string_like<      std::wstring_view& >::value);
        static_assert( comd::is_string_like<const std::wstring_view& >::value);
        static_assert( comd::is_string_like<      std::wstring_view&&>::value);
        static_assert( comd::is_string_like<const std::wstring_view&&>::value);

        static_assert( comd::is_string_like<      std::u16string_view  >::value);
        static_assert( comd::is_string_like<const std::u16string_view  >::value);
        static_assert( comd::is_string_like<      std::u16string_view& >::value);
        static_assert( comd::is_string_like<const std::u16string_view& >::value);
        static_assert( comd::is_string_like<      std::u16string_view&&>::value);
        static_assert( comd::is_string_like<const std::u16string_view&&>::value);

        static_assert( comd::is_string_like<      std::u32string_view  >::value);
        static_assert( comd::is_string_like<const std::u32string_view  >::value);
        static_assert( comd::is_string_like<      std::u32string_view& >::value);
        static_assert( comd::is_string_like<const std::u32string_view& >::value);
        static_assert( comd::is_string_like<      std::u32string_view&&>::value);
        static_assert( comd::is_string_like<const std::u32string_view&&>::value);
    }

    {
        static_assert( comd::is_string_like<      std::array<int, 5>  >::value);
        static_assert( comd::is_string_like<const std::array<int, 5>  >::value);
        static_assert( comd::is_string_like<      std::array<int, 5>& >::value);
        static_assert( comd::is_string_like<const std::array<int, 5>& >::value);
        static_assert( comd::is_string_like<      std::array<int, 5>&&>::value);
        static_assert( comd::is_string_like<const std::array<int, 5>&&>::value);

        static_assert( comd::is_string_like<      std::vector<int>  >::value);
        static_assert( comd::is_string_like<const std::vector<int>  >::value);
        static_assert( comd::is_string_like<      std::vector<int>& >::value);
        static_assert( comd::is_string_like<const std::vector<int>& >::value);
        static_assert( comd::is_string_like<      std::vector<int>&&>::value);
        static_assert( comd::is_string_like<const std::vector<int>&&>::value);
    }

    {
        static_assert( comd::is_string_like<      std::vector<some_char>  >::value);
        static_assert( comd::is_string_like<const std::vector<some_char>  >::value);
        static_assert( comd::is_string_like<      std::vector<some_char>& >::value);
        static_assert( comd::is_string_like<const std::vector<some_char>& >::value);
        static_assert( comd::is_string_like<      std::vector<some_char>&&>::value);
        static_assert( comd::is_string_like<const std::vector<some_char>&&>::value);

        static_assert(!comd::is_string_like<      std::vector<non_char_constr>  >::value);
        static_assert(!comd::is_string_like<const std::vector<non_char_constr>  >::value);
        static_assert(!comd::is_string_like<      std::vector<non_char_constr>& >::value);
        static_assert(!comd::is_string_like<const std::vector<non_char_constr>& >::value);
        static_assert(!comd::is_string_like<      std::vector<non_char_constr>&&>::value);
        static_assert(!comd::is_string_like<const std::vector<non_char_constr>&&>::value);

        static_assert(!comd::is_string_like<      std::vector<non_const_comp_char>  >::value);
        static_assert(!comd::is_string_like<const std::vector<non_const_comp_char>  >::value);
        static_assert(!comd::is_string_like<      std::vector<non_const_comp_char>& >::value);
        static_assert(!comd::is_string_like<const std::vector<non_const_comp_char>& >::value);
        static_assert(!comd::is_string_like<      std::vector<non_const_comp_char>&&>::value);
        static_assert(!comd::is_string_like<const std::vector<non_const_comp_char>&&>::value);

        static_assert(!comd::is_string_like<      std::vector<non_char>  >::value);
        static_assert(!comd::is_string_like<const std::vector<non_char>  >::value);
        static_assert(!comd::is_string_like<      std::vector<non_char>& >::value);
        static_assert(!comd::is_string_like<const std::vector<non_char>& >::value);
        static_assert(!comd::is_string_like<      std::vector<non_char>&&>::value);
        static_assert(!comd::is_string_like<const std::vector<non_char>&&>::value);
    }

    {
        static_assert( comd::is_string_like<      bound_array  >::value);
        static_assert( comd::is_string_like<const bound_array  >::value);
        static_assert( comd::is_string_like<      bound_array& >::value);
        static_assert( comd::is_string_like<const bound_array& >::value);
        static_assert( comd::is_string_like<      bound_array&&>::value);
        static_assert( comd::is_string_like<const bound_array&&>::value);

        static_assert(!comd::is_string_like<      unbound_array  >::value);
        static_assert(!comd::is_string_like<const unbound_array  >::value);
        static_assert(!comd::is_string_like<      unbound_array& >::value);
        static_assert(!comd::is_string_like<const unbound_array& >::value);
        static_assert(!comd::is_string_like<      unbound_array&&>::value);
        static_assert(!comd::is_string_like<const unbound_array&&>::value);
    }

    {
        static_assert( comd::is_string_like<      container_begin_end  >::value);
        static_assert(!comd::is_string_like<const container_begin_end  >::value);
        static_assert( comd::is_string_like<      container_begin_end& >::value);
        static_assert(!comd::is_string_like<const container_begin_end& >::value);
        static_assert( comd::is_string_like<      container_begin_end&&>::value);
        static_assert(!comd::is_string_like<const container_begin_end&&>::value);

        static_assert( comd::is_string_like<      container_cbegin_cend  >::value);
        static_assert( comd::is_string_like<const container_cbegin_cend  >::value);
        static_assert( comd::is_string_like<      container_cbegin_cend& >::value);
        static_assert( comd::is_string_like<const container_cbegin_cend& >::value);
        static_assert( comd::is_string_like<      container_cbegin_cend&&>::value);
        static_assert( comd::is_string_like<const container_cbegin_cend&&>::value);

        static_assert(!comd::is_string_like<      container_begin  >::value);
        static_assert(!comd::is_string_like<const container_begin  >::value);
        static_assert(!comd::is_string_like<      container_begin& >::value);
        static_assert(!comd::is_string_like<const container_begin& >::value);
        static_assert(!comd::is_string_like<      container_begin&&>::value);
        static_assert(!comd::is_string_like<const container_begin&&>::value);

        static_assert(!comd::is_string_like<      container_cbegin  >::value);
        static_assert(!comd::is_string_like<const container_cbegin  >::value);
        static_assert(!comd::is_string_like<      container_cbegin& >::value);
        static_assert(!comd::is_string_like<const container_cbegin& >::value);
        static_assert(!comd::is_string_like<      container_cbegin&&>::value);
        static_assert(!comd::is_string_like<const container_cbegin&&>::value);

        static_assert(!comd::is_string_like<      container_end  >::value);
        static_assert(!comd::is_string_like<const container_end  >::value);
        static_assert(!comd::is_string_like<      container_end& >::value);
        static_assert(!comd::is_string_like<const container_end& >::value);
        static_assert(!comd::is_string_like<      container_end&&>::value);
        static_assert(!comd::is_string_like<const container_end&&>::value);

        static_assert(!comd::is_string_like<      container_cend  >::value);
        static_assert(!comd::is_string_like<const container_cend  >::value);
        static_assert(!comd::is_string_like<      container_cend& >::value);
        static_assert(!comd::is_string_like<const container_cend& >::value);
        static_assert(!comd::is_string_like<      container_cend&&>::value);
        static_assert(!comd::is_string_like<const container_cend&&>::value);
    }
}

BOOST_AUTO_TEST_CASE( is_string_like_v )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_string_like_v<bool>);
        static_assert(!comd::is_string_like_v<char>);
        static_assert(!comd::is_string_like_v<int8_t>);
        static_assert(!comd::is_string_like_v<uint8_t>);
        static_assert(!comd::is_string_like_v<int16_t>);
        static_assert(!comd::is_string_like_v<uint16_t>);
        static_assert(!comd::is_string_like_v<char16_t>);
        static_assert(!comd::is_string_like_v<int32_t>);
        static_assert(!comd::is_string_like_v<uint32_t>);
        static_assert(!comd::is_string_like_v<char32_t>);
        static_assert(!comd::is_string_like_v<wchar_t>);
        static_assert(!comd::is_string_like_v<int64_t>);
        static_assert(!comd::is_string_like_v<uint64_t>);
        static_assert(!comd::is_string_like_v<float>);
        static_assert(!comd::is_string_like_v<double>);
        static_assert(!comd::is_string_like_v<long double>);
    }

    {
        static_assert( comd::is_string_like_v<      std::string  >);
        static_assert( comd::is_string_like_v<const std::string  >);
        static_assert( comd::is_string_like_v<      std::string& >);
        static_assert( comd::is_string_like_v<const std::string& >);
        static_assert( comd::is_string_like_v<      std::string&&>);
        static_assert( comd::is_string_like_v<const std::string&&>);

        static_assert( comd::is_string_like_v<      std::wstring  >);
        static_assert( comd::is_string_like_v<const std::wstring  >);
        static_assert( comd::is_string_like_v<      std::wstring& >);
        static_assert( comd::is_string_like_v<const std::wstring& >);
        static_assert( comd::is_string_like_v<      std::wstring&&>);
        static_assert( comd::is_string_like_v<const std::wstring&&>);

        static_assert( comd::is_string_like_v<      std::u16string  >);
        static_assert( comd::is_string_like_v<const std::u16string  >);
        static_assert( comd::is_string_like_v<      std::u16string& >);
        static_assert( comd::is_string_like_v<const std::u16string& >);
        static_assert( comd::is_string_like_v<      std::u16string&&>);
        static_assert( comd::is_string_like_v<const std::u16string&&>);

        static_assert( comd::is_string_like_v<      std::u32string  >);
        static_assert( comd::is_string_like_v<const std::u32string  >);
        static_assert( comd::is_string_like_v<      std::u32string& >);
        static_assert( comd::is_string_like_v<const std::u32string& >);
        static_assert( comd::is_string_like_v<      std::u32string&&>);
        static_assert( comd::is_string_like_v<const std::u32string&&>);
    }

    {
        static_assert( comd::is_string_like_v<      std::string_view  >);
        static_assert( comd::is_string_like_v<const std::string_view  >);
        static_assert( comd::is_string_like_v<      std::string_view& >);
        static_assert( comd::is_string_like_v<const std::string_view& >);
        static_assert( comd::is_string_like_v<      std::string_view&&>);
        static_assert( comd::is_string_like_v<const std::string_view&&>);

        static_assert( comd::is_string_like_v<      std::wstring_view  >);
        static_assert( comd::is_string_like_v<const std::wstring_view  >);
        static_assert( comd::is_string_like_v<      std::wstring_view& >);
        static_assert( comd::is_string_like_v<const std::wstring_view& >);
        static_assert( comd::is_string_like_v<      std::wstring_view&&>);
        static_assert( comd::is_string_like_v<const std::wstring_view&&>);

        static_assert( comd::is_string_like_v<      std::u16string_view  >);
        static_assert( comd::is_string_like_v<const std::u16string_view  >);
        static_assert( comd::is_string_like_v<      std::u16string_view& >);
        static_assert( comd::is_string_like_v<const std::u16string_view& >);
        static_assert( comd::is_string_like_v<      std::u16string_view&&>);
        static_assert( comd::is_string_like_v<const std::u16string_view&&>);

        static_assert( comd::is_string_like_v<      std::u32string_view  >);
        static_assert( comd::is_string_like_v<const std::u32string_view  >);
        static_assert( comd::is_string_like_v<      std::u32string_view& >);
        static_assert( comd::is_string_like_v<const std::u32string_view& >);
        static_assert( comd::is_string_like_v<      std::u32string_view&&>);
        static_assert( comd::is_string_like_v<const std::u32string_view&&>);
    }

    {
        static_assert( comd::is_string_like_v<      std::array<int, 5>  >);
        static_assert( comd::is_string_like_v<const std::array<int, 5>  >);
        static_assert( comd::is_string_like_v<      std::array<int, 5>& >);
        static_assert( comd::is_string_like_v<const std::array<int, 5>& >);
        static_assert( comd::is_string_like_v<      std::array<int, 5>&&>);
        static_assert( comd::is_string_like_v<const std::array<int, 5>&&>);

        static_assert( comd::is_string_like_v<      std::vector<int>  >);
        static_assert( comd::is_string_like_v<const std::vector<int>  >);
        static_assert( comd::is_string_like_v<      std::vector<int>& >);
        static_assert( comd::is_string_like_v<const std::vector<int>& >);
        static_assert( comd::is_string_like_v<      std::vector<int>&&>);
        static_assert( comd::is_string_like_v<const std::vector<int>&&>);
    }

    {
        static_assert( comd::is_string_like_v<      std::vector<some_char>  >);
        static_assert( comd::is_string_like_v<const std::vector<some_char>  >);
        static_assert( comd::is_string_like_v<      std::vector<some_char>& >);
        static_assert( comd::is_string_like_v<const std::vector<some_char>& >);
        static_assert( comd::is_string_like_v<      std::vector<some_char>&&>);
        static_assert( comd::is_string_like_v<const std::vector<some_char>&&>);

        static_assert(!comd::is_string_like_v<      std::vector<non_char_constr>  >);
        static_assert(!comd::is_string_like_v<const std::vector<non_char_constr>  >);
        static_assert(!comd::is_string_like_v<      std::vector<non_char_constr>& >);
        static_assert(!comd::is_string_like_v<const std::vector<non_char_constr>& >);
        static_assert(!comd::is_string_like_v<      std::vector<non_char_constr>&&>);
        static_assert(!comd::is_string_like_v<const std::vector<non_char_constr>&&>);

        static_assert(!comd::is_string_like_v<      std::vector<non_const_comp_char>  >);
        static_assert(!comd::is_string_like_v<const std::vector<non_const_comp_char>  >);
        static_assert(!comd::is_string_like_v<      std::vector<non_const_comp_char>& >);
        static_assert(!comd::is_string_like_v<const std::vector<non_const_comp_char>& >);
        static_assert(!comd::is_string_like_v<      std::vector<non_const_comp_char>&&>);
        static_assert(!comd::is_string_like_v<const std::vector<non_const_comp_char>&&>);

        static_assert(!comd::is_string_like_v<      std::vector<non_char>  >);
        static_assert(!comd::is_string_like_v<const std::vector<non_char>  >);
        static_assert(!comd::is_string_like_v<      std::vector<non_char>& >);
        static_assert(!comd::is_string_like_v<const std::vector<non_char>& >);
        static_assert(!comd::is_string_like_v<      std::vector<non_char>&&>);
        static_assert(!comd::is_string_like_v<const std::vector<non_char>&&>);
    }

    {
        static_assert( comd::is_string_like_v<      bound_array  >);
        static_assert( comd::is_string_like_v<const bound_array  >);
        static_assert( comd::is_string_like_v<      bound_array& >);
        static_assert( comd::is_string_like_v<const bound_array& >);
        static_assert( comd::is_string_like_v<      bound_array&&>);
        static_assert( comd::is_string_like_v<const bound_array&&>);

        static_assert(!comd::is_string_like_v<      unbound_array  >);
        static_assert(!comd::is_string_like_v<const unbound_array  >);
        static_assert(!comd::is_string_like_v<      unbound_array& >);
        static_assert(!comd::is_string_like_v<const unbound_array& >);
        static_assert(!comd::is_string_like_v<      unbound_array&&>);
        static_assert(!comd::is_string_like_v<const unbound_array&&>);
    }

    {
        static_assert( comd::is_string_like_v<      container_begin_end  >);
        static_assert(!comd::is_string_like_v<const container_begin_end  >);
        static_assert( comd::is_string_like_v<      container_begin_end& >);
        static_assert(!comd::is_string_like_v<const container_begin_end& >);
        static_assert( comd::is_string_like_v<      container_begin_end&&>);
        static_assert(!comd::is_string_like_v<const container_begin_end&&>);

        static_assert( comd::is_string_like_v<      container_cbegin_cend  >);
        static_assert( comd::is_string_like_v<const container_cbegin_cend  >);
        static_assert( comd::is_string_like_v<      container_cbegin_cend& >);
        static_assert( comd::is_string_like_v<const container_cbegin_cend& >);
        static_assert( comd::is_string_like_v<      container_cbegin_cend&&>);
        static_assert( comd::is_string_like_v<const container_cbegin_cend&&>);

        static_assert(!comd::is_string_like_v<      container_begin  >);
        static_assert(!comd::is_string_like_v<const container_begin  >);
        static_assert(!comd::is_string_like_v<      container_begin& >);
        static_assert(!comd::is_string_like_v<const container_begin& >);
        static_assert(!comd::is_string_like_v<      container_begin&&>);
        static_assert(!comd::is_string_like_v<const container_begin&&>);

        static_assert(!comd::is_string_like_v<      container_cbegin  >);
        static_assert(!comd::is_string_like_v<const container_cbegin  >);
        static_assert(!comd::is_string_like_v<      container_cbegin& >);
        static_assert(!comd::is_string_like_v<const container_cbegin& >);
        static_assert(!comd::is_string_like_v<      container_cbegin&&>);
        static_assert(!comd::is_string_like_v<const container_cbegin&&>);

        static_assert(!comd::is_string_like_v<      container_end  >);
        static_assert(!comd::is_string_like_v<const container_end  >);
        static_assert(!comd::is_string_like_v<      container_end& >);
        static_assert(!comd::is_string_like_v<const container_end& >);
        static_assert(!comd::is_string_like_v<      container_end&&>);
        static_assert(!comd::is_string_like_v<const container_end&&>);

        static_assert(!comd::is_string_like_v<      container_cend  >);
        static_assert(!comd::is_string_like_v<const container_cend  >);
        static_assert(!comd::is_string_like_v<      container_cend& >);
        static_assert(!comd::is_string_like_v<const container_cend& >);
        static_assert(!comd::is_string_like_v<      container_cend&&>);
        static_assert(!comd::is_string_like_v<const container_cend&&>);
    }
}
