//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <commander/no_value.hpp>

#include <boost/test/unit_test.hpp>

#include "structs.hpp"

#include <type_traits>
#include <utility>

BOOST_AUTO_TEST_CASE( type_test )
{
    namespace com = commander;

    static_assert(std::is_same_v<com::no_value_t, std::remove_const_t<decltype(com::no_value)>>);

    [](auto given) { [](com::no_value_t)                  { /* by                value      */ }(given);            }(com::no_value);
    [](auto given) { [](com::no_value_t)                  { /* by                value      */ }(given);            }(com::no_value_t());
    [](auto given) { [](com::no_value_t)                  { /* by                value      */ }(given);            }(custom_no_value());
    [](auto given) { [](volatile com::no_value_t)         { /* by       volatile value      */ }(given);            }(com::no_value);
    [](auto given) { [](volatile com::no_value_t)         { /* by       volatile value      */ }(given);            }(com::no_value_t());
    [](auto given) { [](volatile com::no_value_t)         { /* by       volatile value      */ }(given);            }(custom_no_value());
    [](auto given) { [](const com::no_value_t)            { /* by const          value      */ }(given);            }(com::no_value);
    [](auto given) { [](const com::no_value_t)            { /* by const          value      */ }(given);            }(com::no_value_t());
    [](auto given) { [](const com::no_value_t)            { /* by const          value      */ }(given);            }(custom_no_value());
    [](auto given) { [](const volatile com::no_value_t)   { /* by const volatile value      */ }(given);            }(com::no_value);
    [](auto given) { [](const volatile com::no_value_t)   { /* by const volatile value      */ }(given);            }(com::no_value_t());
    [](auto given) { [](const volatile com::no_value_t)   { /* by const volatile value      */ }(given);            }(custom_no_value());
    [](auto given) { [](com::no_value_t&)                 { /* by                lreference */ }(given);            }(com::no_value);
    [](auto given) { [](com::no_value_t&)                 { /* by                lreference */ }(given);            }(com::no_value_t());
    [](auto given) { [](com::no_value_t&)                 { /* by                lreference */ }(given);            }(custom_no_value());
    [](auto given) { [](volatile com::no_value_t&)        { /* by       volatile lreference */ }(given);            }(com::no_value);
    [](auto given) { [](volatile com::no_value_t&)        { /* by       volatile lreference */ }(given);            }(com::no_value_t());
    [](auto given) { [](volatile com::no_value_t&)        { /* by       volatile lreference */ }(given);            }(custom_no_value());
    [](auto given) { [](const com::no_value_t&)           { /* by const          lreference */ }(given);            }(com::no_value);
    [](auto given) { [](const com::no_value_t&)           { /* by const          lreference */ }(given);            }(com::no_value_t());
    [](auto given) { [](const com::no_value_t&)           { /* by const          lreference */ }(given);            }(custom_no_value());
    [](auto given) { [](const volatile com::no_value_t&)  { /* by const volatile lreference */ }(given);            }(com::no_value);
    [](auto given) { [](const volatile com::no_value_t&)  { /* by const volatile lreference */ }(given);            }(com::no_value_t());
    [](auto given) { [](const volatile com::no_value_t&)  { /* by const volatile lreference */ }(given);            }(custom_no_value());
    [](auto given) { [](com::no_value_t&&)                { /* by                rreference */ }(std::move(given)); }(com::no_value);
    [](auto given) { [](com::no_value_t&&)                { /* by                rreference */ }(std::move(given)); }(com::no_value_t());
    [](auto given) { [](com::no_value_t&&)                { /* by                rreference */ }(std::move(given)); }(custom_no_value());
    [](auto given) { [](volatile com::no_value_t&&)       { /* by       volatile rreference */ }(std::move(given)); }(com::no_value);
    [](auto given) { [](volatile com::no_value_t&&)       { /* by       volatile rreference */ }(std::move(given)); }(com::no_value_t());
    [](auto given) { [](volatile com::no_value_t&&)       { /* by       volatile rreference */ }(std::move(given)); }(custom_no_value());
    [](auto given) { [](const com::no_value_t&&)          { /* by const          rreference */ }(std::move(given)); }(com::no_value);
    [](auto given) { [](const com::no_value_t&&)          { /* by const          rreference */ }(std::move(given)); }(com::no_value_t());
    [](auto given) { [](const com::no_value_t&&)          { /* by const          rreference */ }(std::move(given)); }(custom_no_value());
    [](auto given) { [](const volatile com::no_value_t&&) { /* by const volatile rreference */ }(std::move(given)); }(com::no_value);
    [](auto given) { [](const volatile com::no_value_t&&) { /* by const volatile rreference */ }(std::move(given)); }(com::no_value_t());
    [](auto given) { [](const volatile com::no_value_t&&) { /* by const volatile rreference */ }(std::move(given)); }(custom_no_value());
}
