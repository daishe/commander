//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../applier.hpp"
#include "../detail__type_traits/unwrap_reference_wrapper.hpp"
#include "../matcher.hpp"
#include "../no_value.hpp"

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename Meta, typename Matcher, typename Applier>
    class empty_storage
    {
        public:
            using metadata_type = Meta;
            using value_type    = no_value_t;
            using matcher_type  = Matcher;
            using applier_type  = Applier;

            constexpr explicit empty_storage() = default;

            constexpr explicit empty_storage(const empty_storage<metadata_type, matcher_type, applier_type>&) = default;

            constexpr explicit empty_storage(empty_storage<metadata_type, matcher_type, applier_type>&&) = default;

            template <typename Ma, typename Ap>
            constexpr explicit empty_storage(Ma&& matcher, Ap&& applier) : matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename Me, typename Ma, typename Ap>
            constexpr explicit empty_storage(Me&& meta, Ma&& matcher, Ap&& applier) : meta_(std::forward<Me>(meta)), matcher_(std::forward<Ma>(matcher)), applier_(std::forward<Ap>(applier))
            {}

            template <typename... MeArgs, typename... MaArgs, typename... ApArgs>
            constexpr explicit empty_storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args)
                : empty_storage(std::piecewise_construct, meta_args, matcher_args, applier_args, std::make_index_sequence<sizeof...(MeArgs)>(), std::make_index_sequence<sizeof...(MaArgs)>(), std::make_index_sequence<sizeof...(ApArgs)>())
            {}

            constexpr empty_storage<metadata_type, matcher_type, applier_type>& operator =(const empty_storage<metadata_type, matcher_type, applier_type>&) = default;

            constexpr empty_storage<metadata_type, matcher_type, applier_type>& operator =(empty_storage<metadata_type, matcher_type, applier_type>&&) = default;

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

            template <typename... MeArgs, typename... MaArgs, typename... ApArgs, size_t... MeIdx, size_t... MaIdx, size_t... ApIdx>
            constexpr empty_storage(std::piecewise_construct_t, std::tuple<MeArgs...> meta_args, std::tuple<MaArgs...> matcher_args, std::tuple<ApArgs...> applier_args, std::integer_sequence<size_t, MeIdx...>, std::integer_sequence<size_t, MaIdx...>, std::integer_sequence<size_t, ApIdx...>)
                : meta_(std::forward<MeArgs>(std::get<MeIdx>(meta_args))...), matcher_(std::forward<MaArgs>(std::get<MaIdx>(matcher_args))...), applier_(std::forward<ApArgs>(std::get<ApIdx>(applier_args))...)
            {}
    };

    template <typename Me, typename Ma, typename Ap>
    empty_storage(Me, Ma, Ap) -> empty_storage<Me, Ma, Ap>;

    template <typename Meta, typename Matcher, typename Applier>
    auto make_empty_storage(Matcher&& matcher, Applier&& applier)
    {
        using result_type = empty_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Matcher>(matcher),
            std::forward<Applier>(applier)
        );
    }

    template <typename Meta, typename Matcher, typename Applier>
    auto make_empty_storage(Meta&& meta, Matcher&& matcher, Applier&& applier)
    {
        using result_type = empty_storage<
            detail::unwrap_reference_wrapper_t<std::decay_t<Meta>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Matcher>>,
            detail::unwrap_reference_wrapper_t<std::decay_t<Applier>>
        >;
        return result_type(
            std::forward<Meta>(meta),
            std::forward<Matcher>(matcher),
            std::forward<Applier>(applier)
        );
    }

} // namespace commander
