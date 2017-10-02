//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include <type_traits>

// template <typename ResChar, typename FirstChar>
// ResChar make_char(FirstChar c0)
// {
//     static_assert(sizeof(FirstChar) == 1);

//     return ResChar(c0);
// }

// template <typename ResChar, typename FirstChar, typename SecondChar, typename... Chars>
// ResChar make_char(FirstChar c0, SecondChar c1, Chars... cs)
// {
//     static_assert(sizeof(FirstChar)  == 1);
//     static_assert(sizeof(SecondChar) == 1);

//     ResChar res = c0;

//     res <<= (sizeof...(cs) + 1) * 8;
//     res |= make_char<ResChar>(c1, cs...);

//     return res;
// }

template <typename ResChar, typename C1, typename C2, typename C3, typename C4>
ResChar make_char(C1 c1, C2 c2, C3 c3, C4 c4)
{
    uint8_t b1 = static_cast<uint8_t>(c1 & 0xff);
    uint8_t b2 = static_cast<uint8_t>(c2 & 0xff);
    uint8_t b3 = static_cast<uint8_t>(c3 & 0xff);
    uint8_t b4 = static_cast<uint8_t>(c4 & 0xff);

    ResChar res = 0ull;

    res <<= 8;
    res |= b1;
    if (sizeof(res) == 1)
        return res;

    res <<= 8;
    res |= b2;
    if (sizeof(res) == 2)
        return res;

    res <<= 8;
    res |= b3;
    if (sizeof(res) == 3)
        return res;

    res <<= 8;
    res |= b4;
    if (sizeof(res) == 4)
        return res;

    return res;
}

BOOST_AUTO_TEST_CASE( compare_characters )
{
    namespace com = commander;

    // c -> *
    {
        // c -> c
        {
            BOOST_CHECK(com::compare_characters('a', 'a') == true);
            BOOST_CHECK(com::compare_characters('a', 'b') == false);

            BOOST_CHECK(com::compare_characters('\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters('\0', make_char<char>(0x80, 0, 0, 0)) == false);

            BOOST_CHECK(com::compare_characters(make_char<char>(0, 0, 0, 0),    '\0') == true);
            BOOST_CHECK(com::compare_characters(make_char<char>(0x80, 0, 0, 0), '\0') == false);
        }

        // c -> L
        {
            BOOST_CHECK(com::compare_characters('a', L'a') == true);
            BOOST_CHECK(com::compare_characters('a', L'b') == false);

            BOOST_CHECK(com::compare_characters('\0', make_char<wchar_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters('\0', make_char<wchar_t>(0x80, 0, 0, 0)) == false);
        }

        // c -> u8
        {
            BOOST_CHECK(com::compare_characters('a', u8'a') == true);
            BOOST_CHECK(com::compare_characters('a', u8'b') == false);
        }

        // c -> u
        {
            BOOST_CHECK(com::compare_characters('a', u'a') == true);
            BOOST_CHECK(com::compare_characters('a', u'b') == false);

            BOOST_CHECK(com::compare_characters('\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters('\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);
        }

        // c -> U
        {
            BOOST_CHECK(com::compare_characters('a', U'a') == true);
            BOOST_CHECK(com::compare_characters('a', U'b') == false);
            BOOST_CHECK(com::compare_characters(U'b', 'a') == false);

            BOOST_CHECK(com::compare_characters('\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters('\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);
        }
    }

    // L -> *
    {
        // L -> c
        {
            BOOST_CHECK(com::compare_characters(L'a', 'a') == true);
            BOOST_CHECK(com::compare_characters(L'a', 'b') == false);

            BOOST_CHECK(com::compare_characters(L'\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(L'\0', make_char<char>(0x80, 0, 0, 0)) == false);

        }

        // L -> L
        {
            BOOST_CHECK(com::compare_characters(L'a', L'a') == true);
            BOOST_CHECK(com::compare_characters(L'a', L'b') == false);

            BOOST_CHECK(com::compare_characters(L'\0', make_char<wchar_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(L'\0', make_char<wchar_t>(0x80, 0, 0, 0)) == false);

            BOOST_CHECK(com::compare_characters(make_char<wchar_t>(0, 0, 0, 0),    L'\0') == true);
            BOOST_CHECK(com::compare_characters(make_char<wchar_t>(0x80, 0, 0, 0), L'\0') == false);
        }

        // L -> u8
        {
            BOOST_CHECK(com::compare_characters(L'a', u8'a') == true);
            BOOST_CHECK(com::compare_characters(L'a', u8'b') == false);
        }

        // L -> u
        {
            BOOST_CHECK(com::compare_characters(L'a', u'a') == true);
            BOOST_CHECK(com::compare_characters(L'a', u'b') == false);

            BOOST_CHECK(com::compare_characters(L'\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(L'\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);
        }

        // L -> U
        {
            BOOST_CHECK(com::compare_characters(L'a', U'a') == true);
            BOOST_CHECK(com::compare_characters(L'a', U'b') == false);

            BOOST_CHECK(com::compare_characters(L'\0', make_char<char32_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(L'\0', make_char<char32_t>(0x80, 0, 0, 0)) == false);
        }
    }

    // u8 -> *
    {
        // u8 -> c
        {
            BOOST_CHECK(com::compare_characters(u8'a', 'a') == true);
            BOOST_CHECK(com::compare_characters(u8'a', 'b') == false);

            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char>(0x80, 0, 0, 0)) == false);
        }

        // u8 -> L
        {
            BOOST_CHECK(com::compare_characters(u8'a', L'a') == true);
            BOOST_CHECK(com::compare_characters(u8'a', L'b') == false);

            BOOST_CHECK(com::compare_characters(u8'\0', make_char<wchar_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u8'\0', make_char<wchar_t>(0x80, 0, 0, 0)) == false);
        }

        // u8 -> u8
        {
            BOOST_CHECK(com::compare_characters(u8'a', u8'a') == true);
            BOOST_CHECK(com::compare_characters(u8'a', u8'b') == false);

            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char>(0x80, 0, 0, 0)) == false);

            BOOST_CHECK(com::compare_characters(make_char<char>(0, 0, 0, 0),    u8'\0') == true);
            BOOST_CHECK(com::compare_characters(make_char<char>(0x80, 0, 0, 0), u8'\0') == false);
        }

        // u8 -> u
        {
            BOOST_CHECK(com::compare_characters(u8'a', u'a') == true);
            BOOST_CHECK(com::compare_characters(u8'a', u'b') == false);

            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);
        }

        // u8 -> U
        {
            BOOST_CHECK(com::compare_characters(u8'a', U'a') == true);
            BOOST_CHECK(com::compare_characters(u8'a', U'b') == false);

            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char32_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u8'\0', make_char<char32_t>(0x80, 0, 0, 0)) == false);
        }
    }

    // u -> *
    {
        // u -> c
        {
            BOOST_CHECK(com::compare_characters(u'a', 'a') == true);
            BOOST_CHECK(com::compare_characters(u'a', 'b') == false);

            BOOST_CHECK(com::compare_characters(u'\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u'\0', make_char<char>(0x80, 0, 0, 0)) == false);
        }

        // u -> L
        {
            BOOST_CHECK(com::compare_characters(u'a', L'a') == true);
            BOOST_CHECK(com::compare_characters(u'a', L'b') == false);

            BOOST_CHECK(com::compare_characters(u'\0', make_char<wchar_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u'\0', make_char<wchar_t>(0x80, 0, 0, 0)) == false);
        }

        // u -> u8
        {
            BOOST_CHECK(com::compare_characters(u'a', u8'a') == true);
            BOOST_CHECK(com::compare_characters(u'a', u8'b') == false);
        }

        // u -> u
        {
            BOOST_CHECK(com::compare_characters(u'a', u'a') == true);
            BOOST_CHECK(com::compare_characters(u'a', u'b') == false);

            BOOST_CHECK(com::compare_characters(u'\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u'\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);

            BOOST_CHECK(com::compare_characters(make_char<char16_t>(0, 0, 0, 0),    u'\0') == true);
            BOOST_CHECK(com::compare_characters(make_char<char16_t>(0x80, 0, 0, 0), u'\0') == false);
        }

        // u -> U
        {
            BOOST_CHECK(com::compare_characters(u'a', U'a') == true);
            BOOST_CHECK(com::compare_characters(u'a', U'b') == false);

            BOOST_CHECK(com::compare_characters(u'\0', make_char<char32_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(u'\0', make_char<char32_t>(0x80, 0, 0, 0)) == false);
        }
    }

    // U -> *
    {
        // U -> c
        {
            BOOST_CHECK(com::compare_characters(U'a', 'a') == true);
            BOOST_CHECK(com::compare_characters(U'a', 'b') == false);

            BOOST_CHECK(com::compare_characters(U'\0', make_char<char>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(U'\0', make_char<char>(0x80, 0, 0, 0)) == false);
        }

        // U -> L
        {
            BOOST_CHECK(com::compare_characters(U'a', L'a') == true);
            BOOST_CHECK(com::compare_characters(U'a', L'b') == false);

            BOOST_CHECK(com::compare_characters(U'\0', make_char<wchar_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(U'\0', make_char<wchar_t>(0x80, 0, 0, 0)) == false);
        }

        // U -> u8
        {
            BOOST_CHECK(com::compare_characters(U'a', u8'a') == true);
            BOOST_CHECK(com::compare_characters(U'a', u8'b') == false);
        }

        // U -> u
        {
            BOOST_CHECK(com::compare_characters(U'a', u'a') == true);
            BOOST_CHECK(com::compare_characters(U'a', u'b') == false);

            BOOST_CHECK(com::compare_characters(U'\0', make_char<char16_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(U'\0', make_char<char16_t>(0x80, 0, 0, 0)) == false);
        }

        // U -> U
        {
            BOOST_CHECK(com::compare_characters(U'a', U'a') == true);
            BOOST_CHECK(com::compare_characters(U'a', U'b') == false);

            BOOST_CHECK(com::compare_characters(U'\0', make_char<char32_t>(0, 0, 0, 0))    == true);
            BOOST_CHECK(com::compare_characters(U'\0', make_char<char32_t>(0x80, 0, 0, 0)) == false);

            BOOST_CHECK(com::compare_characters(make_char<char32_t>(0, 0, 0, 0),    U'\0') == true);
            BOOST_CHECK(com::compare_characters(make_char<char32_t>(0x80, 0, 0, 0), U'\0') == false);
        }
    }
}
