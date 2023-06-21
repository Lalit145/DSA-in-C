#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to make middle element the head of the list
void makeMiddleHead(struct Node **head_ref) {
    struct Node *slow = *head_ref;
    struct Node *fast = *head_ref;
    struct Node *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = *head_ref;
    *head_ref = slow;
}

// Function to push a new node at the front of the list
void push(struct Node **head_ref, int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("Original Linked List: ");
    printList(head);
    makeMiddleHead(&head);
    printf("Modified Linked List: ");
    printList(head);
    return 0;
}
