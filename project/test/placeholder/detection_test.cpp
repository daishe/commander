//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/placeholder.hpp>

#include <boost/test/unit_test.hpp>

#include "structs.hpp"

#include <type_traits>

BOOST_AUTO_TEST_CASE( detection_test )
{
    namespace com = commander;

    {
        static_assert(!com::is_placeholder<int>::value);
        static_assert(!com::is_placeholder_v<int>);

        static_assert(!com::is_placeholder<nullptr_t>::value);
        static_assert(!com::is_placeholder_v<nullptr_t>);

        static_assert(!com::is_placeholder<decltype(nullptr)>::value);
        static_assert(!com::is_placeholder_v<decltype(nullptr)>);
    }

    {
        static_assert(com::is_placeholder<com::placeholder_t>::value);
        static_assert(com::is_placeholder_v<com::placeholder_t>);

        static_assert(com::is_placeholder<decltype(com::placeholder_t())>::value);
        static_assert(com::is_placeholder_v<decltype(com::placeholder_t())>);

        static_assert(com::is_placeholder<decltype(com::placeholder)>::value);
        static_assert(com::is_placeholder_v<decltype(com::placeholder)>);
    }

    {
        static_assert(com::is_placeholder<custom_placeholder>::value);
        static_assert(com::is_placeholder_v<custom_placeholder>);

        static_assert(com::is_placeholder<decltype(custom_placeholder())>::value);
        static_assert(com::is_placeholder_v<decltype(custom_placeholder())>);

        static_assert(!com::is_placeholder<custom_struct>::value);
        static_assert(!com::is_placeholder_v<custom_struct>);

        static_assert(!com::is_placeholder<decltype(custom_struct())>::value);
        static_assert(!com::is_placeholder_v<decltype(custom_struct())>);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(int(0));

        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr_t());

        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(nullptr);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder_t());

        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(com::placeholder);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](auto v)                 { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto v)        { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](const auto v)           { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto v)  { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](auto& v)                { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto& v)       { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](const auto& v)          { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder<decltype(v)>::value); }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto& v) { static_assert(com::is_placeholder_v<decltype(v)>);      }(given); }(custom_placeholder());

        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](auto v)                 { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder<decltype(v)>::value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::is_placeholder_v<decltype(v)>);      }(given); }(custom_struct());
    }
}

BOOST_AUTO_TEST_CASE( detection_test_func )
{
    namespace com = commander;

    {
        int int_value;
        static_assert(!com::func::is_placeholder(int_value).value);
        static_assert(!com::func::is_placeholder_v(int_value));

        nullptr_t nullptr_t_value;
        static_assert(!com::func::is_placeholder(nullptr_t_value).value);
        static_assert(!com::func::is_placeholder_v(nullptr_t_value));

        static_assert(!com::func::is_placeholder(nullptr).value);
        static_assert(!com::func::is_placeholder_v(nullptr));
    }

    {
        com::placeholder_t placeholder_t_value;
        static_assert(com::func::is_placeholder(placeholder_t_value).value);
        static_assert(com::func::is_placeholder_v(placeholder_t_value));

        static_assert(com::func::is_placeholder(com::placeholder_t()).value);
        static_assert(com::func::is_placeholder_v(com::placeholder_t()));

        static_assert(com::func::is_placeholder(com::placeholder).value);
        static_assert(com::func::is_placeholder_v(com::placeholder));
    }

    {
        custom_placeholder custom_placeholder_value;
        static_assert(com::func::is_placeholder(custom_placeholder_value).value);
        static_assert(com::func::is_placeholder_v(custom_placeholder_value));

        static_assert(com::func::is_placeholder(custom_placeholder()).value);
        static_assert(com::func::is_placeholder_v(custom_placeholder()));

        custom_struct custom_struct_value;
        static_assert(!com::func::is_placeholder(custom_struct_value).value);
        static_assert(!com::func::is_placeholder_v(custom_struct_value));

        static_assert(!com::func::is_placeholder(custom_struct()).value);
        static_assert(!com::func::is_placeholder_v(custom_struct()));
    }

    {
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder(v).value); }(given); }(int(0));
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder_v(v));     }(given); }(int(0));

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr_t());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr_t());

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder(v).value); }(given); }(nullptr);
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder_v(v));     }(given); }(nullptr);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder_t());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder_t());

        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder(v).value); }(given); }(com::placeholder);
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder_v(v));     }(given); }(com::placeholder);
    }

    {
        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](auto v)                 { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto v)        { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](const auto v)           { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto v)  { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](auto& v)                { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](volatile auto& v)       { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](const auto& v)          { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder(v).value); }(given); }(custom_placeholder());
        [](auto given) { [](const volatile auto& v) { static_assert(com::func::is_placeholder_v(v));     }(given); }(custom_placeholder());

        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](auto v)                 { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto v)        { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](const auto v)           { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto v)  { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](auto& v)                { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](volatile auto& v)       { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](const auto& v)          { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder(v).value); }(given); }(custom_struct());
        [](auto given) { [](const volatile auto& v) { static_assert(!com::func::is_placeholder_v(v));     }(given); }(custom_struct());
    }
}
