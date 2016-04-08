/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cordic.h>

#ifdef __STDC_HOSTED__
#include <stdio.h>
#endif

struct cordic_result example_success(cordic_args) {
    cordic_success;
}

struct cordic_result example_failure(cordic_args) {
    cordic_assert(1 == 1);
    cordic_assert(1 == 2, "1 does not equal 2!");

    cordic_success;
}

#ifdef __STDC_HOSTED__
int main(void) {
    struct cordic_result success = example_success();
    printf("%d, \"%s\", \"%s\", %p\n", success.line, (void *)success.file,
        (void *)success.fn, (void *)success.msg);

    struct cordic_result failure = example_failure();
    printf("%d, \"%s\", \"%s\", \"%s\"\n", failure.line, failure.file,
        failure.fn, failure.msg);

    return 0;
}
#endif
