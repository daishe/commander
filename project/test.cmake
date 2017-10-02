#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Testing initialization ---------------------------------------------------

# Enable
enable_testing()



##### Tests --------------------------------------------------------------------

# List all tests locations
file(GLOB loaction_items RELATIVE ${project.loc.test} ${project.loc.test}/*)
foreach(_.directory_name ${loaction_items})

    # Full path
    set(_ "${project.loc.test}/${_.directory_name}")

    # Include tests from all valid locations
    if(IS_DIRECTORY ${_})
        include(${_}/test.cmake)
    endif()

endforeach()
