//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>

namespace commander
{

    namespace detail
    {

        template <typename T>
        struct decay
        {
            using type = std::decay_t<T>;
        };

        template <typename T>
        using decay_t = typename decay<T>::type;

        template <typename T>
        struct decay_without_c
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_const_v<std::remove_reference_t<T>>,
                std::add_const_t<std::decay_t<T>>,
                std::decay_t<T>
            >;
        };

        template <typename T>
        using decay_without_c_t = typename decay_without_c<T>::type;

        template <typename T>
        struct decay_without_v
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_volatile_v<std::remove_reference_t<T>>,
                std::add_volatile_t<std::decay_t<T>>,
                std::decay_t<T>
            >;
        };

        template <typename T>
        using decay_without_v_t = typename decay_without_v<T>::type;

        template <typename T>
        struct decay_without_r
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>>,
                    std::conditional_t<
                        std::is_lvalue_reference_v<T>,
                        std::add_lvalue_reference_t<std::decay_t<T>>,
                        std::conditional_t<
                            std::is_rvalue_reference_v<T>,
                            std::add_rvalue_reference_t<std::decay_t<T>>,
                            std::decay_t<T>
                        >
                    >,
                std::decay_t<T>
            >;
        };

        template <typename T>
        using decay_without_r_t = typename decay_without_r<T>::type;

        template <typename T>
        struct decay_without_lr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_lvalue_reference_v<T>,
                    std::add_lvalue_reference_t<std::decay_t<T>>,
                std::decay_t<T>
            >;
        };

        template <typename T>
        using decay_without_lr_t = typename decay_without_lr<T>::type;

        template <typename T>
        struct decay_without_rr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_rvalue_reference_v<T>,
                    std::add_rvalue_reference_t<std::decay_t<T>>,
                std::decay_t<T>
            >;
        };

        template <typename T>
        using decay_without_rr_t = typename decay_without_rr<T>::type;

        template <typename T>
        struct decay_without_cv
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_const_v<std::remove_reference_t<T>>,
                std::add_const_t<decay_without_v_t<T>>,
                decay_without_v_t<T>
            >;
        };

        template <typename T>
        using decay_without_cv_t = typename decay_without_cv<T>::type;

        template <typename T>
        struct decay_without_cr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>>,
                    std::conditional_t<
                        std::is_lvalue_reference_v<T>,
                        std::add_lvalue_reference_t<decay_without_c_t<T>>,
                        std::conditional_t<
                            std::is_rvalue_reference_v<T>,
                            std::add_rvalue_reference_t<decay_without_c_t<T>>,
                            decay_without_c_t<T>
                        >
                    >,
                decay_without_c_t<T>
            >;
        };

        template <typename T>
        using decay_without_cr_t = typename decay_without_cr<T>::type;

        template <typename T>
        struct decay_without_clr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_lvalue_reference_v<T>,
                    std::add_lvalue_reference_t<decay_without_c_t<T>>,
                decay_without_c_t<T>
            >;
        };

        template <typename T>
        using decay_without_clr_t = typename decay_without_clr<T>::type;

        template <typename T>
        struct decay_without_crr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_rvalue_reference_v<T>,
                    std::add_rvalue_reference_t<decay_without_c_t<T>>,
                decay_without_c_t<T>
            >;
        };

        template <typename T>
        using decay_without_crr_t = typename decay_without_crr<T>::type;

        template <typename T>
        struct decay_without_vr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>>,
                    std::conditional_t<
                        std::is_lvalue_reference_v<T>,
                        std::add_lvalue_reference_t<decay_without_v_t<T>>,
                        std::conditional_t<
                            std::is_rvalue_reference_v<T>,
                            std::add_rvalue_reference_t<decay_without_v_t<T>>,
                            decay_without_v_t<T>
                        >
                    >,
                decay_without_v_t<T>
            >;
        };

        template <typename T>
        using decay_without_vr_t = typename decay_without_vr<T>::type;

        template <typename T>
        struct decay_without_vlr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_lvalue_reference_v<T>,
                    std::add_lvalue_reference_t<decay_without_v_t<T>>,
                decay_without_v_t<T>
            >;
        };

        template <typename T>
        using decay_without_vlr_t = typename decay_without_vlr<T>::type;

        template <typename T>
        struct decay_without_vrr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_rvalue_reference_v<T>,
                    std::add_rvalue_reference_t<decay_without_v_t<T>>,
                decay_without_v_t<T>
            >;
        };

        template <typename T>
        using decay_without_vrr_t = typename decay_without_vrr<T>::type;

        template <typename T>
        struct decay_without_cvr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>>,
                    std::conditional_t<
                        std::is_lvalue_reference_v<T>,
                        std::add_lvalue_reference_t<decay_without_cv_t<T>>,
                        std::conditional_t<
                            std::is_rvalue_reference_v<T>,
                            std::add_rvalue_reference_t<decay_without_cv_t<T>>,
                            decay_without_cv_t<T>
                        >
                    >,
                decay_without_cv_t<T>
            >;
        };

        template <typename T>
        using decay_without_cvr_t = typename decay_without_cvr<T>::type;

        template <typename T>
        struct decay_without_cvlr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_lvalue_reference_v<T>,
                    std::add_lvalue_reference_t<decay_without_cv_t<T>>,
                decay_without_cv_t<T>
            >;
        };

        template <typename T>
        using decay_without_cvlr_t = typename decay_without_cvlr<T>::type;

        template <typename T>
        struct decay_without_cvrr
        {
            using type = std::conditional_t<
                !std::is_array_v<std::remove_reference_t<T>> && std::is_rvalue_reference_v<T>,
                    std::add_rvalue_reference_t<decay_without_cv_t<T>>,
                decay_without_cv_t<T>
            >;
        };

        template <typename T>
        using decay_without_cvrr_t = typename decay_without_cvrr<T>::type;

    } // namespace detail

} // namespace commander
