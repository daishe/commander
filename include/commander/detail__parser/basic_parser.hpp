//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../algorithm.hpp"
#include "../exception.hpp"
#include "../no_value.hpp"
#include "../placeholder.hpp"

#include <iterator>
#include <optional>
#include <type_traits>
#include <utility>

namespace commander
{

    template <typename StringView, typename String>
    class basic_parser
    {
        public:
            using string_type      = String;
            using string_view_type = StringView;

            using value_type = std::optional<string_type>;

            basic_parser() = default;

            basic_parser(const basic_parser<string_view_type, string_type>&) = default;

            basic_parser(basic_parser<string_view_type, string_type>&&) = default;

            basic_parser<string_view_type, string_type>& operator =(const basic_parser<string_view_type, string_type>&) = default;

            basic_parser<string_view_type, string_type>& operator =(basic_parser<string_view_type, string_type>&&) = default;

            value_type& value()
            { return this->state_; };

            const value_type& value() const
            { return this->state_; };

            template <typename T, typename Callback>
            typename std::enable_if_t<
                std::is_same_v<string_view_type, T> ||
                std::is_constructible_v<string_view_type, T> ||
                std::is_convertible_v<T, string_view_type>,
                Callback
            > operator ()(T&& argument, Callback callback)
            {
                const string_view_type argument_view(argument);

                auto apply = [this, &callback](const auto& opt) {
                    if (std::get<2>(opt).is_last) {
                        if (option_has_value(std::get<0>(opt))) {
                            const string_view_type value_view(
                                std::get<0>(opt).data() + option_value_begin_offset(std::get<0>(opt)),
                                option_value_size(std::get<0>(opt))
                            );

                            if (!callback(std::get<0>(opt), std::get<1>(opt), value_view))
                                throw input_not_consumed<string_type, string_type>(std::get<0>(opt), std::get<1>(opt));
                        }
                        else {
                            if (!callback(std::get<0>(opt), std::get<1>(opt), placeholder))
                                this->value() = std::get<0>(opt);
                        }
                    }
                    else {
                        if (!callback(std::get<0>(opt), std::get<1>(opt), no_value))
                            throw missing_value_error<string_type, string_type>(std::get<0>(opt), std::get<1>(opt));
                    }
                };

                if (this->state_) {
                    this->apply_value_(std::forward<T>(argument), callback);
                }
                else {
                    if (is_parse_stop(argument_view))
                        this->state_ = argument_view;
                    else if (is_option(argument_view))
                        for_each_in_pack<string_view_type>(argument_view, apply);
                    else
                        this->apply_value_(std::forward<T>(argument), callback);
                }

                return callback;
            }

            template <typename T, typename Callback>
            typename std::enable_if_t<
                !std::is_same_v<string_view_type, T> &&
                !std::is_constructible_v<string_view_type, T> &&
                !std::is_convertible_v<T, string_view_type>,
                Callback
            > operator ()(T&& argument, Callback callback)
            {
                this->apply_value_(std::forward<T>(argument), callback);
                return callback;
            }

            void operator ()() const
            { this->finalize(); };

            operator bool() const
            { return this->is_finalizable(); };

            void finalize() const
            {
                auto throw_missing_value_error = [](const auto& opt) {
                    throw missing_value_error<string_type, string_type>(std::get<0>(opt), std::get<1>(opt));
                };

                if (!this->is_finalizable())
                    for_last_in_pack<string_view_type>(this->state_.value(), throw_missing_value_error);
            };

            bool is_finalizable() const
            { return !this->state_ || is_parse_stop(this->state_.value()); };

        private:
            value_type state_;

            template <typename T, typename Callback>
            void apply_value_(T&& argument, Callback&& callback)
            {
                auto apply = [&argument, &callback](const auto& opt) {
                    if (!callback(std::get<0>(opt), std::get<1>(opt), std::forward<T>(argument)))
                        throw input_not_consumed<string_type, string_type>(std::get<0>(opt), std::get<1>(opt));
                };

                if (this->state_) {
                    for_last_in_pack<string_view_type>(this->state_.value(), apply);

                    if (!is_parse_stop(this->state_.value()))
                        this->state_ = std::nullopt;
                }
                else {
                    for_parse_stop<string_view_type>(apply);
                }
            }
    };

} // namespace commander
