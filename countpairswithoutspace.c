#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void findPair(struct Node* head, int sum) {
    struct Node* first = head;
    struct Node* second = head;

    while (second->next != NULL) {
        second = second->next;
    }
    while (first != second) {
        if ((first->data + second->data) == sum) {
            printf("Pair found: (%d, %d)\n", first->data, second->data);
            return;
        }
        if ((first->data + second->data) < sum) {
            first = first->next;
        } else {
            second = second->prev;
        }
    }
    printf("Pair not found\n");
}

int main() {
    struct Node* head = NULL;

    // Adding elements to linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    int sum = 4;
    findPair(head, sum);

    return 0;
}
