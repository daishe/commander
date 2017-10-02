#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Project ------------------------------------------------------------------

# Project name
project(commander)



##### General locations --------------------------------------------------------

# Source root location
set(project.root "${CMAKE_CURRENT_SOURCE_DIR}")

# Project locations
set(project.loc           "${CMAKE_CURRENT_LIST_DIR}")
set(project.loc.benchmark "${CMAKE_CURRENT_LIST_DIR}/benchmark")
set(project.loc.include   "${CMAKE_CURRENT_LIST_DIR}/../include")
set(project.loc.root      "${CMAKE_CURRENT_LIST_DIR}")
set(project.loc.src       "${CMAKE_CURRENT_LIST_DIR}/src")
set(project.loc.test      "${CMAKE_CURRENT_LIST_DIR}/test")
set(project.loc.vendor    "${CMAKE_CURRENT_LIST_DIR}/../vendor")



##### Source files and directories ---------------------------------------------

# Project source files
file(
    GLOB_RECURSE _.source
    RELATIVE ${project.root}
    ${project.loc.src}/*.c
    ${project.loc.src}/*.cpp
)
list(APPEND project.source "${_.source}")

# Project header files locations
list(
    APPEND project.include
    "${project.loc.include}"
    "${project.loc.src}"
    "${project.loc.vendor}"
)



##### Flags and definitions ----------------------------------------------------

# Compiler definitions
list(APPEND project.define)
# list(APPEND project.define.debug                )
# list(APPEND project.define.release        NDEBUG)
# list(APPEND project.define.relwithdebinfo NDEBUG)
# list(APPEND project.define.minsizerel     NDEBUG)

# Compiler flags
list(APPEND project.cflags -Wall -std=gnu++1z -std=c++1z)
# list(APPEND project.cflags.debug          -O0 -g)
# list(APPEND project.cflags.release        -O3   )
# list(APPEND project.cflags.relwithdebinfo -O2 -g)
# list(APPEND project.cflags.minsizerel     -Os   )

if(MINGW OR MSYS OR CYGWIN OR CMAKE_COMPILER_IS_GNUCXX)
    list(APPEND project.cflags -Wextra -Wpedantic)
endif()

# Linker flags
list(APPEND project.lflags)
# list(APPEND project.lflags.debug     )
# list(APPEND project.lflags.optimized )

# Linker
list(APPEND project.link)
# list(APPEND project.link.debug     )
# list(APPEND project.link.optimized )

# Build type based
build_type_compose(project.define.buildtypebased "${project.define}" "${project.define.debug}" "${project.define.release}" "${project.define.relwithdebinfo}" "${project.define.minsizerel}")
build_type_compose(project.cflags.buildtypebased "${project.cflags}" "${project.cflags.debug}" "${project.cflags.release}" "${project.cflags.relwithdebinfo}" "${project.cflags.minsizerel}")
build_type_compose_link(project.lflags.buildtypebased "${project.lflags}" "${project.lflags.debug}" "${project.lflags.optimized}")
build_type_compose_link(project.link.buildtypebased   "${project.link}"   "${project.link.debug}"   "${project.link.optimized}")



##### Dependencies -------------------------------------------------------------

# Project dependencies (see dependencies.cmake)
include(${project.loc}/dependencies.cmake)



##### Benchmarks ---------------------------------------------------------------

# Project benchmarks (see benchmark.cmake)
include(${project.loc}/benchmark.cmake)



##### Tests --------------------------------------------------------------------

# Project tests (see test.cmake)
include(${project.loc}/test.cmake)
