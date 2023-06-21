#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countPairs(struct Node* head1, struct Node* head2, int sum) {
    int count = 0;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if ((temp1->data + temp2->data) == sum)
                count++;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return count;
}

// Helper function to push a new node in the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Adding elements to linked list 1
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);

    // Adding elements to linked list 2
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 6);

    int sum = 4;
    printf("Count of pairs is %d\n", countPairs(head1, head2, sum));

    return 0;
}
