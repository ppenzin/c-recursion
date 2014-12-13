#include <assert.h>

/* Our list node definition */
struct node {
    int data;
    struct node * next;
};

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

