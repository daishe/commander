//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../applier.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "../matcher.hpp"

#include <initializer_list>
#include <optional>
#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename Meta, typename Value, typename Matcher, typename Applier>
    class optional_storage
    {
        public:
            using metadata_type = Meta;
            using value_type    = Value;
            using matcher_type  = Matcher;
            using applier_type  = Applier;

            constexpr explicit optional_storage() = default;

            constexpr explicit optional_storage(const optional_storage<metadata_type, value_type, matcher_type, applier_type>&) = default;

            constexpr explicit optional_storage(optional_storage<metadata_type, value_type, matcher_type, applier_type>&&) = default;

            constexpr explicit optional_storage(std::nullopt_t)
            {};

            template <typename Va>
            constexpr explicit optional_storage(Va&& default_value) : value_(std::forward<Va>(default_value))
            {}

            template <typename Ma, typename Ap>
            constexpr explicit optional_storage(Ma&& matcher, Ap&& applier) : matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Ma, typename Ap>
            constexpr explicit optional_storage(std::nullopt_t, Ma&& matcher, Ap&& applier) : matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Va, typename Ma, typename Ap>
            constexpr explicit optional_storage(Va&& default_value, Ma&& matcher, Ap&& applier) : value_(std::forward<Va>(default_value)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Me, typename Ma, typename Ap>
            constexpr explicit optional_storage(Me&& meta, std::nullopt_t, Ma&& matcher, Ap&& applier) : meta_(std::forward<Me>(meta)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Me, typename Va, typename Ma, typename Ap>
            constexpr explicit optional_storage(Me&& meta, Va&& default_value, Ma&& matcher, Ap&& applier) : value_(std::forward<Va>(default_value)), meta_(std::forward<Me>(meta)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename... MeArgs, typename... VaArgs, typename... MaArgs, typename... ApArgs>
            constexpr explicit optional_storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<VaArgs...> value_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args)
                : optional_storage(std::piecewise_construct, meta_args, value_args, matcher_args, applier_args, std::make_index_sequence<sizeof...(MeArgs)>(), std::make_index_sequence<sizeof...(VaArgs)>(), std::make_index_sequence<sizeof...(MaArgs)>(), std::make_index_sequence<sizeof...(ApArgs)>())
            {}

            constexpr optional_storage<metadata_type, value_type, matcher_type, applier_type>& operator =(const optional_storage<metadata_type, value_type, matcher_type, applier_type>&) = default;

            constexpr optional_storage<metadata_type, value_type, matcher_type, applier_type>& operator =(optional_storage<metadata_type, value_type, matcher_type, applier_type>&&) = default;

            constexpr optional_storage<metadata_type, value_type, matcher_type, applier_type>& operator =(std::nullopt_t)
            {
                this->value_ = std::nullopt;
                return *this;
            };

            template <typename T>
            constexpr optional_storage<metadata_type, value_type, matcher_type, applier_type>& operator =(T&& value)
            {
                this->value_ = std::forward<T>(value);
                return *this;
            }

            constexpr value_type* operator ->()
            { return &(*(this->value_)); };

            constexpr const value_type* operator ->() const
            { return &(*(this->value_)); };

            constexpr value_type& operator *() &
            { return *(this->value_); };

            constexpr const value_type& operator *() const&
            { return *(this->value_); };

            constexpr value_type&& operator *() &&
            { return *(this->value_); };

            constexpr const value_type&& operator *() const&&
            { return *(this->value_); };

            constexpr explicit operator bool() const noexcept
            { return (bool)(this->value_); };

            constexpr bool has_value() const noexcept
            { return this->value_.has_value(); };

            constexpr value_type& value() &
            { return this->value_.value(); };

            constexpr const value_type& value() const&
            { return this->value_.value(); };

            constexpr value_type&& value() &&
            { return std::move(this->value_.value()); };

            constexpr const value_type&& value() const&&
            { return std::move(this->value_.value()); };

            template <typename Other>
            constexpr value_type value_or(Other&& other_value) const&
            { return this->value_or(std::forward<Other>(other_value)); }

            template <typename Other>
            constexpr value_type value_or(Other&& other_value) &&
            { return this->value_or(std::forward<Other>(other_value)); }

            void reset() noexcept
            { this->value_.reset(); };

            template <typename... Types>
            std::enable_if_t<
                std::is_constructible_v<value_type, Types&&...>,
                value_type&
            > emplace(Types&&... values)
            { return this->value_(std::forward<Types>(values)...); }

            template <typename T, typename... Types>
            std::enable_if_t<
                std::is_constructible_v<value_type, std::initializer_list<T>&, Types&&...>,
                value_type&
            > emplace(std::initializer_list<T> il, Types&&... values)
            { return this->value_.emplace(il, std::forward<Types>(values)...); }

            constexpr std::optional<value_type>& optional() & noexcept
            { return this->value_; };

            constexpr const std::optional<value_type>& optional() const& noexcept
            { return this->value_; };

            constexpr std::optional<value_type>&& optional() && noexcept
            { return std::move(this->value_); };

            constexpr const std::optional<value_type>&& optional() const&& noexcept
            { return std::move(this->value_); };

            constexpr metadata_type& metadata() noexcept
            { return this->meta_; };

            constexpr const metadata_type& metadata() const noexcept
            { return this->meta_; };

            constexpr matcher_type& matcher() noexcept
            { return this->matcher_; };

            constexpr const matcher_type& matcher() const noexcept
            { return this->matcher_; };

            constexpr applier_type& applier() noexcept
            { return this->applier_; };

            constexpr const applier_type& applier() const noexcept
            { return this->applier_; };

            template <typename... Types>
            constexpr decltype(auto) match(Types&&... values) noexcept
            { return invoke_matcher(this->matcher_, std::forward<Types>(values)...); }

            template <typename... Types>
            constexpr decltype(auto) match(Types&&... values) const
            { return invoke_matcher(this->matcher_, std::forward<Types>(values)...); }

            template <typename... Types>
            constexpr decltype(auto) apply(Types&&... values) noexcept
            { return invoke_applier(this->applier_, std::forward<Types>(values)...); }

            template <typename... Types>
            constexpr decltype(auto) apply(Types&&... values) const
            { return invoke_applier(this->applier_, std::forward<Types>(values)...); }

        private:
            std::optional<value_type> value_;
            metadata_type             meta_;
            matcher_type              matcher_;
            applier_type              applier_;

            template <typename... MeArgs, typename... VaArgs, typename... MaArgs, typename... ApArgs, size_t... MeIdx, size_t... VaIdx, size_t... MaIdx, size_t... ApIdx>
            constexpr optional_storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<VaArgs...> value_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args, std::integer_sequence<size_t, MeIdx...>, std::integer_sequence<size_t, VaIdx...>, std::integer_sequence<size_t, MaIdx...>, std::integer_sequence<size_t, ApIdx...>)
                : value_(std::in_place, std::forward<VaArgs>(std::get<VaIdx>(value_args))...), meta_(std::forward<MeArgs>(std::get<MeIdx>(meta_args))...), matcher_(std::forward<MaArgs>(std::get<MaIdx>(matcher_args))...), applier_(std::forward<ApArgs>(std::get<ApIdx>(applier_args))...)
            {}
    };

    template <typename Me, typename Va, typename Ma, typename Ap>
    optional_storage(Me, Va, Ma, Ap) -> optional_storage<Me, Va, Ma, Ap>;

    template <typename Meta, typename Matcher, typename Applier, typename Value>
    auto make_optional_storage(Value&& value)
    {
        using result_type = optional_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Value>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Value>(value)
        );
    }

    template <typename Meta, typename Value, typename Matcher, typename Applier>
    auto make_optional_storage(Matcher&& matcher, Applier&& applier)
    {
        using result_type = optional_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Value>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Matcher>(matcher),
            std::forward<Applier>(applier)
        );
    }

    template <typename Meta, typename Value, typename Matcher, typename Applier>
    auto make_optional_storage(Value&& value, Matcher&& matcher, Applier&& applier)
    {
        using result_type = optional_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Value>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Value>(value),
            std::forward<Matcher>(matcher),
            std::forward<Applier>(applier)
        );
    }

    template <typename Meta, typename Value, typename Matcher, typename Applier>
    auto make_optional_storage(Meta&& meta, Value&& value, Matcher&& matcher, Applier&& applier)
    {
        using result_type = optional_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Value>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Meta>(meta),
            std::forward<Value>(value),
            std::forward<Matcher>(matcher),
            std::forward<Applier>(applier)
        );
    }

} // namespace commander
