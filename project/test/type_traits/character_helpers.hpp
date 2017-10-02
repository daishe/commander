//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

struct non_char {};

struct some_char { explicit some_char(uint8_t) {}; };
inline bool     operator ==(const some_char&, const      char&) { return true; }
inline bool     operator ==(const      char&, const some_char&) { return true; }
inline uint8_t  operator ==(const some_char&, const  char16_t&) { return 1; }
inline uint8_t  operator ==(const  char16_t&, const some_char&) { return 1; }
inline uint16_t operator ==(const some_char&, const  char32_t&) { return 1; }
inline uint16_t operator ==(const  char32_t&, const some_char&) { return 1; }
inline uint32_t operator ==(const some_char&, const   wchar_t&) { return 1; }
inline uint32_t operator ==(const   wchar_t&, const some_char&) { return 1; }

struct non_char_constr { explicit non_char_constr(non_char) {}; };
inline bool     operator ==(const non_char_constr&, const            char&) { return true; }
inline bool     operator ==(const            char&, const non_char_constr&) { return true; }
inline uint8_t  operator ==(const non_char_constr&, const        char16_t&) { return 1; }
inline uint8_t  operator ==(const        char16_t&, const non_char_constr&) { return 1; }
inline uint16_t operator ==(const non_char_constr&, const        char32_t&) { return 1; }
inline uint16_t operator ==(const        char32_t&, const non_char_constr&) { return 1; }
inline uint32_t operator ==(const non_char_constr&, const         wchar_t&) { return 1; }
inline uint32_t operator ==(const         wchar_t&, const non_char_constr&) { return 1; }

struct non_const_comp_char { explicit non_const_comp_char(uint8_t) {}; };
inline bool     operator ==(      non_const_comp_char&, const                char&) { return true; }
inline bool     operator ==(const                char&,       non_const_comp_char&) { return true; }
inline uint8_t  operator ==(      non_const_comp_char&, const            char16_t&) { return 1; }
inline uint8_t  operator ==(const            char16_t&,       non_const_comp_char&) { return 1; }
inline uint16_t operator ==(      non_const_comp_char&, const            char32_t&) { return 1; }
inline uint16_t operator ==(const            char32_t&,       non_const_comp_char&) { return 1; }
inline uint32_t operator ==(      non_const_comp_char&, const             wchar_t&) { return 1; }
inline uint32_t operator ==(const             wchar_t&,       non_const_comp_char&) { return 1; }
