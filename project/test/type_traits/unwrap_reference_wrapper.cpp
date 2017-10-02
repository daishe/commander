//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/detail__type_traits/unwrap_reference_wrapper.hpp>

#include <boost/test/unit_test.hpp>

#include <functional>

BOOST_AUTO_TEST_CASE( is_reference_wrapper )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_reference_wrapper<               int  >::value);
        static_assert(!comd::is_reference_wrapper<      volatile int  >::value);
        static_assert(!comd::is_reference_wrapper<const          int  >::value);
        static_assert(!comd::is_reference_wrapper<const volatile int  >::value);
        static_assert(!comd::is_reference_wrapper<               int& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile int& >::value);
        static_assert(!comd::is_reference_wrapper<const          int& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile int& >::value);
        static_assert(!comd::is_reference_wrapper<               int&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile int&&>::value);
        static_assert(!comd::is_reference_wrapper<const          int&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile int&&>::value);
    }

    {
        static_assert( comd::is_reference_wrapper<               std::reference_wrapper<int>  >::value);
        static_assert( comd::is_reference_wrapper<      volatile std::reference_wrapper<int>  >::value);
        static_assert( comd::is_reference_wrapper<const          std::reference_wrapper<int>  >::value);
        static_assert( comd::is_reference_wrapper<const volatile std::reference_wrapper<int>  >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<int>& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<int>& >::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<int>& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<int>& >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<int>&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<int>&&>::value);
    }

    {
        static_assert( comd::is_reference_wrapper<               std::reference_wrapper<               int>  >::value);
        static_assert( comd::is_reference_wrapper<               std::reference_wrapper<      volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<               std::reference_wrapper<const          int>  >::value);
        static_assert( comd::is_reference_wrapper<               std::reference_wrapper<const volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<      volatile std::reference_wrapper<               int>  >::value);
        static_assert( comd::is_reference_wrapper<      volatile std::reference_wrapper<      volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<      volatile std::reference_wrapper<const          int>  >::value);
        static_assert( comd::is_reference_wrapper<      volatile std::reference_wrapper<const volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<const          std::reference_wrapper<               int>  >::value);
        static_assert( comd::is_reference_wrapper<const          std::reference_wrapper<      volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<const          std::reference_wrapper<const          int>  >::value);
        static_assert( comd::is_reference_wrapper<const          std::reference_wrapper<const volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<const volatile std::reference_wrapper<               int>  >::value);
        static_assert( comd::is_reference_wrapper<const volatile std::reference_wrapper<      volatile int>  >::value);
        static_assert( comd::is_reference_wrapper<const volatile std::reference_wrapper<const          int>  >::value);
        static_assert( comd::is_reference_wrapper<const volatile std::reference_wrapper<const volatile int>  >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<               int>& >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<      volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<const          int>& >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<const volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<               int>& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<      volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<const          int>& >::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<const volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<               int>& >::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<      volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<const          int>& >::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<const volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<               int>& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<      volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<const          int>& >::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<const volatile int>& >::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<               int>&&>::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<      volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<const          int>&&>::value);
        static_assert(!comd::is_reference_wrapper<               std::reference_wrapper<const volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<               int>&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<      volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<const          int>&&>::value);
        static_assert(!comd::is_reference_wrapper<      volatile std::reference_wrapper<const volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<               int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<      volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<const          int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const          std::reference_wrapper<const volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<               int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<      volatile int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<const          int>&&>::value);
        static_assert(!comd::is_reference_wrapper<const volatile std::reference_wrapper<const volatile int>&&>::value);
    }
}

BOOST_AUTO_TEST_CASE( is_reference_wrapper_v )
{
    namespace comd = commander::detail;

    {
        static_assert(!comd::is_reference_wrapper_v<               int  >);
        static_assert(!comd::is_reference_wrapper_v<      volatile int  >);
        static_assert(!comd::is_reference_wrapper_v<const          int  >);
        static_assert(!comd::is_reference_wrapper_v<const volatile int  >);
        static_assert(!comd::is_reference_wrapper_v<               int& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile int& >);
        static_assert(!comd::is_reference_wrapper_v<const          int& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile int& >);
        static_assert(!comd::is_reference_wrapper_v<               int&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile int&&>);
        static_assert(!comd::is_reference_wrapper_v<const          int&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile int&&>);
    }

    {
        static_assert( comd::is_reference_wrapper_v<               std::reference_wrapper<int>  >);
        static_assert( comd::is_reference_wrapper_v<      volatile std::reference_wrapper<int>  >);
        static_assert( comd::is_reference_wrapper_v<const          std::reference_wrapper<int>  >);
        static_assert( comd::is_reference_wrapper_v<const volatile std::reference_wrapper<int>  >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<int>& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<int>& >);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<int>& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<int>& >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<int>&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<int>&&>);
    }

    {
        static_assert( comd::is_reference_wrapper_v<               std::reference_wrapper<               int>  >);
        static_assert( comd::is_reference_wrapper_v<               std::reference_wrapper<      volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<               std::reference_wrapper<const          int>  >);
        static_assert( comd::is_reference_wrapper_v<               std::reference_wrapper<const volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<      volatile std::reference_wrapper<               int>  >);
        static_assert( comd::is_reference_wrapper_v<      volatile std::reference_wrapper<      volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const          int>  >);
        static_assert( comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<const          std::reference_wrapper<               int>  >);
        static_assert( comd::is_reference_wrapper_v<const          std::reference_wrapper<      volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<const          std::reference_wrapper<const          int>  >);
        static_assert( comd::is_reference_wrapper_v<const          std::reference_wrapper<const volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<const volatile std::reference_wrapper<               int>  >);
        static_assert( comd::is_reference_wrapper_v<const volatile std::reference_wrapper<      volatile int>  >);
        static_assert( comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const          int>  >);
        static_assert( comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const volatile int>  >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<               int>& >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<      volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<const          int>& >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<const volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<               int>& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<      volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const          int>& >);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<               int>& >);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<      volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<const          int>& >);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<const volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<               int>& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<      volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const          int>& >);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const volatile int>& >);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<               int>&&>);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<      volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<const          int>&&>);
        static_assert(!comd::is_reference_wrapper_v<               std::reference_wrapper<const volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<               int>&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const          int>&&>);
        static_assert(!comd::is_reference_wrapper_v<      volatile std::reference_wrapper<const volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<               int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<      volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<const          int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const          std::reference_wrapper<const volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<               int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const          int>&&>);
        static_assert(!comd::is_reference_wrapper_v<const volatile std::reference_wrapper<const volatile int>&&>);
    }
}

BOOST_AUTO_TEST_CASE( unwrap_reference_wrapper )
{
    namespace comd = commander::detail;

    {
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               int  >::type,                int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile int  >::type,       volatile int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          int  >::type, const          int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile int  >::type, const volatile int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               int& >::type,                int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile int& >::type,       volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          int& >::type, const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile int& >::type, const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               int&&>::type,                int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile int&&>::type,       volatile int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          int&&>::type, const          int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile int&&>::type, const volatile int&&>);
    }

    {
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<               int>  >::type,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<      volatile int>  >::type,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const          int>  >::type,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const volatile int>  >::type,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<               int>  >::type,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<      volatile int>  >::type,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const          int>  >::type,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const volatile int>  >::type,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<               int>  >::type,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<      volatile int>  >::type,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const          int>  >::type,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const volatile int>  >::type,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<               int>  >::type,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<      volatile int>  >::type,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const          int>  >::type,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const volatile int>  >::type,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<               int>& >::type,                std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<      volatile int>& >::type,                std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const          int>& >::type,                std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const volatile int>& >::type,                std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<               int>& >::type,       volatile std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<      volatile int>& >::type,       volatile std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const          int>& >::type,       volatile std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const volatile int>& >::type,       volatile std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<               int>& >::type, const          std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<      volatile int>& >::type, const          std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const          int>& >::type, const          std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const volatile int>& >::type, const          std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<               int>& >::type, const volatile std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<      volatile int>& >::type, const volatile std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const          int>& >::type, const volatile std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const volatile int>& >::type, const volatile std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<               int>&&>::type,                std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<      volatile int>&&>::type,                std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const          int>&&>::type,                std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<               std::reference_wrapper<const volatile int>&&>::type,                std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<               int>&&>::type,       volatile std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<      volatile int>&&>::type,       volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const          int>&&>::type,       volatile std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<      volatile std::reference_wrapper<const volatile int>&&>::type,       volatile std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<               int>&&>::type, const          std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<      volatile int>&&>::type, const          std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const          int>&&>::type, const          std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const          std::reference_wrapper<const volatile int>&&>::type, const          std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<               int>&&>::type, const volatile std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<      volatile int>&&>::type, const volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const          int>&&>::type, const volatile std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper<const volatile std::reference_wrapper<const volatile int>&&>::type, const volatile std::reference_wrapper<const volatile int>&&>);
    }
}

BOOST_AUTO_TEST_CASE( unwrap_reference_wrapper_t )
{
    namespace comd = commander::detail;

    {
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               int  >,                int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile int  >,       volatile int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          int  >, const          int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile int  >, const volatile int  >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               int& >,                int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile int& >,       volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          int& >, const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile int& >, const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               int&&>,                int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile int&&>,       volatile int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          int&&>, const          int&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile int&&>, const volatile int&&>);
    }

    {
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<               int>  >,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<      volatile int>  >,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const          int>  >,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const volatile int>  >,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<               int>  >,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<      volatile int>  >,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const          int>  >,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const volatile int>  >,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<               int>  >,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<      volatile int>  >,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const          int>  >,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const volatile int>  >,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<               int>  >,                                                       int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<      volatile int>  >,                                              volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const          int>  >,                                        const          int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const volatile int>  >,                                        const volatile int& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<               int>& >,                std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<      volatile int>& >,                std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const          int>& >,                std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const volatile int>& >,                std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<               int>& >,       volatile std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<      volatile int>& >,       volatile std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const          int>& >,       volatile std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const volatile int>& >,       volatile std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<               int>& >, const          std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<      volatile int>& >, const          std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const          int>& >, const          std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const volatile int>& >, const          std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<               int>& >, const volatile std::reference_wrapper<               int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<      volatile int>& >, const volatile std::reference_wrapper<      volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const          int>& >, const volatile std::reference_wrapper<const          int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const volatile int>& >, const volatile std::reference_wrapper<const volatile int>& >);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<               int>&&>,                std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<      volatile int>&&>,                std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const          int>&&>,                std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<               std::reference_wrapper<const volatile int>&&>,                std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<               int>&&>,       volatile std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<      volatile int>&&>,       volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const          int>&&>,       volatile std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<      volatile std::reference_wrapper<const volatile int>&&>,       volatile std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<               int>&&>, const          std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<      volatile int>&&>, const          std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const          int>&&>, const          std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const          std::reference_wrapper<const volatile int>&&>, const          std::reference_wrapper<const volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<               int>&&>, const volatile std::reference_wrapper<               int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<      volatile int>&&>, const volatile std::reference_wrapper<      volatile int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const          int>&&>, const volatile std::reference_wrapper<const          int>&&>);
        static_assert(std::is_same_v<comd::unwrap_reference_wrapper_t<const volatile std::reference_wrapper<const volatile int>&&>, const volatile std::reference_wrapper<const volatile int>&&>);
    }
}
