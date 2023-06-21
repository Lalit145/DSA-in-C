#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* n) {
    int res = 1;
    struct Node* temp = n;
    while (temp->next != n) {
        res++;
        temp = temp->next;
    }
    return res;
}

int countLoop(struct Node* head) {
    struct Node* slow_p = head, * fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p)
            return countNodes(slow_p);
    }

    return 0;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    // Adding elements to linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    printf("Length of Loop is %d\n", countLoop(head));

    return 0;
}
