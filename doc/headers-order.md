# Commander - headers order

Header groups should be separated with one blank line. Directives in each group should be in alphabetical order.

## General header files (from `include` directory)
    1. General commander headers (from `include` directory)
    2. Other libraries (including STL) *can be expanded into multiple groups*

## Other header files
    1. General commander headers (from `include` directory)
    2. Commander headers associated with current header file (but not form `include` directory)
    3. Other libraries headers (including STL) *can be expanded into multiple groups*

## Source files
    1. General commander headers (from `include` directory)
    2. Commander headers associated with current source file (but not form `include` directory)
    3. Other libraries headers (including STL) *can be expanded into multiple groups*

## Test files
    1. Currently tested headers
    2. Headers specific to the test system (ex. `boost/test/unit_test.hpp`)
    3. Commander headers associated with current test file (but not form `include` directory)
    4. General commander headers (from `include` directory)
    5. Other libraries headers (including STL) *can be expanded into multiple groups*
