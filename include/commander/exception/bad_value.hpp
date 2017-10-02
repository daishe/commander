//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "input_not_consumed.hpp"

#include <string>
#include <utility>

namespace commander
{

    template <typename Argument, typename Header>
    class bad_value : public input_not_consumed<Argument, Header>
    {
        public:
            using argument_type            = typename input_not_consumed<Argument, Header>::argument_type;
            using argument_reference       = typename input_not_consumed<Argument, Header>::argument_reference;
            using argument_const_reference = typename input_not_consumed<Argument, Header>::argument_const_reference;

            using header_type            = typename input_not_consumed<Argument, Header>::header_type;
            using header_reference       = typename input_not_consumed<Argument, Header>::header_reference;
            using header_const_reference = typename input_not_consumed<Argument, Header>::header_const_reference;

            template <typename Head>
            explicit bad_value(Head&& header) : input_not_consumed<Argument, Header>("bad_value", std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit bad_value(Arg&& argument, Head&& header) : input_not_consumed<Argument, Header>("bad_value", std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            template <typename Head>
            explicit bad_value(const std::string& what_arg, Head&& header) : input_not_consumed<Argument, Header>(what_arg, std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit bad_value(const std::string& what_arg, Arg&& argument, Head&& header) : input_not_consumed<Argument, Header>(what_arg, std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            template <typename Head>
            explicit bad_value(const char* what_arg, Head&& header) : input_not_consumed<Argument, Header>(what_arg, std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit bad_value(const char* what_arg, Arg&& argument, Head&& header) : input_not_consumed<Argument, Header>(what_arg, std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            virtual ~bad_value() = default;
    };

} // namespace commander
