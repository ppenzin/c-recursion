#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmockery.h>

#include "list-recursion.h"

// Check for assert error on empty list
void assert_error_on_empty_list(void **state) {
    expect_assert_failure(sum(NULL));
}

// Simple sum test
void sum_123(void **state) {
    struct node * head = (struct node *) malloc(sizeof(struct node));
    /* Set numbers */
    head->data = 1;
    head->next =  (struct node *) malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next =  (struct node *) malloc(sizeof(struct node));
    head->next->next->data = 3;
    /* Terminate the list */
    head->next->next->next = NULL;

    /* == Check == */
    assert_int_equal(6, sum(head));

    /* Free up memory (cmockery will flag us otherwise) */
    free(head->next->next);
    free(head->next);
    free(head);
}

int main(void) {
    const UnitTest tests[] = {
        unit_test(assert_error_on_empty_list),
        unit_test(sum_123),
    };
    return run_tests(tests, "list-recursion");
}
