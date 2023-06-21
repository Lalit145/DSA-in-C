#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int decimalValue(struct Node* head) {
    int result = 0;
    struct Node* temp = head;
    int multiplier = 1;

    while (temp != NULL) {
        result += temp->data * multiplier;
        multiplier *= 2;
        temp = temp->next;
    }

    return result;
}

int main() {
    struct Node* head = NULL;

    // Adding elements to linked list
    push(&head, 1);
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);

    printf("Decimal value: %d\n", decimalValue(head));

    return 0;
}
