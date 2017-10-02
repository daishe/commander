//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "option_error.hpp"

#include <string>
#include <utility>

namespace commander
{

    template <typename Argument, typename Header>
    class input_not_consumed : public option_error<Argument, Header>
    {
        public:
            using argument_type            = typename option_error<Argument, Header>::argument_type;
            using argument_reference       = typename option_error<Argument, Header>::argument_reference;
            using argument_const_reference = typename option_error<Argument, Header>::argument_const_reference;

            using header_type            = typename option_error<Argument, Header>::header_type;
            using header_reference       = typename option_error<Argument, Header>::header_reference;
            using header_const_reference = typename option_error<Argument, Header>::header_const_reference;

            template <typename Head>
            explicit input_not_consumed(Head&& header) : option_error<Argument, Header>("input_not_consumed", std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit input_not_consumed(Arg&& argument, Head&& header) : option_error<Argument, Header>("input_not_consumed", std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            template <typename Head>
            explicit input_not_consumed(const std::string& what_arg, Head&& header) : option_error<Argument, Header>(what_arg, std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit input_not_consumed(const std::string& what_arg, Arg&& argument, Head&& header) : option_error<Argument, Header>(what_arg, std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            template <typename Head>
            explicit input_not_consumed(const char* what_arg, Head&& header) : option_error<Argument, Header>(what_arg, std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit input_not_consumed(const char* what_arg, Arg&& argument, Head&& header) : option_error<Argument, Header>(what_arg, std::forward<Arg>(argument), std::forward<Head>(header))
            {}

            virtual ~input_not_consumed() = default;
    };

} // namespace commander
