//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <exception>
#include <stdexcept>
#include <string>
#include <utility>

namespace commander
{

    template <typename Argument>
    class argument_error : public std::runtime_error
    {
        public:
            using argument_type   = Argument;

            using value_type      = Argument;
            using reference       = Argument&;
            using const_reference = const Argument&;

            template <typename Arg>
            explicit argument_error(Arg&& argument) : runtime_error("argument_error"), argument_(std::forward<Arg>(argument))
            {}

            template <typename Arg>
            explicit argument_error(const std::string& what_arg, Arg&& argument) : runtime_error(what_arg), argument_(std::forward<Arg>(argument))
            {}

            template <typename Arg>
            explicit argument_error(const char* what_arg, Arg&& argument) : runtime_error(what_arg), argument_(std::forward<Arg>(argument))
            {}

            virtual ~argument_error() = default;

            virtual const_reference argument() const
            { return this->argument_; };

        private:
            value_type argument_;
    };

} // namespace commander
