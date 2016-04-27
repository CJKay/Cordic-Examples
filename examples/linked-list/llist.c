/*
* This Source Code Form is subject to the terms of the Mozilla Public License,
* v. 2.0. If a copy of the MPL was not distributed with this file, you can
* obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "llist.h"

#include <stddef.h>

void llist_init(struct llist *list) {
    list->prev = list;
    list->next = list;
    list->data = NULL;
}

void llist_add(struct llist *new, struct llist *head) {
    head->next->prev = new;
    new->next = head->next;
    new->prev = head;
    head->next = new;
}

void llist_remove(struct llist *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void llist_replace(struct llist *old, struct llist *new) {
    new->next = old->next;
    new->next->prev = new;
    new->prev = old->prev;
    new->prev->next = new;
}
