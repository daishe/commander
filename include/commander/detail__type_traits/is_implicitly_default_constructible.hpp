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
        struct is_implicitly_default_constructible_impl
        {
            private:
                template <typename U>
                static void invoke(const U&);

                template <typename U>
                static std::true_type test(const U&, decltype(invoke<const U&>({}))* = nullptr);

                static std::false_type test(...);

            public:
                using type = decltype(test(std::declval<T>()));
        };

        template <typename T>
        struct is_implicitly_default_constructible
            : std::conjunction<std::is_default_constructible<T>, typename is_implicitly_default_constructible_impl<T>::type>
        {};

        template <typename T>
        inline constexpr bool is_implicitly_default_constructible_v = is_implicitly_default_constructible<T>::value;

    } // namespace detail

} // namespace commander
