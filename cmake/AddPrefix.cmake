################################################################################
# This Source Code Form is subject to the terms of the Mozilla Public License, #
# v. 2.0. If a copy of the MPL was not distributed with this file, you can     #
# obtain one at http://mozilla.org/MPL/2.0/.                                   #
################################################################################

################################################################################
# Add a prefix to all values in a list.                                        #
################################################################################

function(add_prefix out prefix)
    unset(${out})

    foreach(value ${ARGN})
        set(value "${prefix}${value}")
        list(APPEND ${out} ${value})
    endforeach()

    set(${out} ${${out}} PARENT_SCOPE)
endfunction()
