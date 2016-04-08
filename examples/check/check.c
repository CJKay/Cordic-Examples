/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cordic.h>

#ifdef __STDC_HOSTED__
#include <stdio.h>
#endif

cordic_test(example_success) {
    cordic_assert(1 == 1);
    cordic_assert(1 == 1, "1 does equal 1!");
}

cordic_test(example_failure) {
    cordic_assert(1 == 2, "1 does not equal 2!");
}

cordic_test(example_warn) {
    cordic_warn(1 != 1);
    cordic_warn(1 != 2);
    cordic_warn(1 != 3, "1 does not equal 3!");
}

#ifdef __STDC_HOSTED__
int main(void) {
    example_success.run(&example_success);
    printf("%d\n", example_success.failed);

    example_failure.run(&example_failure);
    printf("%d\n", example_failure.failed);
    printf("%d, \"%s\", \"%s\"\n", example_failure.error.line,
        example_failure.error.cond, example_failure.error.msg);

    example_warn.run(&example_warn);
    printf("%d\n", example_warn.num_warnings);
    printf("%d, \"%s\"\n", example_warn.warnings[0].line,
        example_warn.warnings[0].cond);
    printf("%d, \"%s\", \"%s\"\n", example_warn.warnings[1].line,
        example_warn.warnings[1].cond, example_warn.warnings[1].msg);

    return 0;
}
#endif
