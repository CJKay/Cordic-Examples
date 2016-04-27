/*
* This Source Code Form is subject to the terms of the Mozilla Public License,
* v. 2.0. If a copy of the MPL was not distributed with this file, you can
* obtain one at http://mozilla.org/MPL/2.0/.
*/

struct llist {
    struct llist *prev;
    struct llist *next;

    void *data;
};

// Initalise our linked list
void llist_init(struct llist *list);

// Insert a new node at the beginning of the linked list
void llist_add(struct llist *new, struct llist *head);

// Remove this node from its linked list
void llist_remove(struct llist *node);

// Replace a linked list node with another
void llist_replace(struct llist *old, struct llist *new);
