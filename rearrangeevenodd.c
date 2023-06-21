#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void rearrange(struct Node** head) {
    struct Node* odd = *head;
    struct Node* even = odd->next;
    struct Node* evenFirst = even;

    while (1) {
        if (!odd || !even || !(even->next)) {
            odd->next = evenFirst;
            break;
        }

        odd->next = even->next;
        odd = even->next;

        if (odd->next == NULL) {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }

        even->next = odd->next;
        even = odd->next;
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
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original list: ");
    printList(head);

    rearrange(&head);

    printf("Modified list: ");
    printList(head);

    return 0;
}
