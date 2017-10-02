//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/pack_position.hpp>

#include <boost/test/unit_test.hpp>

#include <commander/algorithm.hpp>

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>

#define PP_MSG(pack) "{" << (pack).is_first << ',' << (pack).exact << ',' << (pack).is_last << "}"
#define PP_OP_PP_MSG(lhs, op, rhs) PP_MSG(lhs) << " " << (op) << " " << PP_MSG(rhs)

template <typename It, typename Callback, typename... Indexes>
void each_except(It begin, It end, Callback callback, Indexes... indexes)
{
    size_t pos = size_t(-1);
    std::for_each(begin, end, [&](const auto& v) {
        if (!commander::compare_disjunction(++pos, size_t(-1), size_t(indexes)...))
            callback(v);
    });
}

template <typename It, typename Callback, typename... Indexes>
void each_of(It begin, It end, Callback callback, Indexes... indexes)
{
    size_t pos = size_t(-1);
    std::for_each(begin, end, [&](const auto& v) {
        if (commander::compare_disjunction(++pos, size_t(-1), size_t(indexes)...))
            callback(v);
    });
}

BOOST_AUTO_TEST_CASE( pack_position )
{
    namespace com = commander;

    std::vector<com::pack_position<size_t>> pos;

    pos.push_back(com::pack_position<size_t> {false, 0, false});
    pos.push_back(com::pack_position<size_t> {false, 0, true });
    pos.push_back(com::pack_position<size_t> {true,  0, false});
    pos.push_back(com::pack_position<size_t> {true,  0, true });

    pos.push_back(com::pack_position<size_t> {false, 1, false});
    pos.push_back(com::pack_position<size_t> {false, 1, true });
    pos.push_back(com::pack_position<size_t> {true,  1, false});
    pos.push_back(com::pack_position<size_t> {true,  1, true });

    pos.push_back(com::pack_position<size_t> {false, 2, false});
    pos.push_back(com::pack_position<size_t> {false, 2, true });
    pos.push_back(com::pack_position<size_t> {true,  2, false});
    pos.push_back(com::pack_position<size_t> {true,  2, true });

    pos.push_back(com::pack_position<size_t> {false, 3, false});
    pos.push_back(com::pack_position<size_t> {false, 3, true });
    pos.push_back(com::pack_position<size_t> {true,  3, false});
    pos.push_back(com::pack_position<size_t> {true,  3, true });

    {
        static_assert(std::is_same_v<int, com::pack_position<int>::size_type>);
        static_assert(std::is_same_v<size_t, com::pack_position<size_t>::size_type>);
    }

    {
        BOOST_CHECK(pos.at( 0).is_first == false); BOOST_CHECK(pos.at( 0).exact == 0); BOOST_CHECK(pos.at( 0).is_last == false);
        BOOST_CHECK(pos.at( 1).is_first == false); BOOST_CHECK(pos.at( 1).exact == 0); BOOST_CHECK(pos.at( 1).is_last == true);
        BOOST_CHECK(pos.at( 2).is_first == true);  BOOST_CHECK(pos.at( 2).exact == 0); BOOST_CHECK(pos.at( 2).is_last == false);
        BOOST_CHECK(pos.at( 3).is_first == true);  BOOST_CHECK(pos.at( 3).exact == 0); BOOST_CHECK(pos.at( 3).is_last == true);
        BOOST_CHECK(pos.at( 4).is_first == false); BOOST_CHECK(pos.at( 4).exact == 1); BOOST_CHECK(pos.at( 4).is_last == false);
        BOOST_CHECK(pos.at( 5).is_first == false); BOOST_CHECK(pos.at( 5).exact == 1); BOOST_CHECK(pos.at( 5).is_last == true);
        BOOST_CHECK(pos.at( 6).is_first == true);  BOOST_CHECK(pos.at( 6).exact == 1); BOOST_CHECK(pos.at( 6).is_last == false);
        BOOST_CHECK(pos.at( 7).is_first == true);  BOOST_CHECK(pos.at( 7).exact == 1); BOOST_CHECK(pos.at( 7).is_last == true);
        BOOST_CHECK(pos.at( 8).is_first == false); BOOST_CHECK(pos.at( 8).exact == 2); BOOST_CHECK(pos.at( 8).is_last == false);
        BOOST_CHECK(pos.at( 9).is_first == false); BOOST_CHECK(pos.at( 9).exact == 2); BOOST_CHECK(pos.at( 9).is_last == true);
        BOOST_CHECK(pos.at(10).is_first == true);  BOOST_CHECK(pos.at(10).exact == 2); BOOST_CHECK(pos.at(10).is_last == false);
        BOOST_CHECK(pos.at(11).is_first == true);  BOOST_CHECK(pos.at(11).exact == 2); BOOST_CHECK(pos.at(11).is_last == true);
        BOOST_CHECK(pos.at(12).is_first == false); BOOST_CHECK(pos.at(12).exact == 3); BOOST_CHECK(pos.at(12).is_last == false);
        BOOST_CHECK(pos.at(13).is_first == false); BOOST_CHECK(pos.at(13).exact == 3); BOOST_CHECK(pos.at(13).is_last == true);
        BOOST_CHECK(pos.at(14).is_first == true);  BOOST_CHECK(pos.at(14).exact == 3); BOOST_CHECK(pos.at(14).is_last == false);
        BOOST_CHECK(pos.at(15).is_first == true);  BOOST_CHECK(pos.at(15).exact == 3); BOOST_CHECK(pos.at(15).is_last == true);
    }

    {
        for (size_t cur_idx = 0; cur_idx < 4; ++cur_idx) {
            const auto& cur = pos.at(cur_idx);
            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == true,  PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == false, PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == false, PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == true,  PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == false, PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == true,  PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == false, PP_OP_PP_MSG(cur, "<=", p)); });
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == true,  PP_OP_PP_MSG(cur, "<=", p)); });

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == true,  PP_OP_PP_MSG(cur, ">",  p)); });
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == false, PP_OP_PP_MSG(cur, ">",  p)); });

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == true,  PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == false, PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3);
        }
    }

    {
        for (size_t cur_idx = 4; cur_idx < 8; ++cur_idx) {
            const auto& cur = pos.at(cur_idx);
            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == true,  PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == false, PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == false, PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == true,  PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == false, PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == true,  PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == false, PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == true,  PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == true,  PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == false, PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == true,  PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == false, PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7);
        }
    }

    {
        for (size_t cur_idx = 8; cur_idx < 12; ++cur_idx) {
            const auto& cur = pos.at(cur_idx);
            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == true,  PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == false, PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == false, PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == true,  PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == false, PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == true,  PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == false, PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == true,  PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == true,  PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == false, PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == true,  PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == false, PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
        }
    }

    {
        for (size_t cur_idx = 12; cur_idx < 16; ++cur_idx) {
            const auto& cur = pos.at(cur_idx);
            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == true,  PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur == p) == false, PP_OP_PP_MSG(cur, "==", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == false, PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur != p) == true,  PP_OP_PP_MSG(cur, "!=", p)); }, cur_idx);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == false, PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <  p) == true,  PP_OP_PP_MSG(cur, "<",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == false, PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur <= p) == true,  PP_OP_PP_MSG(cur, "<=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == true,  PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >  p) == false, PP_OP_PP_MSG(cur, ">",  p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

            each_of    (pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == true,  PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
            each_except(pos.begin(), pos.end(), [&](const auto& p) { BOOST_CHECK_MESSAGE((cur >= p) == false, PP_OP_PP_MSG(cur, ">=", p)); }, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
        }
    }
}
