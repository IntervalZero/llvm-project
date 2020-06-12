//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// UNSUPPORTED: c++11, c++14

// <functional>

// Test the feature test macros defined by <functional>

/*  Constant                           Value
    __cpp_lib_bind_front               201811L [C++2a]
    __cpp_lib_boyer_moore_searcher     201603L [C++17]
    __cpp_lib_constexpr_misc           201811L [C++2a]
    __cpp_lib_invoke                   201411L [C++17]
    __cpp_lib_not_fn                   201603L [C++17]
    __cpp_lib_ranges                   201811L [C++2a]
    __cpp_lib_result_of_sfinae         201210L [C++14]
    __cpp_lib_transparent_operators    201210L [C++14]
                                       201510L [C++17]
*/

#include <functional>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_bind_front
#   error "__cpp_lib_bind_front should not be defined before c++2a"
# endif

# ifdef __cpp_lib_boyer_moore_searcher
#   error "__cpp_lib_boyer_moore_searcher should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifdef __cpp_lib_invoke
#   error "__cpp_lib_invoke should not be defined before c++17"
# endif

# ifdef __cpp_lib_not_fn
#   error "__cpp_lib_not_fn should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifdef __cpp_lib_result_of_sfinae
#   error "__cpp_lib_result_of_sfinae should not be defined before c++14"
# endif

# ifdef __cpp_lib_transparent_operators
#   error "__cpp_lib_transparent_operators should not be defined before c++14"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_bind_front
#   error "__cpp_lib_bind_front should not be defined before c++2a"
# endif

# ifdef __cpp_lib_boyer_moore_searcher
#   error "__cpp_lib_boyer_moore_searcher should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifdef __cpp_lib_invoke
#   error "__cpp_lib_invoke should not be defined before c++17"
# endif

# ifdef __cpp_lib_not_fn
#   error "__cpp_lib_not_fn should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifndef __cpp_lib_result_of_sfinae
#   error "__cpp_lib_result_of_sfinae should be defined in c++14"
# endif
# if __cpp_lib_result_of_sfinae != 201210L
#   error "__cpp_lib_result_of_sfinae should have the value 201210L in c++14"
# endif

# ifndef __cpp_lib_transparent_operators
#   error "__cpp_lib_transparent_operators should be defined in c++14"
# endif
# if __cpp_lib_transparent_operators != 201210L
#   error "__cpp_lib_transparent_operators should have the value 201210L in c++14"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_bind_front
#   error "__cpp_lib_bind_front should not be defined before c++2a"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_boyer_moore_searcher
#     error "__cpp_lib_boyer_moore_searcher should be defined in c++17"
#   endif
#   if __cpp_lib_boyer_moore_searcher != 201603L
#     error "__cpp_lib_boyer_moore_searcher should have the value 201603L in c++17"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_boyer_moore_searcher
#     error "__cpp_lib_boyer_moore_searcher should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifndef __cpp_lib_invoke
#   error "__cpp_lib_invoke should be defined in c++17"
# endif
# if __cpp_lib_invoke != 201411L
#   error "__cpp_lib_invoke should have the value 201411L in c++17"
# endif

# ifndef __cpp_lib_not_fn
#   error "__cpp_lib_not_fn should be defined in c++17"
# endif
# if __cpp_lib_not_fn != 201603L
#   error "__cpp_lib_not_fn should have the value 201603L in c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifndef __cpp_lib_result_of_sfinae
#   error "__cpp_lib_result_of_sfinae should be defined in c++17"
# endif
# if __cpp_lib_result_of_sfinae != 201210L
#   error "__cpp_lib_result_of_sfinae should have the value 201210L in c++17"
# endif

# ifndef __cpp_lib_transparent_operators
#   error "__cpp_lib_transparent_operators should be defined in c++17"
# endif
# if __cpp_lib_transparent_operators != 201510L
#   error "__cpp_lib_transparent_operators should have the value 201510L in c++17"
# endif

#elif TEST_STD_VER > 17

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_bind_front
#     error "__cpp_lib_bind_front should be defined in c++2a"
#   endif
#   if __cpp_lib_bind_front != 201811L
#     error "__cpp_lib_bind_front should have the value 201811L in c++2a"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_bind_front
#     error "__cpp_lib_bind_front should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_boyer_moore_searcher
#     error "__cpp_lib_boyer_moore_searcher should be defined in c++2a"
#   endif
#   if __cpp_lib_boyer_moore_searcher != 201603L
#     error "__cpp_lib_boyer_moore_searcher should have the value 201603L in c++2a"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_boyer_moore_searcher
#     error "__cpp_lib_boyer_moore_searcher should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_constexpr_misc
#     error "__cpp_lib_constexpr_misc should be defined in c++2a"
#   endif
#   if __cpp_lib_constexpr_misc != 201811L
#     error "__cpp_lib_constexpr_misc should have the value 201811L in c++2a"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_constexpr_misc
#     error "__cpp_lib_constexpr_misc should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_invoke
#   error "__cpp_lib_invoke should be defined in c++2a"
# endif
# if __cpp_lib_invoke != 201411L
#   error "__cpp_lib_invoke should have the value 201411L in c++2a"
# endif

# ifndef __cpp_lib_not_fn
#   error "__cpp_lib_not_fn should be defined in c++2a"
# endif
# if __cpp_lib_not_fn != 201603L
#   error "__cpp_lib_not_fn should have the value 201603L in c++2a"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_ranges
#     error "__cpp_lib_ranges should be defined in c++2a"
#   endif
#   if __cpp_lib_ranges != 201811L
#     error "__cpp_lib_ranges should have the value 201811L in c++2a"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_ranges
#     error "__cpp_lib_ranges should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_result_of_sfinae
#   error "__cpp_lib_result_of_sfinae should be defined in c++2a"
# endif
# if __cpp_lib_result_of_sfinae != 201210L
#   error "__cpp_lib_result_of_sfinae should have the value 201210L in c++2a"
# endif

# ifndef __cpp_lib_transparent_operators
#   error "__cpp_lib_transparent_operators should be defined in c++2a"
# endif
# if __cpp_lib_transparent_operators != 201510L
#   error "__cpp_lib_transparent_operators should have the value 201510L in c++2a"
# endif

#endif // TEST_STD_VER > 17

int main(int, char**) { return 0; }
