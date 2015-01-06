/* Our list node definition */
struct node {
    int data;
    struct node * next;
};

/* ======== Function prototypes ======== */

/* Sum all the elements recursively */
int sum(struct node * head);
