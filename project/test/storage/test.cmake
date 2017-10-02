#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Test initialization ------------------------------------------------------

# Additional source files
file(
    GLOB_RECURSE _.source RELATIVE ${project.root}
    ${_}/*.c
    ${_}/*.cpp
)

# Variables
set(_.executable_name "${PROJECT_NAME}-test-${_.directory_name}")
set(_.test_case_name  "test_${_.directory_name}")
set(test.${_.executable_name}.name       "${_.executable_name}")
set(test.${_.executable_name}.case       "${_.test_case_name}")
set(test.${_.executable_name}.executable "${_.executable_name}")
list(APPEND test._.cases       "${_.test_case_name}")
list(APPEND test._.executables "${_.executable_name}")

# Executables
add_executable(${_.executable_name} ${project.source} ${_.source})

# Includes
target_include_directories(${_.executable_name} PUBLIC "${project.include}" "${_}")

# Compiler definitions
target_compile_definitions(${_.executable_name} PUBLIC ${project.define.buildtypebased})

# Compiler flags
target_compile_options(${_.executable_name} PUBLIC ${project.cflags.buildtypebased})

# Linker flags and libraries
target_link_libraries(${_.executable_name} ${project.lflags.buildtypebased} ${project.link.buildtypebased})



##### Test cases ---------------------------------------------------------------

add_test(${_.test_case_name} ${_.executable_name})
