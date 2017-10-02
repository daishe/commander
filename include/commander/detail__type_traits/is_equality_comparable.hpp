//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>
#include <utility>

namespace commander
{

    namespace detail
    {

        template <typename T1, typename T2>
        struct is_equality_comparable_impl
        {
            private:
                template <typename U1, typename U2>
                static auto test(U1&& v1, U2&& v2) -> std::is_convertible<decltype(std::forward<U1>(v1) == std::forward<U2>(v2)), bool>;

                static std::false_type test(...);

            public:
                using type = decltype(test(std::declval<T1>(), std::declval<T2>()));
        };

        template <typename T1, typename T2>
        struct is_equality_comparable
            : std::conjunction<typename is_equality_comparable_impl<T1, T2>::type, typename is_equality_comparable_impl<T2, T1>::type>
        {};

        template <typename T1, typename T2>
        inline constexpr bool is_equality_comparable_v = is_equality_comparable<T1, T2>::value;

    } // namespace detail

} // namespace commander
