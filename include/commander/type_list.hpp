//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "detail__type_traits/decay.hpp"
#include "detail__type_traits/index_of.hpp"

namespace commander
{

    namespace tl
    {

        inline constexpr size_t npos = size_t(-1);

        template <typename Self, template <typename...> typename To>
        struct rebase;

        template <template <typename...> typename Self, typename... Types, template <typename...> typename To>
        struct rebase<Self<Types...>, To>
        {
            using type = To<Types...>;
        };

        template <typename Self, template <typename...> typename To>
        using rebase_t = typename rebase<Self, To>::type;

        template <typename Self>
        struct size;

        template <template <typename...> typename Self, typename... Types>
        struct size<Self<Types...>> : std::integral_constant<size_t, sizeof...(Types)>
        {};

        template <typename Self>
        inline constexpr size_t size_v = size<Self>::value;

        template <typename Self>
        struct empty;

        template <template <typename...> typename Self, typename... Types>
        struct empty<Self<Types...>> : std::integral_constant<bool, sizeof...(Types) == 0>
        {};

        template <typename Self>
        inline constexpr bool empty_v = empty<Self>::value;

        template <typename Self, typename T>
        struct index_of;

        template <template <typename...> typename Self, typename... Types, typename T>
        struct index_of<Self<Types...>, T> : detail::index_of<T, Types...>
        {};

        template <typename Self, typename T>
        inline constexpr size_t index_of_v = index_of<Self, T>::value;

    } // namespace tl

    template <typename... Types>
    struct type_list
    {};

    namespace detail
    {

        template <typename T>
        struct is_type_list_impl : std::false_type
        {};

        template <typename... Types>
        struct is_type_list_impl<type_list<Types...>> : std::true_type
        {};

    } // namespace detail

    template <typename T>
    struct is_type_list : detail::is_type_list_impl<detail::decay_without_r_t<T>>
    {};

    template <typename T>
    inline constexpr bool is_type_list_v = is_type_list<T>::value;

    template <typename... LhsTypes, typename... RhsTypes>
    constexpr bool operator ==(const type_list<LhsTypes...>&, const type_list<RhsTypes...>&)
    {
        if constexpr (sizeof...(LhsTypes) == 0 || sizeof...(RhsTypes) == 0)
            return sizeof...(LhsTypes) == 0 && sizeof...(RhsTypes) == 0;
        else
            return ((tl::index_of_v<type_list<LhsTypes...>, RhsTypes> != tl::npos) && ...) && ((tl::index_of_v<type_list<RhsTypes...>, LhsTypes> != tl::npos) && ...);
    }

    template <typename... LhsTypes, typename... RhsTypes>
    constexpr bool operator !=(const type_list<LhsTypes...>& lhs, const type_list<RhsTypes...>& rhs)
    { return !(lhs == rhs); }

} // namespace commander
