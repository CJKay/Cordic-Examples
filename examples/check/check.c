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

cordic_suite(example_suite, NULL, NULL, NULL,
    &example_success,
    &example_failure,
    &example_warn
);

#ifdef __STDC_HOSTED__
int main(void) {
    for(unsigned int i = 0; i < example_suite.num_tests; i++) {
        struct cordic_test *test = example_suite.tests[i];
        test->run(test);

        printf("Suite: %s\n", example_suite.name);
        printf("%s: %d warnings, test %s\n", test->name, test->num_warnings,
            test->failed ? "failed" : "succeeded");

        for(unsigned int j = 0; j < test->num_warnings; j++) {
            printf("    Warning: \"%s\" failed on line %d: \"%s\"\n",
                test->warnings[j].cond, test->warnings[j].line,
                test->warnings[j].msg);
        }

        if(test->failed) {
            printf("    Error: \"%s\" failed on line %d: \"%s\"\n",
                test->error.cond, test->error.line,
                test->error.msg);
        }
    }

    return 0;
}
#endif
