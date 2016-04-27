/*
* This Source Code Form is subject to the terms of the Mozilla Public License,
* v. 2.0. If a copy of the MPL was not distributed with this file, you can
* obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <cordic.h>

#include "llist.h"

static struct llist my_llist;

cordic_setup(my_llist_setup) {
    llist_init(&my_llist);
}

cordic_test(my_llist_empty) {
    llist_init(&my_llist);

    cordic_assert(my_llist.data == NULL);
    cordic_assert(my_llist.next == &my_llist);
    cordic_assert(my_llist.prev == &my_llist);
}

cordic_test(my_llist_add, my_llist_setup, NULL) {
    struct llist node1, node2, node3;

    llist_add(&node3, &my_llist);
    llist_add(&node2, &my_llist);
    llist_add(&node1, &my_llist);

    cordic_assert(my_llist.next == &node1);
    cordic_assert(my_llist.next->next == &node2);
    cordic_assert(my_llist.next->next->next == &node3);
    cordic_assert(my_llist.next->next->next->next == &my_llist);

    cordic_assert(my_llist.prev == &node3);
    cordic_assert(my_llist.prev->prev == &node2);
    cordic_assert(my_llist.prev->prev->prev == &node1);
    cordic_assert(my_llist.prev->prev->prev->prev == &my_llist);
}

cordic_test(my_llist_remove, my_llist_setup, NULL) {
    struct llist node1, node2, node3;

    llist_add(&node3, &my_llist);
    llist_add(&node2, &my_llist);
    llist_add(&node1, &my_llist);
    llist_remove(&node2);

    cordic_assert(my_llist.next == &node1);
    cordic_assert(my_llist.next->next == &node3);
    cordic_assert(my_llist.next->next->next == &my_llist);

    cordic_assert(my_llist.prev == &node3);
    cordic_assert(my_llist.prev->prev == &node1);
    cordic_assert(my_llist.prev->prev->prev == &my_llist);
}

cordic_test(my_llist_replace, my_llist_setup, NULL) {
    struct llist node1, node2, node3;

    llist_add(&node2, &my_llist);
    llist_add(&node1, &my_llist);
    llist_replace(&node1, &node3);

    cordic_assert(my_llist.next == &node3);
    cordic_assert(my_llist.next->next == &node2);
    cordic_assert(my_llist.next->next->next == &my_llist);

    cordic_assert(my_llist.prev == &node2);
    cordic_assert(my_llist.prev->prev == &node3);
    cordic_assert(my_llist.prev->prev->prev == &my_llist);
}

cordic_suite(my_llist_suite, NULL, NULL,
    &my_llist_empty,
    &my_llist_add,
    &my_llist_remove,
    &my_llist_replace
);

#ifdef __STDC_HOSTED__
#include <stdio.h>

int main(void) {
    cordic_run_suite(&my_llist_suite);

    printf("Number of tests: %d\n", my_llist_suite.num_tests);
    printf("Number of failed tests: %d\n", my_llist_suite.num_failed);
    for(unsigned int i = 0; i < my_llist_suite.num_tests; i++) {
        struct cordic_test *test = my_llist_suite.tests[i];

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
