//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/no_value.hpp>

#include <boost/test/unit_test.hpp>

#include "structs.hpp"

#include <type_traits>

BOOST_AUTO_TEST_CASE( detection_test )
{
    namespace com = commander;

    {
        static_assert(!com::is_no_value<int>::value);
        static_assert(!com::is_no_value_v<int>);

        static_assert(!com::is_no_value<nullptr_t>::value);
        static_assert(!com::is_no_value_v<nullptr_t>);

        static_assert(!com::is_no_value<decltype(nullptr)>::value);
        static_assert(!com::is_no_value_v<decltype(nullptr)>);
    }

    {
        static_assert(com::is_no_value<com::no_value_t>::value);
        static_assert(com::is_no_value_v<com::no_value_t>);

        static_assert(com::is_no_value<decltype(com::no_value_t())>::value);
        static_assert(com::is_no_value_v<decltype(com::no_value_t())>);

        static_assert(com::is_no_value<decltype(com::no_value)>::value);
        static_assert(com::is_no_value_v<decltype(com::no_value)>);
    }

    {
        static_assert(com::is_no_value<custom_no_value>::value);
        static_assert(com::is_no_value_v<custom_no_value>);

        static_assert(com::is_no_value<decltype(custom_no_value())>::value);
        static_assert(com::is_no_value_v<decltype(custom_no_value())>);

        static_assert(!com::is_no_value<custom_struct>::value);
        static_assert(!com::is_no_value_v<custom_struct>);

        static_assert(!com::is_no_value<decltype(custom_struct())>::value);
        static_assert(!com::is_no_value_v<decltype(custom_struct())>);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(int(0));

        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr_t());

        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(nullptr);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](auto v)                 { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value_t());

        [](auto given) { [](auto v)                 { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](auto v)                 { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(com::no_value);
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(com::no_value);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](auto v)                 { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](const auto v)           { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](auto& v)                { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](const auto& v)          { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value<decltype(v)>::value); }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_no_value_v<decltype(v)>);      }(given); }(custom_no_value());

        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](auto v)                 { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_no_value_v<decltype(v)>);      }(given); }(custom_struct());
    }
}

BOOST_AUTO_TEST_CASE( detection_test_func )
{
    namespace com = commander;

    {
        int int_value;
        static_assert(!com::func::is_no_value(int_value).value);
        static_assert(!com::func::is_no_value_v(int_value));

        nullptr_t nullptr_t_value;
        static_assert(!com::func::is_no_value(nullptr_t_value).value);
        static_assert(!com::func::is_no_value_v(nullptr_t_value));

        static_assert(!com::func::is_no_value(nullptr).value);
        static_assert(!com::func::is_no_value_v(nullptr));
    }

    {
        com::no_value_t no_value_t_value;
        static_assert(com::func::is_no_value(no_value_t_value).value);
        static_assert(com::func::is_no_value_v(no_value_t_value));

        static_assert(com::func::is_no_value(com::no_value_t()).value);
        static_assert(com::func::is_no_value_v(com::no_value_t()));

        static_assert(com::func::is_no_value(com::no_value).value);
        static_assert(com::func::is_no_value_v(com::no_value));
    }

    {
        custom_no_value custom_no_value_value;
        static_assert(com::func::is_no_value(custom_no_value_value).value);
        static_assert(com::func::is_no_value_v(custom_no_value_value));

        static_assert(com::func::is_no_value(custom_no_value()).value);
        static_assert(com::func::is_no_value_v(custom_no_value()));

        custom_struct custom_struct_value;
        static_assert(!com::func::is_no_value(custom_struct_value).value);
        static_assert(!com::func::is_no_value_v(custom_struct_value));

        static_assert(!com::func::is_no_value(custom_struct()).value);
        static_assert(!com::func::is_no_value_v(custom_struct()));
    }

    {
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value(v).value); }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value_v(v));     }(given); }(int(0));

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr_t());

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value(v).value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value_v(v));     }(given); }(nullptr);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value_t());

        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value(v).value); }(given); }(com::no_value);
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value_v(v));     }(given); }(com::no_value);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](auto v)                 { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value(v).value); }(given); }(custom_no_value());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_no_value_v(v));     }(given); }(custom_no_value());

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value(v).value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_no_value_v(v));     }(given); }(custom_struct());
    }
}
