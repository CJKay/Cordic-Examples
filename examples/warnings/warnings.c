/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */


#include <cordic.h>

#ifdef __STDC_HOSTED__
#include <stdio.h>
#endif

cordic_test(basic_test) {
    for(int i = 0; i <= CORDIC_MAX_WARNINGS; i++) {
        cordic_warn(true);
    }
}

cordic_suite(basic_suite, NULL, NULL,
    &basic_test
);

#ifdef __STDC_HOSTED__
int main(void) {
    cordic_run_suite(&basic_suite);

    printf("Number of tests: %d\n", basic_suite.num_tests);
    printf("Number of failed tests: %d\n", basic_suite.num_failed);
    for(unsigned int i = 0; i < basic_suite.num_tests; i++) {
        struct cordic_test *test = basic_suite.tests[i];

        printf("Test %s %s:\n", test->name,
            test->failed ? "failed" : "succeeded");
        printf("    %d warnings\n", test->num_warnings);
        for(unsigned int j = 0; j < test->num_warnings; j++) {
            struct cordic_result *warning = &test->warnings[j];

            printf("    Warning: line %d, condition \"%s\"", warning->line,
                warning->cond);
            if(warning->msg != NULL)
                printf(": %s", warning->msg);
            printf("\n");

            if(j + 1 == CORDIC_MAX_WARNINGS) {
                printf("    And %d more warning(s)...\n", test->num_warnings -
                    j - 1);

                break;
            }
        }

        if(test->failed) {
            struct cordic_result *error = &test->error;

            printf("    Error: line %d, condition \"%s\"", error->line,
                    error->cond);
            if(error->msg != NULL)
                printf(": %s", error->msg);
            printf("\n");
        }
    }

    return 0;
}
#endif
