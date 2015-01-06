#include <assert.h>

#include "list-recursion.h"

#ifdef UNIT_TESTING
#include <stddef.h>
// Overrides library functions, must be the last include
#include <cmockery/cmockery_override.h>
#endif // UNIT_TESTING

/* Sum all the elements recursively */
int sum(struct node * head) {
    /* We don't work with empty lists */
    assert(head);

    /* Just one element in the list */
    if (!head->next) {
        return (head->data);
    } else {
        /* Call ourselves */
        return (head->data + sum(head->next));
    }
}

