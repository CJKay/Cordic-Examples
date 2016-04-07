/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cordic.h>

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

int main(void) {
    return 0;
}
