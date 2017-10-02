#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Initialization -----------------------------------------------------------

# Required version
cmake_minimum_required(VERSION 3.1)



##### Utilities ----------------------------------------------------------------

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used), Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
else()
   set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used), Debug, Release, RelWithDebInfo, MinSizeRel.")
endif()

# Include utility functions
include(${CMAKE_CURRENT_LIST_DIR}/cmake/utils.cmake)



##### Project ------------------------------------------------------------------

# Include main CMake file
include(project/root.cmake)
