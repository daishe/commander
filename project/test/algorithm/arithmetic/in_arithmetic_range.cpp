//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/algorithm.hpp>

#include <boost/test/unit_test.hpp>

#include "arithmetic_helpers.hpp"

#include <type_traits>

BOOST_AUTO_TEST_CASE( in_arithmetic_range )
{
    namespace comd = commander::detail;

    {
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int8_t>::max())      == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int8_t>::lowest())   == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint8_t>::max())     == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint8_t>::lowest())  == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int16_t>::max())     == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int16_t>::lowest())  == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint16_t>::max())    == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint16_t>::lowest()) == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int32_t>::max())     == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int32_t>::lowest())  == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint32_t>::max())    == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint32_t>::lowest()) == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int64_t>::max())     == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<int64_t>::lowest())  == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint64_t>::max())    == true);
        BOOST_CHECK(comd::in_arithmetic_range<bool>(nl<uint64_t>::lowest()) == true);

        BOOST_CHECK(comd::in_arithmetic_range<int8_t>(true)   == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(true)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<int16_t>(true)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(true) == true);
        BOOST_CHECK(comd::in_arithmetic_range<int32_t>(true)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(true) == true);
        BOOST_CHECK(comd::in_arithmetic_range<int64_t>(true)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(true) == true);

        BOOST_CHECK(comd::in_arithmetic_range<int8_t>(false)   == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(false)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<int16_t>(false)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(false) == true);
        BOOST_CHECK(comd::in_arithmetic_range<int32_t>(false)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(false) == true);
        BOOST_CHECK(comd::in_arithmetic_range<int64_t>(false)  == true);
        BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(false) == true);
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint8_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint8_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint8_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint8_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint8_t>(nl<int8_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int16_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int16_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int16_t>(nl<int8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint16_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint16_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint16_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint16_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint16_t>(nl<int8_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int32_t>(nl<int8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint32_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint32_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint32_t>(nl<int8_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<int64_t>(nl<int8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint64_t>(nl<int8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint64_t>(nl<int8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int8_t>(sc<uint64_t>(nl<int8_t>::max(), +1)) == false);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int8_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int8_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int8_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int8_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int16_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int16_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int16_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint16_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint16_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint16_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int32_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint32_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<int64_t>(nl<uint8_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint8_t>(sc<uint64_t>(nl<uint8_t>::lowest(), +1)) == true);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint16_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint16_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint16_t>(nl<int16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint16_t>(nl<int16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint16_t>(nl<int16_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int32_t>(nl<int16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint32_t>(nl<int16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint32_t>(nl<int16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint32_t>(nl<int16_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<int64_t>(nl<int16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint64_t>(nl<int16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint64_t>(nl<int16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int16_t>(sc<uint64_t>(nl<int16_t>::max(), +1)) == false);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int8_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int8_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int8_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int8_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint8_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint8_t>(nl<uint16_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint8_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint8_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int16_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int16_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int16_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int16_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int32_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint32_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<int64_t>(nl<uint16_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint16_t>(sc<uint64_t>(nl<uint16_t>::lowest(), +1)) == true);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int32_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint32_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint32_t>(nl<int32_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint32_t>(nl<int32_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint32_t>(nl<int32_t>::max(), +1)) == false);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<int64_t>(nl<int32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint64_t>(nl<int32_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint64_t>(nl<int32_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int32_t>(sc<uint64_t>(nl<int32_t>::max(), +1)) == false);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int8_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int8_t>(nl<uint32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int8_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int8_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint8_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint8_t>(nl<uint32_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint8_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint8_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int16_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int16_t>(nl<uint32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int16_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int16_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint16_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint16_t>(nl<uint32_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint16_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint16_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int32_t>(nl<uint32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int32_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int32_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint32_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<int64_t>(nl<uint32_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::max(), +1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint32_t>(sc<uint64_t>(nl<uint32_t>::lowest(), +1)) == true);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint8_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint16_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int32_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint32_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int64_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<int64_t>::lowest()) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint64_t>::max()) == false);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(nl<uint64_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(sc<uint64_t>(nl<int64_t>::max(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(sc<uint64_t>(nl<int64_t>::max()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<int64_t>(sc<uint64_t>(nl<int64_t>::max(), +1)) == false);
        }
    }

    {
        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int8_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int8_t>(nl<uint64_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int8_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int8_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint8_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint8_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint8_t>(nl<uint64_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint8_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint8_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int16_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int16_t>(nl<uint64_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int16_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int16_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint16_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint16_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint16_t>(nl<uint64_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint16_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint16_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int32_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int32_t>(nl<uint64_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int32_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int32_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint32_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint32_t>::lowest()) == true);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint32_t>(nl<uint64_t>::lowest(), -1)) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint32_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<uint32_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int64_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<int64_t>::lowest()) == false);

            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int64_t>(nl<uint64_t>::lowest(), -1)) == false);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int64_t>(nl<uint64_t>::lowest()))     == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(sc<int64_t>(nl<uint64_t>::lowest(), +1)) == true);
        }

        {
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint64_t>::max()) == true);
            BOOST_CHECK(comd::in_arithmetic_range<uint64_t>(nl<uint64_t>::lowest()) == true);
        }
    }
}
