//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <iterator>
#include <type_traits>
#include <utility>

namespace commander
{

    namespace detail
    {

        template <typename T>
        struct is_traversable_impl
        {
            private:
                template <typename U>
                static std::true_type test(U&& value, decltype(std::begin(value))* = nullptr, decltype(std::end(value))* = nullptr);

                static std::false_type test(...);

            public:
                using type = decltype(test(std::declval<T>()));
        };

        template <typename T>
        struct is_traversable : is_traversable_impl<T>::type
        {};

        template <typename T>
        inline constexpr bool is_traversable_v = is_traversable<T>::value;

    } // namespace detail

} // namespace commander
