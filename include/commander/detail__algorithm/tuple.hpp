//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

namespace commander
{

    namespace detail
    {
        template <typename Seq>
        struct tuple_visit_worker;

        template <size_t... Indexes>
        struct tuple_visit_worker<std::index_sequence<Indexes...>>
        {
            template <typename Callable, typename Tuple>
            constexpr static bool visit(Callable&& callable, Tuple&& tuple)
            { return false || (visit_member_(callable, std::get<Indexes>(std::forward<Tuple>(tuple))) || ...); }

            private:
                template <typename Callable, typename T>
                constexpr static bool visit_member_(Callable&& callable, T&& mamber)
                {
                    std::forward<Callable>(callable)(mamber);
                    return false;
                }

        };

        template <typename Callable, typename Tuple>
        constexpr bool tuple_visit_invoker(Callable&& callable, Tuple&& tuple)
        {
            return tuple_visit_worker<
                std::make_index_sequence<
                    std::tuple_size_v<std::remove_reference_t<Tuple>>
                >
            >::visit(std::forward<Callable>(callable), std::forward<Tuple>(tuple));
        }

        template <typename Seq>
        struct tuple_visit_conjunction_worker;

        template <size_t... Indexes>
        struct tuple_visit_conjunction_worker<std::index_sequence<Indexes...>>
        {
            template <typename Callable, typename Tuple>
            constexpr static decltype(auto) visit(Callable&& callable, Tuple&& tuple)
            { return (callable(std::get<Indexes>(std::forward<Tuple>(tuple))) && ...); }
        };

        template <typename Callable, typename Tuple>
        constexpr decltype(auto) tuple_visit_conjunction_invoker(Callable&& callable, Tuple&& tuple)
        {
            return tuple_visit_conjunction_worker<
                std::make_index_sequence<
                    std::tuple_size_v<std::remove_reference_t<Tuple>>
                >
            >::visit(std::forward<Callable>(callable), std::forward<Tuple>(tuple));
        }

        template <typename Seq>
        struct tuple_visit_disjunction_worker;

        template <size_t... Indexes>
        struct tuple_visit_disjunction_worker<std::index_sequence<Indexes...>>
        {
            template <typename Callable, typename Tuple>
            constexpr static decltype(auto) visit(Callable&& callable, Tuple&& tuple)
            { return (callable(std::get<Indexes>(std::forward<Tuple>(tuple))) || ...); }
        };

        template <typename Callable, typename Tuple>
        constexpr decltype(auto) tuple_visit_disjunction_invoker(Callable&& callable, Tuple&& tuple)
        {
            return tuple_visit_disjunction_worker<
                std::make_index_sequence<
                    std::tuple_size_v<std::remove_reference_t<Tuple>>
                >
            >::visit(std::forward<Callable>(callable), std::forward<Tuple>(tuple));
        }

    } // namespace detail

    template <typename Callable, typename... Tuples>
    constexpr void tuple_visit(Callable&& callable, Tuples&&... tuples)
    { (detail::tuple_visit_invoker(callable, std::forward<Tuples>(tuples)) || ...); }

    template <typename Callable, typename... Tuples>
    constexpr decltype(auto) tuple_visit_conjunction(Callable&& callable, Tuples&&... tuples)
    { return (detail::tuple_visit_conjunction_invoker(callable, std::forward<Tuples>(tuples)) && ...); }

    template <typename Callable, typename... Tuples>
    constexpr decltype(auto) tuple_visit_disjunction(Callable&& callable, Tuples&&... tuples)
    { return (detail::tuple_visit_disjunction_invoker(callable, std::forward<Tuples>(tuples)) || ...); }

} // namespace commander
