#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int count(struct Node* head, int search_for) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == search_for)
            count++;
        current = current->next;
    }
    return count;
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
    push(&head, 2);
    push(&head, 1);

    int search_for = 2;
    printf("Count of %d is: %d\n", search_for, count(head, search_for));

    return 0;
}
