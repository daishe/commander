//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "is_traversable.hpp"

#include <iterator>
#include <type_traits>
#include <utility>

namespace commander
{

    namespace detail
    {

        template <typename T>
        struct traversable_value_type_impl
        {
            private:
                template <typename U>
                static auto test(U&& container) -> decltype(*std::begin(container));

                static auto test(...) -> void;

            public:
                using type = decltype(test(std::declval<T>()));
        };

        template <typename T>
        struct traversable_value_type
        {
            using type = std::conditional_t<is_traversable_v<T>, typename traversable_value_type_impl<T>::type, void>;
        };

        template <typename T>
        using traversable_value_type_t = typename traversable_value_type<T>::type;

    } // namespace detail

} // namespace commander
