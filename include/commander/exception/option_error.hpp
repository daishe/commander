//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "argument_error.hpp"

#include <string>
#include <utility>

namespace commander
{

    template <typename Argument, typename Header>
    class option_error : public argument_error<Argument>
    {
        public:
            using argument_type            = typename argument_error<Argument>::value_type;
            using argument_reference       = typename argument_error<Argument>::reference;
            using argument_const_reference = typename argument_error<Argument>::const_reference;

            using header_type            = Header;
            using header_reference       = Header&;
            using header_const_reference = const Header&;

            template <typename Head>
            explicit option_error(Head&& header) : argument_error<Argument>("option_error", header), header_(std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit option_error(Arg&& argument, Head&& header) : argument_error<Argument>("option_error", argument), header_(std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit option_error(const std::string& what_arg, Head&& header) : argument_error<Argument>(what_arg, header), header_(std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit option_error(const std::string& what_arg, Arg&& argument, Head&& header) : argument_error<Argument>(what_arg, argument), header_(std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit option_error(const char* what_arg, Head&& header) : argument_error<Argument>(what_arg, header), header_(std::forward<Head>(header))
            {}

            template <typename Arg, typename Head>
            explicit option_error(const char* what_arg, Arg&& argument, Head&& header) : argument_error<Argument>(what_arg, argument), header_(std::forward<Head>(header))
            {}

            virtual ~option_error() = default;

            virtual header_const_reference header() const
            { return this->header_; };

        private:
            header_type header_;
    };

} // namespace commander
