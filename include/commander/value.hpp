//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "detail__type_traits/is_implicitly_default_constructible.hpp"
#include "detail__type_traits/unwrap_reference_wrapper.hpp"
#include "no_value.hpp"

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename Value>
    class value
    {
        public:
            using value_type  = Value;

            template <typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_default_constructible<V>,
                    detail::is_implicitly_default_constructible<V>
                >::value,
                bool
            > = false>
            constexpr value() : value_()
            {}

            template <typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_default_constructible<V>,
                    std::negation<
                        detail::is_implicitly_default_constructible<V>
                    >
                >::value,
                bool
            > = false>
            constexpr explicit value() : value_()
            {}

            template <typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_copy_constructible<V>,
                    std::is_convertible<const V&, V>
                >::value,
                bool
            > = false>
            constexpr value(const value_type& value) : value_(value)
            {}

            template <typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_copy_constructible<V>,
                    std::negation<
                        std::is_convertible<const V&, V>
                    >
                >::value,
                bool
            > = false>
            constexpr explicit value(const value_type& value) : value_(value)
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, U1&&>,
                    std::is_convertible<U1&&, value_type>
                >::value,
                bool
            > = false>
            constexpr value(U1&& value) : value_(std::forward<U1>(value))
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, U1&&>,
                    std::negation<
                        std::is_convertible<U1&&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr explicit value(U1&& value) : value_(std::forward<U1>(value))
            {}

            template <typename... Args>
            constexpr value(std::piecewise_construct_t, std::tuple<Args...> args)
                : value(std::piecewise_construct, args, std::make_index_sequence<sizeof...(Args)>())
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, const U1&>,
                    std::is_convertible<const U1&, value_type>
                >::value,
                bool
            > = false>
            constexpr value(const value<U1>& other) : value_(other.value_)
            {}

            constexpr value(const value<value_type>& other) = default;

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, const U1&>,
                    std::negation<
                        std::is_convertible<const U1&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr explicit value(const value<U1>& other) : value_(other.value_)
            {}

            constexpr value(value<value_type>&& other) = default;

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, U1&&>,
                    std::is_convertible<U1&&, value_type>
                >::value,
                bool
            > = false>
            constexpr value(value<U1>&& other) : value_(std::forward<U1>(other.value_))
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::is_constructible<value_type, U1&&>,
                    std::negation<
                        std::is_convertible<U1&&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr explicit value(value<U1>&& other) : value_(std::forward<U1>(other.value_))
            {}

            template <typename V = value_type, std::enable_if_t<
                std::is_copy_assignable<V>::value,
                bool
            > = false>
            constexpr value<value_type>& operator =(const value<value_type>& other)
            {
                this->value_ = other.value_;
                return *this;
            }

            template <typename V = value_type, std::enable_if_t<
                std::negation<
                    std::is_copy_assignable<V>
                >::value,
                bool
            > = false>
            constexpr value<value_type>& operator =(const value<value_type>& other) = delete;

            template <typename U1, std::enable_if_t<
                std::is_assignable<value_type&, const U1&>::value,
                bool
            > = false>
            constexpr value<value_type>& operator =(const value<U1>& other)
            {
                this->value_ = other.value_;
                return *this;
            }

            template <typename V = value_type, std::enable_if_t<
                std::is_move_assignable<V>::value,
                bool
            > = false>
            constexpr value<value_type>& operator =(value<value_type>&& other)
                noexcept(std::is_nothrow_move_assignable<value_type>::value)
            {
                this->value_  = std::forward<value_type>(other.value_);
                return *this;
            }

            template <typename U1, std::enable_if_t<
                std::is_assignable<value_type&, const U1&&>::value,
                bool
            > = false>
            constexpr value<value_type>& operator =(value<U1>&& other)
            {
                this->value_ = std::forward<value_type>(other.value_);
                return *this;
            }

            constexpr value_type* operator ->()
            { return &this->value_; };

            constexpr const value_type* operator ->() const
            { return &this->value_; };

            constexpr value_type& operator *() &
            { return this->value_; };

            constexpr const value_type& operator *() const&
            { return this->value_; };

            constexpr value_type&& operator *() &&
            { return std::move(this->value_); };

            constexpr const value_type&& operator *() const&&
            { return std::move(this->value_); };

            template <typename V = value_type, std::enable_if_t<
                std::is_swappable<V>::value,
                bool
            > = false>
            constexpr void swap(value<value_type>& other)
                noexcept(std::is_nothrow_swappable<value_type>::value)
            {
                using std::swap;
                swap(this->value_, other.value_);
            }

        private:
            value_type value_;

            template <typename... Args, size_t... Idx>
            constexpr value(std::piecewise_construct_t, std::tuple<Args...> args, std::integer_sequence<size_t, Idx...> idx)
                : value_(std::forward<Args>(std::get<Idx>(args))...)
            {}
    };

    template <typename T>
    value(T) -> value<T>;

    namespace detail
    {

        template <typename T>
        struct is_value_type_impl : std::false_type
        {};

        template <typename T>
        struct is_value_type_impl<value<T>> : std::true_type
        {};

    } // namespace detail

    template <typename T>
    struct is_value_type : detail::is_value_type_impl<std::decay_t<T>>
    {};

    template <typename T>
    inline constexpr bool is_value_type_v = is_value_type<T>::value;

    template <typename T>
    constexpr bool operator ==(const value<T>& lhs, const value<T>& rhs)
    { return lhs.header() == rhs.header() && lhs.value() == rhs.value(); }

    template <typename T>
    constexpr bool operator !=(const value<T>& lhs, const value<T>& rhs)
    { return !(lhs == rhs); }

    template <typename T>
    constexpr bool operator <(const value<T>& lhs, const value<T>& rhs)
    { return lhs.value() < rhs.value(); }

    template <typename T>
    constexpr bool operator >(const value<T>& lhs, const value<T>& rhs)
    { return rhs < lhs; }

    template <typename T>
    constexpr bool operator <=(const value<T>& lhs, const value<T>& rhs)
    { return !(rhs < lhs); }

    template <typename T>
    constexpr bool operator >=(const value<T>& lhs, const value<T>& rhs)
    { return !(lhs < rhs); }

    template <typename T>
    constexpr auto make_value(T&& arg)
    { return value<detail::unwrap_reference_wrapper_t<std::decay_t<T>>>(std::forward<T>(arg)); }

    template <typename T>
    constexpr value<T&&> forward_as_value(T&& arg) noexcept
    { return value<T&&>(std::forward<T>(arg)); }

} // namespace commander

namespace commander
{

    namespace detail
    {

        template <size_t Idx>
        struct value_get_by_idx;

        template <>
        struct value_get_by_idx<0>
        {
            template <typename T>
            static constexpr T& ref(value<T>& val) noexcept
            { return val.value(); }

            template <typename T>
            static constexpr T&& rref(value<T>&& val) noexcept
            { return std::forward<T>(val.value()); }

            template <typename T>
            static constexpr const T& cref(const value<T>& val) noexcept
            { return val.value(); }

            template <typename T>
            static constexpr const T&& crref(const value<T>&& val) noexcept
            { return val.value(); }
        };

    } // namespace detail

} // namespace commander

namespace std
{

    template <typename T>
    struct tuple_size<commander::value<T>> : public std::integral_constant<size_t, 1>
    {};

    template <typename T>
    struct tuple_element<0, commander::value<T>>
    { using type = T; };

    template <typename T, std::enable_if_t<
        std::is_swappable<T>::value,
        bool
    > = false>
    constexpr void swap(commander::value<T>& lhs, commander::value<T>& rhs) noexcept(noexcept(lhs.swap(rhs)))
    { lhs.swap(rhs); }

    template <typename T, std::enable_if_t<
        std::negation<
            std::is_swappable<T>
        >::value,
        bool
    > = false>
    constexpr void swap(commander::value<T>& lhs, commander::value<T>& rhs) = delete;

    template <size_t Idx, typename T>
    constexpr std::tuple_element_t<Idx, commander::value<T>>& get(commander::value<T>& val) noexcept
    { return commander::detail::value_get_by_idx<Idx>::ref(val); }

    template <size_t Idx, typename T>
    constexpr std::tuple_element_t<Idx, commander::value<T>>&& get(commander::value<T>&& val) noexcept
    { return commander::detail::value_get_by_idx<Idx>::rref(val); }

    template <size_t Idx, typename T>
    constexpr const std::tuple_element_t<Idx, commander::value<T>>& get(const commander::value<T>& val) noexcept
    { return commander::detail::value_get_by_idx<Idx>::cref(val); }

    template <size_t Idx, typename T>
    constexpr const std::tuple_element_t<Idx, commander::value<T>>&& get(const commander::value<T>&& val) noexcept
    { return commander::detail::value_get_by_idx<Idx>::crref(val); }

    template <typename T>
    constexpr T& get(commander::value<T>& val) noexcept
    { return val.value(); }

    template <typename T>
    constexpr T&& get(commander::value<T>&& val) noexcept
    { return std::move(std::move(val).value()); }

    template <typename T>
    constexpr const T& get(const commander::value<T>& val) noexcept
    { return val.value(); }

    template <typename T>
    constexpr const T&& get(const commander::value<T>&& val) noexcept
    { return std::move(std::move(val).value()); }

} // namespace std
