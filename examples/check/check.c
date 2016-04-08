/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cordic.h>

#ifdef __STDC_HOSTED__
#include <stdio.h>
#endif

struct cordic_result example_success(struct cordic_args args) {
    (void)args;

    cordic_success;
}

struct cordic_result example_failure(struct cordic_args args) {
    (void)args;

    cordic_assert(1 == 1);
    cordic_assert(1 == 2, "1 does not equal 2!");

    cordic_success;
}

#ifdef __STDC_HOSTED__
int main(void) {
    struct cordic_args args = { 0 };

    struct cordic_result success = example_success(args);
    printf("%d, %p, %p, %p\n", success.line, (void *)success.file,
        (void *)success.fn, (void *)success.msg);

    struct cordic_result failure = example_failure(args);
    printf("%d, \"%s\", \"%s\", \"%s\"\n", failure.line, failure.file,
        failure.fn, failure.msg);

    return 0;
}
#endif
