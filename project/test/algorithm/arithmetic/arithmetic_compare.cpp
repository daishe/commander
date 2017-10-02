//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include "arithmetic_helpers.hpp"

#include <tuple>
#include <type_traits>

BOOST_AUTO_TEST_CASE( arithmetic_compare )
{
    namespace com  = commander;
    namespace comd = commander::detail;

    using schar8  = std::make_signed_t<char>;     using uchar8  = std::make_unsigned_t<char>;
    using schar16 = std::make_signed_t<char16_t>; using uchar16 = std::make_unsigned_t<char16_t>;
    using schar32 = std::make_signed_t<char32_t>; using uchar32 = std::make_unsigned_t<char32_t>;
    using swchar  = std::make_signed_t<wchar_t>;  using uwchar  = std::make_unsigned_t<wchar_t>;

    const auto non_arithmetic_tuple = std::make_tuple(non_arithmetic_true(), non_arithmetic_false());
    const auto int_tuple = std::make_tuple(int(-5), int(-1), int(0), int(1), int(5));
    const auto float_tuple = std::make_tuple(float(-5), float(-1), float(0), float(1), float(5));
    const auto char_tuple = std::make_tuple(
        sc<schar8>(sc<char>('a')),      sc<uchar8>(sc<char>('a')),
        sc<schar16>(sc<char16_t>('a')), sc<uchar16>(sc<char16_t>('a')),
        sc<schar32>(sc<char32_t>('a')), sc<uchar32>(sc<char32_t>('a')),
        sc<swchar>(sc<wchar_t>('a')),   sc<uwchar>(sc<wchar_t>('a'))
    );

    const auto bool_limits_tuple = std::make_tuple(true, false);
    const auto signed_integral_limits_tuple = std::make_tuple(
        nl<int8_t>::max(),  nl<int8_t>::lowest(),
        nl<int16_t>::max(), nl<int16_t>::lowest(),
        nl<int32_t>::max(), nl<int32_t>::lowest(),
        nl<int64_t>::max(), nl<int64_t>::lowest()
    );
    const auto unsigned_integral_limits_tuple = std::make_tuple(
        nl<uint8_t>::max(),  nl<uint8_t>::lowest(),
        nl<uint16_t>::max(), nl<uint16_t>::lowest(),
        nl<uint32_t>::max(), nl<uint32_t>::lowest(),
        nl<uint64_t>::max(), nl<uint64_t>::lowest()
    );
    const auto floating_point_limits_tuple = std::make_tuple(
        nl<float>::max(),       nl<float>::lowest(),
        nl<double>::max(),      nl<double>::lowest(),
        nl<long double>::max(), nl<long double>::lowest()
    );

    {
        com::tuple_visit(
            [&](const auto& non_arithmetic) {
                size_t count = 0;
                com::tuple_visit(
                    [&](const auto& v) { count += comd::arithmetic_compare(non_arithmetic, v) ? 1 : 0; },
                    non_arithmetic_tuple, int_tuple, float_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
                );
                BOOST_CHECK(count == 0);
            },
            non_arithmetic_tuple
        );
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(int_tuple), std::get< 0>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(int_tuple), std::get< 0>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(int_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(int_tuple), std::get< 1>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(int_tuple), std::get< 1>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(int_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(int_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 2>(int_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(int_tuple), std::get< 3>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(int_tuple), std::get< 3>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(int_tuple), std::get< 0>(bool_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 3>(int_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 3);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(int_tuple), std::get< 4>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(int_tuple), std::get< 4>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 4>(int_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(float_tuple), std::get< 0>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(float_tuple), std::get< 0>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(float_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(float_tuple), std::get< 1>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(float_tuple), std::get< 1>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(float_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(float_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 2>(float_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(float_tuple), std::get< 3>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(float_tuple), std::get< 3>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(float_tuple), std::get< 0>(bool_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 3>(float_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 3);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(float_tuple), std::get< 4>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(float_tuple), std::get< 4>(float_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 4>(float_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 2);
        }
    }

    {
        com::tuple_visit(
            [&](const auto& character) {
                BOOST_CHECK(com::tuple_visit_conjunction(
                    [&](const auto& v) -> bool { return comd::arithmetic_compare(character, v); },
                    char_tuple
                ) == true);

                size_t count = 0;
                com::tuple_visit(
                    [&](const auto& v) { count += comd::arithmetic_compare(character, v) ? 1 : 0; },
                    non_arithmetic_tuple, int_tuple, float_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
                );
                BOOST_CHECK(count == 0);
            },
            char_tuple
        );
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(bool_limits_tuple), std::get< 3>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(bool_limits_tuple), std::get< 3>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(bool_limits_tuple), std::get< 0>(bool_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(bool_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 3);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(bool_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(signed_integral_limits_tuple), std::get< 0>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(signed_integral_limits_tuple), std::get< 1>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(signed_integral_limits_tuple), std::get< 2>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 2>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(signed_integral_limits_tuple), std::get< 3>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 3>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(signed_integral_limits_tuple), std::get< 4>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 4>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(signed_integral_limits_tuple), std::get< 5>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 5>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 6>(signed_integral_limits_tuple), std::get< 6>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 6>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(signed_integral_limits_tuple), std::get< 7>(signed_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 7>(signed_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(unsigned_integral_limits_tuple), std::get< 0>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(unsigned_integral_limits_tuple), std::get< 2>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 2>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 3>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(unsigned_integral_limits_tuple), std::get< 4>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 4>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 5>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 6>(unsigned_integral_limits_tuple), std::get< 6>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 6>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 2>(int_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 2>(float_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 1>(bool_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 1>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 3>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 5>(unsigned_integral_limits_tuple)) == true);
            BOOST_CHECK(comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), std::get< 7>(unsigned_integral_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 7>(unsigned_integral_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 7);
        }
    }

    {
        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 0>(floating_point_limits_tuple), std::get< 0>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 0>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 1>(floating_point_limits_tuple), std::get< 1>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 1>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 2>(floating_point_limits_tuple), std::get< 2>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 2>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 3>(floating_point_limits_tuple), std::get< 3>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 3>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 4>(floating_point_limits_tuple), std::get< 4>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 4>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }

        {
            BOOST_CHECK(comd::arithmetic_compare(std::get< 5>(floating_point_limits_tuple), std::get< 5>(floating_point_limits_tuple)) == true);

            size_t count = 0;
            com::tuple_visit(
                [&](const auto& v) { count += comd::arithmetic_compare(std::get< 5>(floating_point_limits_tuple), v) ? 1 : 0; },
                non_arithmetic_tuple, int_tuple, float_tuple, char_tuple, bool_limits_tuple, signed_integral_limits_tuple, unsigned_integral_limits_tuple, floating_point_limits_tuple
            );
            BOOST_CHECK(count == 1);
        }
    }
}
