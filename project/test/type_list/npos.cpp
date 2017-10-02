//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/type_list.hpp>

#include <boost/test/unit_test.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( npos )
{
    namespace com = commander;

    static_assert(std::is_same_v<const size_t, decltype(com::tl::npos)>);
    static_assert(com::tl::npos == size_t(-1));
}
