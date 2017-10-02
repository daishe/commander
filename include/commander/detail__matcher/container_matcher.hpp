//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../detail__type_traits/is_equality_comparable.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "invoke_matcher.hpp"

#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <utility>

namespace commander
{
    template <typename Container>
    class container_matcher
    {
        public:
            using container_type = Container;

            constexpr explicit container_matcher() = default;

            constexpr explicit container_matcher(const container_matcher<container_type>&) = default;

            constexpr explicit container_matcher(container_matcher<container_type>&&) = default;

            constexpr explicit container_matcher(const container_type& container) : container_(container)
            {};

            template <typename OtherContainer>
            constexpr explicit container_matcher(OtherContainer&& container) : container_(std::forward<OtherContainer>(container))
            {}

            template <typename... Args>
            constexpr explicit container_matcher(std::in_place_t, Args&&... args) : container_(std::forward<Args>(args)...)
            {}

            template <typename T, typename... Args>
            constexpr explicit container_matcher(std::in_place_t, std::initializer_list<T> il, Args&&... args) : container_(il, std::forward<Args>(args)...)
            {}

            template <typename... Args>
            constexpr explicit container_matcher(std::piecewise_construct_t, std::tuple<Args...> args) : container_matcher(std::piecewise_construct, args, std::make_index_sequence<sizeof...(Args)>())
            {}

            constexpr container_matcher<container_type>& operator =(const container_matcher<container_type>&) = default;

            constexpr container_matcher<container_type>& operator =(container_matcher<container_type>&&) = default;

            template <typename Value>
            constexpr auto match(const Value& value) const
            {
                if constexpr (detail::is_equality_comparable_v<const typename container_type::value_type&, const Value&>)
                    return std::find(this->container_.cbegin(), this->container_.cend(), value) != this->container_.cend();
                else
                    return false;
            }

            constexpr container_type& container() &
            { return this->container_; };

            constexpr const container_type& container() const&
            { return this->container_; };

            constexpr container_type&& container() &&
            { return std::move(this->container_); };

            constexpr const container_type&& container() const&&
            { return std::move(this->container_); };

        private:
            container_type container_;

            template <typename... Args, size_t... Idx>
            constexpr container_matcher(std::piecewise_construct_t, std::tuple<Args...> args, std::integer_sequence<size_t, Idx...>) : container_(std::forward<Args>(std::get<Idx>(args))...)
            {}
    };

    template <typename Container>
    container_matcher(Container) -> container_matcher<Container>;

    template <typename... Types>
    constexpr auto make_container_matcher(Types&&... values)
    { return container_matcher<detail::unwrap_reference_wrapper_t<std::decay_t<Types>>...>(std::forward<Types>(values)...); }

} // namespace commander
