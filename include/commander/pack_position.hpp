//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace commander
{

    template <typename Size>
    struct pack_position
    {
        using size_type = Size;

        bool      is_first = true;
        size_type exact    = 0;
        bool      is_last  = true;

    };

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator ==(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return (lhs.is_first == rhs.is_first) && (lhs.exact == rhs.exact) && (lhs.is_last == rhs.is_last); }

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator !=(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return !(lhs == rhs); }

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator <(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return (lhs.exact < rhs.exact); }

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator <=(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return !(rhs < lhs); }

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator >(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return rhs < lhs; }

    template <typename SizeLhs, typename SizeRhs>
    constexpr bool operator >=(const pack_position<SizeLhs>& lhs, const pack_position<SizeRhs>& rhs)
    { return !(lhs < rhs); }


} // namespace commander
