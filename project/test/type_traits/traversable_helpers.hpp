//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

struct container_begin_end   {       int* begin();             int* end();       };
struct container_cbegin_cend { const int* begin() const; const int* end() const; };

struct container_begin  {       int* begin();       };
struct container_cbegin { const int* begin() const; };

struct container_end  {       int* end();       };
struct container_cend { const int* end() const; };

typedef uint8_t bound_array[5];
typedef uint8_t unbound_array[];
