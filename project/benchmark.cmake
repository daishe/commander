#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Benchmarks ---------------------------------------------------------------

# List all benchmarks locations
file(GLOB loaction_items RELATIVE ${project.loc.benchmark} ${project.loc.benchmark}/*)
foreach(_.directory_name ${loaction_items})

    # Full path
    set(_ "${project.loc.benchmark}/${_.directory_name}")

    # Include benchmarks from all valid locations
    if(IS_DIRECTORY ${_})
        include(${_}/benchmark.cmake)
    endif()

endforeach()
