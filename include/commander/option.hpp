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

    template <typename Header, typename Value>
    class option
    {
        public:
            using header_type = Header;
            using value_type  = Value;

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_default_constructible<H>,
                        std::is_default_constructible<V>
                    >,
                    std::conjunction<
                        detail::is_implicitly_default_constructible<H>,
                        detail::is_implicitly_default_constructible<V>
                    >
                >::value,
                bool
            > = false>
            constexpr option() : header_(), value_()
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_default_constructible<H>,
                        std::is_default_constructible<V>
                    >,
                    std::negation<std::conjunction<
                        detail::is_implicitly_default_constructible<H>,
                        detail::is_implicitly_default_constructible<V>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option() : header_(), value_()
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_copy_constructible<H>,
                        std::is_default_constructible<V>
                    >,
                    std::conjunction<
                        std::is_convertible<const H&, H>,
                        detail::is_implicitly_default_constructible<V>
                    >
                >::value,
                bool
            > = false>
            constexpr option(const header_type& header) : header_(header), value_()
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_copy_constructible<H>,
                        std::is_default_constructible<V>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<const H&, H>,
                        detail::is_implicitly_default_constructible<V>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(const header_type& header) : header_(header), value_()
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_default_constructible<value_type>
                    >,
                    std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        detail::is_implicitly_default_constructible<value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr option(U1&& header) : header_(std::forward<U1>(header)), value_()
            {}

            template <typename U1, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_default_constructible<value_type>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        detail::is_implicitly_default_constructible<value_type>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(U1&& header) : header_(std::forward<U1>(header)), value_()
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_copy_constructible<H>,
                        std::is_copy_constructible<V>
                    >,
                    std::conjunction<
                        std::is_convertible<const H&, H>,
                        std::is_convertible<const V&, V>
                    >
                >::value,
                bool
            > = false>
            constexpr option(const header_type& header, const value_type& value) : header_(header), value_(value)
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_copy_constructible<H>,
                        std::is_copy_constructible<V>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<const H&, H>,
                        std::is_convertible<const V&, V>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(const header_type& header, const value_type& value) : header_(header), value_(value)
            {}

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_constructible<value_type, U2&&>
                    >,
                    std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        std::is_convertible<U2&&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr option(U1&& header, U2&& value) : header_(std::forward<U1>(header)), value_(std::forward<U2>(value))
            {}

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_constructible<value_type, U2&&>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        std::is_convertible<U2&&, value_type>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(U1&& header, U2&& value) : header_(std::forward<U1>(header)), value_(std::forward<U2>(value))
            {}

            template <typename... Args1, typename... Args2>
            constexpr option(std::piecewise_construct_t, std::tuple<Args1...> header_args, std::tuple<Args2...> value_args)
                : option(std::piecewise_construct, header_args, value_args, std::make_index_sequence<sizeof...(Args1)>(), std::make_index_sequence<sizeof...(Args2)>())
            {}

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, const U1&>,
                        std::is_constructible<value_type, const U2&>
                    >,
                    std::conjunction<
                        std::is_convertible<const U1&, header_type>,
                        std::is_convertible<const U2&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr option(const option<U1, U2>& other) : header_(other.header_), value_(other.value_)
            {}

            constexpr option(const option<header_type, value_type>& other) = default;

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, const U1&>,
                        std::is_constructible<value_type, const U2&>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<const U1&, header_type>,
                        std::is_convertible<const U2&, value_type>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(const option<U1, U2>& other) : header_(other.header_), value_(other.value_)
            {}

            constexpr option(option<header_type, value_type>&& other) = default;

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_constructible<value_type, U2&&>
                    >,
                    std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        std::is_convertible<U2&&, value_type>
                    >
                >::value,
                bool
            > = false>
            constexpr option(option<U1, U2>&& other) : header_(std::forward<U1>(other.header_)), value_(std::forward<U2>(other.value_))
            {}

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::conjunction<
                        std::is_constructible<header_type, U1&&>,
                        std::is_constructible<value_type, U2&&>
                    >,
                    std::negation<std::conjunction<
                        std::is_convertible<U1&&, header_type>,
                        std::is_convertible<U2&&, value_type>
                    >>
                >::value,
                bool
            > = false>
            constexpr explicit option(option<U1, U2>&& other) : header_(std::forward<U1>(other.header_)), value_(std::forward<U2>(other.value_))
            {}

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_copy_assignable<H>,
                    std::is_copy_assignable<V>
                >::value,
                bool
            > = false>
            constexpr option<header_type, value_type>& operator =(const option<header_type, value_type>& other)
            {
                this->header_ = other.header_;
                this->value_  = other.value_;
                return *this;
            }

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::negation<std::conjunction<
                    std::is_copy_assignable<H>,
                    std::is_copy_assignable<V>
                >>::value,
                bool
            > = false>
            constexpr option<header_type, value_type>& operator =(const option<header_type, value_type>& other) = delete;

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::is_assignable<header_type&, const U1&>,
                    std::is_assignable<value_type&, const U2&>
                >::value,
                bool
            > = false>
            constexpr option<header_type, value_type>& operator =(const option<U1, U2>& other)
            {
                this->header_ = other.header_;
                this->value_  = other.value_;
                return *this;
            }

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_move_assignable<H>,
                    std::is_move_assignable<V>
                >::value,
                bool
            > = false>
            constexpr option<header_type, value_type>& operator =(option<header_type, value_type>&& other)
                noexcept(std::conjunction<
                    std::is_nothrow_move_assignable<header_type>,
                    std::is_nothrow_move_assignable<value_type>
                >::value)
            {
                this->header_ = std::forward<header_type>(other.header_);
                this->value_  = std::forward<value_type>(other.value_);
                return *this;
            }

            template <typename U1, typename U2, std::enable_if_t<
                std::conjunction<
                    std::is_assignable<header_type&, const U1&&>,
                    std::is_assignable<value_type&, const U2&&>
                >::value,
                bool
            > = false>
            constexpr option<header_type, value_type>& operator =(option<U1, U2>&& other)
            {
                this->header_ = std::forward<header_type>(other.header_);
                this->value_  = std::forward<value_type>(other.value_);
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
            { return this->value_; };

            constexpr const value_type&& operator *() const&&
            { return this->value_; };

            template <typename H = header_type, typename V = value_type, std::enable_if_t<
                std::conjunction<
                    std::is_swappable<H>,
                    std::is_swappable<V>
                >::value,
                bool
            > = false>
            constexpr void swap(option<header_type, value_type>& other)
                noexcept(std::conjunction<
                    std::is_nothrow_swappable<header_type>,
                    std::is_nothrow_swappable<value_type>
                >::value)
            {
                using std::swap;
                swap(this->header_, other.header_);
                swap(this->value_, other.value_);
            }

            constexpr header_type& header() &
            { return this->header_; };

            constexpr const header_type& header() const&
            { return this->header_; };

            constexpr header_type&& header() &&
            { return std::move(this->header_); };

            constexpr const header_type&& header() const&&
            { return std::move(this->value_); };

            constexpr value_type& value() &
            { return this->value_; };

            constexpr const value_type& value() const&
            { return this->value_; };

            constexpr value_type&& value() &&
            { return std::move(this->value_); };

            constexpr const value_type&& value() const&&
            { return std::move(this->value_); };

        private:
            header_type header_;
            value_type  value_;

            template <typename... Args1, typename... Args2, size_t... Idx1, size_t... Idx2>
            constexpr option(std::piecewise_construct_t, std::tuple<Args1...> header_args, std::tuple<Args2...> value_args, std::integer_sequence<size_t, Idx1...>, std::integer_sequence<size_t, Idx2...>)
                : header_(std::forward<Args1>(std::get<Idx1>(header_args))...), value_(std::forward<Args2>(std::get<Idx2>(value_args))...)
            {}
    };

    template <typename T1>
    option(T1) -> option<T1, no_value_t>;

    template <typename T1, typename T2>
    option(T1, T2) -> option<T1, T2>;

    namespace detail
    {

        template <typename T>
        struct is_option_type_impl : std::false_type
        {};

        template <typename T1, typename T2>
        struct is_option_type_impl<option<T1, T2>> : std::true_type
        {};

    } // namespace detail

    template <typename T>
    struct is_option_type : detail::is_option_type_impl<std::decay_t<T>>
    {};

    template <typename T>
    inline constexpr bool is_option_type_v = is_option_type<T>::value;

    template <typename T1, typename T2>
    constexpr bool operator ==(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return lhs.header() == rhs.header() && lhs.value() == rhs.value(); }

    template <typename T1, typename T2>
    constexpr bool operator !=(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return !(lhs == rhs); }

    template <typename T1, typename T2>
    constexpr bool operator <(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return (lhs.header() < rhs.header()) || (!(rhs.header() < lhs.header()) && lhs.value() < rhs.value()); }

    template <typename T1, typename T2>
    constexpr bool operator >(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return rhs < lhs; }

    template <typename T1, typename T2>
    constexpr bool operator <=(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return !(rhs < lhs); }

    template <typename T1, typename T2>
    constexpr bool operator >=(const option<T1, T2>& lhs, const option<T1, T2>& rhs)
    { return !(lhs < rhs); }

    template <typename T1>
    constexpr auto make_option(T1&& arg1)
    { return option<detail::unwrap_reference_wrapper_t<std::decay_t<T1>>, no_value_t>(std::forward<T1>(arg1), no_value); }

    template <typename T1, typename T2>
    constexpr auto make_option(T1&& arg1, T2&& arg2)
    { return option<detail::unwrap_reference_wrapper_t<std::decay_t<T1>>, detail::unwrap_reference_wrapper_t<std::decay_t<T2>>>(std::forward<T1>(arg1), std::forward<T2>(arg2)); }

    template <typename T1>
    constexpr option<T1&&, no_value_t> forward_as_option(T1&& arg1) noexcept
    { return option<T1&&, no_value_t>(std::forward<T1>(arg1), no_value); }

    template <typename T1, typename T2>
    constexpr option<T1&&, T2&&> forward_as_option(T1&& arg1, T2&& arg2) noexcept
    { return option<T1&&, T2&&>(std::forward<T1>(arg1), std::forward<T2>(arg2)); }

} // namespace commander

namespace commander
{

    namespace detail
    {

        template <size_t Idx>
        struct option_get_by_idx;

        template <>
        struct option_get_by_idx<0>
        {
            template <typename T1, typename T2>
            static constexpr T1& ref(option<T1, T2>& opt) noexcept
            { return opt.header(); }

            template <typename T1, typename T2>
            static constexpr T1&& rref(option<T1, T2>&& opt) noexcept
            { return std::move(std::move(opt).header()); }

            template <typename T1, typename T2>
            static constexpr const T1& cref(const option<T1, T2>& opt) noexcept
            { return opt.header(); }

            template <typename T1, typename T2>
            static constexpr const T1&& crref(const option<T1, T2>&& opt) noexcept
            { return std::move(std::move(opt).header()); }
        };

        template <>
        struct option_get_by_idx<1>
        {
            template <typename T1, typename T2>
            static constexpr T2& ref(option<T1, T2>& opt) noexcept
            { return opt.value(); }

            template <typename T1, typename T2>
            static constexpr T2&& rref(option<T1, T2>&& opt) noexcept
            { return std::move(std::move(opt).value()); }

            template <typename T1, typename T2>
            static constexpr const T2& cref(const option<T1, T2>& opt) noexcept
            { return opt.value(); }

            template <typename T1, typename T2>
            static constexpr const T2&& crref(const option<T1, T2>&& opt) noexcept
            { return std::move(std::move(opt).value()); }
        };

    } // namespace detail

} // namespace commander

namespace std
{

    template <typename T1, typename T2>
    struct tuple_size<commander::option<T1, T2>> : public std::integral_constant<size_t, 2>
    {};

    template <typename T1, typename T2>
    struct tuple_element<0, commander::option<T1, T2>>
    { using type = T1; };

    template <typename T1, typename T2>
    struct tuple_element<1, commander::option<T1, T2>>
    { using type = T2; };

    template <typename T1, typename T2, std::enable_if_t<
        std::conjunction<
            std::is_swappable<T1>,
            std::is_swappable<T2>
        >::value,
        bool
    > = false>
    constexpr void swap(commander::option<T1, T2>& lhs, commander::option<T1, T2>& rhs) noexcept(noexcept(lhs.swap(rhs)))
    { lhs.swap(rhs); }

    template <typename T1, typename T2, std::enable_if_t<
        std::negation<std::conjunction<
            std::is_swappable<T1>,
            std::is_swappable<T2>
        >>::value,
        bool
    > = false>
    constexpr void swap(commander::option<T1, T2>& lhs, commander::option<T1, T2>& rhs) = delete;

    template <size_t Idx, typename T1, typename T2>
    constexpr std::tuple_element_t<Idx, commander::option<T1, T2>>& get(commander::option<T1, T2>& opt) noexcept
    { return commander::detail::option_get_by_idx<Idx>::ref(opt); }

    template <size_t Idx, typename T1, typename T2>
    constexpr std::tuple_element_t<Idx, commander::option<T1, T2>>&& get(commander::option<T1, T2>&& opt) noexcept
    { return commander::detail::option_get_by_idx<Idx>::rref(opt); }

    template <size_t Idx, typename T1, typename T2>
    constexpr const std::tuple_element_t<Idx, commander::option<T1, T2>>& get(const commander::option<T1, T2>& opt) noexcept
    { return commander::detail::option_get_by_idx<Idx>::cref(opt); }

    template <size_t Idx, typename T1, typename T2>
    constexpr const std::tuple_element_t<Idx, commander::option<T1, T2>>&& get(const commander::option<T1, T2>&& opt) noexcept
    { return commander::detail::option_get_by_idx<Idx>::crref(opt); }

    template <typename T, typename U>
    constexpr T& get(commander::option<T, U>& opt) noexcept
    { return opt.header(); }

    template <typename T, typename U>
    constexpr T&& get(commander::option<T, U>&& opt) noexcept
    { return std::move(std::move(opt).header()); }

    template <typename T, typename U>
    constexpr const T& get(const commander::option<T, U>& opt) noexcept
    { return opt.header(); }

    template <typename T, typename U>
    constexpr const T&& get(const commander::option<T, U>&& opt) noexcept
    { return std::move(std::move(opt).header()); }

    template <typename T, typename U>
    constexpr T& get(commander::option<U, T>& opt) noexcept
    { return opt.value(); }

    template <typename T, typename U>
    constexpr T&& get(commander::option<U, T>&& opt) noexcept
    { return std::move(std::move(opt).value()); }

    template <typename T, typename U>
    constexpr const T& get(const commander::option<U, T>& opt) noexcept
    { return opt.value(); }

    template <typename T, typename U>
    constexpr const T&& get(const commander::option<U, T>&& opt) noexcept
    { return std::move(std::move(opt).value()); }

} // namespace std
