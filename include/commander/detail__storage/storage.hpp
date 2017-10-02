//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../applier.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "../matcher.hpp"

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename Meta, typename Value, typename Matcher, typename Applier>
    class storage
    {
        public:
            using metadata_type = Meta;
            using value_type    = Value;
            using matcher_type  = Matcher;
            using applier_type  = Applier;

            constexpr explicit storage() = default;

            constexpr explicit storage(const storage<metadata_type, value_type, matcher_type, applier_type>&) = default;

            constexpr explicit storage(storage<metadata_type, value_type, matcher_type, applier_type>&&) = default;

            template <typename Va>
            constexpr explicit storage(Va&& default_value) : value_(std::forward<Va>(default_value))
            {}

            template <typename Ma, typename Ap>
            constexpr explicit storage(Ma&& matcher, Ap&& applier) : matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Va, typename Ma, typename Ap>
            constexpr explicit storage(Va&& default_value, Ma&& matcher, Ap&& applier) : value_(std::forward<Va>(default_value)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Me, typename Va, typename Ma, typename Ap>
            constexpr explicit storage(Me&& meta, Va&& default_value, Ma&& matcher, Ap&& applier) : value_(std::forward<Va>(default_value)), meta_(std::forward<Me>(meta)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename... MeArgs, typename... VaArgs, typename... MaArgs, typename... ApArgs>
            constexpr explicit storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<VaArgs...> value_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args)
                : storage(std::piecewise_construct, meta_args, value_args, matcher_args, applier_args, std::make_index_sequence<sizeof...(MeArgs)>(), std::make_index_sequence<sizeof...(VaArgs)>(), std::make_index_sequence<sizeof...(MaArgs)>(), std::make_index_sequence<sizeof...(ApArgs)>())
            {}

            constexpr storage<metadata_type, value_type, matcher_type, applier_type>& operator =(const storage<metadata_type, value_type, matcher_type, applier_type>&) = default;

            constexpr storage<metadata_type, value_type, matcher_type, applier_type>& operator =(storage<metadata_type, value_type, matcher_type, applier_type>&&) = default;

            template <typename T>
            constexpr storage<metadata_type, value_type, matcher_type, applier_type>& operator =(T&& value)
            {
                this->value_ = std::forward<T>(value);
                return *this;
            }

            constexpr value_type* operator ->()
            { return &(this->value_); };

            constexpr const value_type* operator ->() const
            { return &(this->value_); };

            constexpr value_type& operator *() &
            { return this->value_; };

            constexpr const value_type& operator *() const&
            { return this->value_; };

            constexpr value_type&& operator *() &&
            { return std::move(this->value_); };

            constexpr const value_type&& operator *() const&&
            { return std::move(this->value_); };

            constexpr value_type& value() & noexcept
            { return this->value_; };

            constexpr const value_type& value() const& noexcept
            { return this->value_; };

            constexpr value_type&& value() && noexcept
            { return std::move(this->value_); };

            constexpr const value_type&& value() const&& noexcept
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
            value_type    value_;
            metadata_type meta_;
            matcher_type  matcher_;
            applier_type  applier_;

            template <typename... MeArgs, typename... VaArgs, typename... MaArgs, typename... ApArgs, size_t... MeIdx, size_t... VaIdx, size_t... MaIdx, size_t... ApIdx>
            constexpr storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<VaArgs...> value_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args, std::integer_sequence<size_t, MeIdx...>, std::integer_sequence<size_t, VaIdx...>, std::integer_sequence<size_t, MaIdx...>, std::integer_sequence<size_t, ApIdx...>)
                : value_(std::forward<VaArgs>(std::get<VaIdx>(value_args))...), meta_(std::forward<MeArgs>(std::get<MeIdx>(meta_args))...), matcher_(std::forward<MaArgs>(std::get<MaIdx>(matcher_args))...), applier_(std::forward<ApArgs>(std::get<ApIdx>(applier_args))...)
            {}
    };

    template <typename Me, typename Va, typename Ma, typename Ap>
    storage(Me, Va, Ma, Ap) -> storage<Me, Va, Ma, Ap>;

    template <typename Meta, typename Matcher, typename Applier, typename Value>
    auto make_storage(Value&& value)
    {
        using result_type = storage<
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
    auto make_storage(Matcher&& matcher, Applier&& applier)
    {
        using result_type = storage<
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
    auto make_storage(Value&& value, Matcher&& matcher, Applier&& applier)
    {
        using result_type = storage<
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
    auto make_storage(Meta&& meta, Value&& value, Matcher&& matcher, Applier&& applier)
    {
        using result_type = storage<
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
