#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Adding elements to linked list
    push(&head, 5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("Modified list: ");
    printList(head);

    return 0;
}
