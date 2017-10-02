#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Threads -------------------------------------------------------------

# Find package
find_package(Threads REQUIRED)

# Set libraries to link
list(APPEND project.link "Threads::Threads")

# Recreate "build type based"
build_type_compose_link(project.link.buildtypebased "${project.link}" "${project.link.debug}" "${project.link.optimized}")



##### Boost -------------------------------------------------------------

# Set options
set(Boost_NO_BOOST_CMAKE     ON)
set(Boost_USE_STATIC_LIBS    ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED  ON)

# Set requied components
set(Boost_COMPONENTS system)

# Find package
find_package(Boost 1.64.0 COMPONENTS ${Boost_COMPONENTS} REQUIRED)

# Set include directories
list(APPEND project.include "${Boost_INCLUDE_DIRS}")

# Set libraries to link
list(APPEND project.link.debug     "${Boost_SYSTEM_LIBRARY_DEBUG}")
list(APPEND project.link.optimized "${Boost_SYSTEM_LIBRARY_RELEASE}")

# Recreate "build type based"
build_type_compose_link(project.link.buildtypebased "${project.link}" "${project.link.debug}" "${project.link.optimized}")
