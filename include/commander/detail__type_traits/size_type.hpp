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

        template <typename T>
        struct has_size_type_impl
        {
            private:
                template <typename U>
                static std::true_type test(const U&, typename U::size_type* = nullptr);

                static std::false_type test(...);

            public:
                using type = decltype(test(std::declval<T>()));
        };

        template <typename T>
        struct has_size_type : has_size_type_impl<T>::type
        {};

        template <typename T>
        inline constexpr bool has_size_type_v = has_size_type<T>::value;

        template <typename SizeType>
        struct size_type_impl
        {
            using size_type = SizeType;
        };

        template <typename T, typename SizeType = size_t>
        struct size_type
        {
            using type = typename std::conditional_t<has_size_type_v<T>, std::decay_t<T>, size_type_impl<SizeType>>::size_type;
        };

        template <typename T, typename SizeType = size_t>
        using size_type_t = typename size_type<T, SizeType>::type;

    } // namespace detail

} // namespace commander
