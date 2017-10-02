//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

#define CHECK_TUPLE_1(r, x0)         BOOST_CHECK((r) == std::forward_as_tuple(x0))
#define CHECK_TUPLE_2(r, x0, x1)     BOOST_CHECK((r) == std::forward_as_tuple((x0), (x1)))
#define CHECK_TUPLE_3(r, x0, x1, x2) BOOST_CHECK((r) == std::forward_as_tuple((x0), (x1), (x2)))

#define CHECK_EXCEPTION_A(c, e, a)     BOOST_CHECK_EXCEPTION((c), e, [&](const auto& ex) -> bool { return ex.argument() == (a); })
#define CHECK_EXCEPTION_AH(c, e, a, h) BOOST_CHECK_EXCEPTION((c), e, [&](const auto& ex) -> bool { return (ex.argument() == (a) && ex.header() == (h)); })

template <typename FirstCallback, typename SecondCallback>
class splited_callback
{
    public:

        splited_callback() = default;

        splited_callback(const splited_callback<FirstCallback, SecondCallback>&) = default;

        splited_callback(size_t count, FirstCallback first, SecondCallback second) : count_(count), firstcallback_(first), secondcallback_(second)
        {};

        template <typename... Types>
        int operator ()(Types&&... types)
        {
            if (this->count_ > 0) {
                this->count_ -= 1;
                return this->firstcallback_(std::forward<Types>(types)...);
            }
            else {
                return this->secondcallback_(std::forward<Types>(types)...);
            }
        }

        void reset(size_t count)
        { this->count_ = count; };

    private:
        size_t         count_;
        FirstCallback  firstcallback_;
        SecondCallback secondcallback_;
};

template <typename FirstCallback, typename SecondCallback>
auto make_splited_callback(size_t count, FirstCallback first, SecondCallback second)
{ return splited_callback<FirstCallback, SecondCallback>(count, first, second); }
