#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



# Allow easy flags adding, based on build type
function(build_type_compose out global debug release relwithdebinfo minsizerel)
    set(
        ${out}
        ${global}
        $<$<CONFIG:Debug>:${debug}>
        $<$<CONFIG:Release>:${release}>
        $<$<CONFIG:RelWithDebInfo>:${relwithdebinfo}>
        $<$<CONFIG:MinSizeRel>:${minsizerel}>
        PARENT_SCOPE
    )
endfunction()

# Allow easy link items adding
function(build_type_compose_link out general debug optimized)
    foreach(item ${debug})
        list(APPEND debug_ "debug" "${item}")
    endforeach()
    foreach(item ${optimized})
        list(APPEND optimized_ "optimized" "${item}")
    endforeach()

    set(${out} ${general} ${debug_} ${optimized_} PARENT_SCOPE)
endfunction()
