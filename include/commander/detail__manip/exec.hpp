//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../detail__type_traits/decay.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename... Types>
    class exec
    {
        public:
            using value_type = std::tuple<Types...>;

            template <typename... Others>
            constexpr explicit exec(Others&&... args) : value_(std::forward<Others>(args)...)
            {}

            constexpr exec(const exec<Types...>&) = default;

            constexpr exec(exec<Types...>&&) = default;

            constexpr exec<Types...>& operator =(const exec<Types...>&) = default;

            constexpr exec<Types...>& operator =(exec<Types...>&&) = default;

            template <typename Command>
            constexpr decltype(auto) operator ()(Command&& command)
            { return std::apply(command, this->value_); }

            constexpr value_type& value() &
            { return this->value_; };

            constexpr const value_type& value() const&
            { return this->value_; };

            constexpr value_type&& value() &&
            { return std::move(this->value_); };

            constexpr const value_type&& value() const&&
            { return std::move(this->value_); };

        private:
            value_type value_;
    };

    template <typename... Types>
    exec(Types...) -> exec<Types&&...>;

    namespace detail
    {

        template <typename T>
        struct is_exec_impl : std::false_type
        {};

        template <typename... Types>
        struct is_exec_impl<exec<Types...>> : std::true_type
        {};

    } // namespace detail

    template <typename T>
    struct is_exec : detail::is_exec_impl<detail::decay_t<T>>
    {};

    template <typename T>
    inline constexpr bool is_exec_v = is_exec<T>::value;

    namespace func
    {

        template <typename T>
        constexpr auto is_exec(T&&)
        {
            if constexpr (commander::is_exec_v<T>)
                return std::true_type();
            else
                return std::false_type();
        }

        template <typename T>
        constexpr bool is_exec_v(T&& value)
        { return is_exec(std::forward<T>(value)).value; }

    } // namespace func

    template <typename... Types, typename... Others>
    constexpr bool operator ==(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() == rhs.value(); }

    template <typename... Types, typename... Others>
    constexpr bool operator <(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() < rhs.value(); }

    template <typename... Types, typename... Others>
    constexpr bool operator !=(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() != rhs.value(); }

    template <typename... Types, typename... Others>
    constexpr bool operator >(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() > rhs.value(); }

    template <typename... Types, typename... Others>
    constexpr bool operator <=(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() <= rhs.value(); }

    template <typename... Types, typename... Others>
    constexpr bool operator >=(const exec<Types...>& lhs, const exec<Others...>& rhs)
    { return lhs.value() >= rhs.value(); }

    template <typename... Types>
    constexpr auto make_exec(Types&&... args)
    { return exec<detail::unwrap_reference_wrapper_t<std::decay_t<Types>>...>(std::forward<Types>(args)...); }

    template <typename... Types>
    constexpr auto forward_as_exec(Types&&... args) noexcept
    { return exec<Types&&...>(std::forward<Types>(args)...); }

} // namespace commander
