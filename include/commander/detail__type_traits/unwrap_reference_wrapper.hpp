//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "decay.hpp"

#include <functional>
#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename T>
        struct is_reference_wrapper_impl
        {
            private:
                template <typename U>
                static std::true_type test(const std::reference_wrapper<U>&& value);

                template <typename U>
                static std::true_type test(const volatile std::reference_wrapper<U>&& value);

                static std::false_type test(...);

            public:
                using type = decltype(test(std::declval<std::decay_t<T>>()));
        };

        template <typename T>
        struct is_reference_wrapper : std::conjunction<std::negation<std::is_reference<T>>, typename is_reference_wrapper_impl<T>::type>
        {};

        template <typename T>
        inline constexpr bool is_reference_wrapper_v = is_reference_wrapper<T>::value;

        template <typename T>
        struct unwrap_reference_wrapper_impl
        {
            using type = T;
        };

        template<typename T>
        struct unwrap_reference_wrapper_impl<std::reference_wrapper<T>>
        {
            using type = std::add_lvalue_reference_t<T>;
        };

        template<typename T>
        struct unwrap_reference_wrapper_impl<const std::reference_wrapper<T>>
        {
            using type = std::add_lvalue_reference_t<T>;
        };

        template<typename T>
        struct unwrap_reference_wrapper_impl<volatile std::reference_wrapper<T>>
        {
            using type = std::add_lvalue_reference_t<T>;
        };

        template<typename T>
        struct unwrap_reference_wrapper_impl<const volatile std::reference_wrapper<T>>
        {
            using type = std::add_lvalue_reference_t<T>;
        };

        template <typename T>
        struct unwrap_reference_wrapper
        {
            using type = typename unwrap_reference_wrapper_impl<T>::type;
        };

        template <typename T>
        using unwrap_reference_wrapper_t = typename unwrap_reference_wrapper<T>::type;

    } // namespace detail

} // namespace commander
