#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[20];
    struct Node* next;
};

int isPalindrome(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev_of_slow = NULL;
    struct Node* midnode = NULL;
    int res = 1;

    if (head != NULL && head->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;

            // Store previous of slow pointer
            prev_of_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            midnode = slow;
            slow = slow->next;
        }
        prev_of_slow->next = NULL;
        struct Node* second_half = slow;
        prev_of_slow = NULL;

        while (second_half != NULL) {
            struct Node* next = second_half->next;
            second_half->next = prev_of_slow;
            prev_of_slow = second_half;
            second_half = next;
        }
        struct Node* temp1 = head;

        while (prev_of_slow != NULL) {
            if (strcmp(temp1->data, prev_of_slow->data) != 0) {
                res = 0;
                break;
            }
            temp1 = temp1->next;
            prev_of_slow = prev_of_slow->next;
        }

        // Reversing the second half again
        prev_of_slow = NULL;
        second_half = slow;
        while (second_half != NULL) {
            next = second_half->next;
            second_half->next = prev_of_slow;
            prev_of_slow = second_half;
            second_half = next;
        }
        if (midnode != NULL) {
            prev_of_slow = midnode;
            prev_of_slow->next = slow;
        } else
            head->next = slow;
    }
    return res;
}

int main() {
    struct Node* head = NULL;

    // Adding elements to linked list
    push(&head, "a");
    push(&head, "b");
    push(&head, "c");
    push(&head, "b");
    push(&head, "a");

    if (isPalindrome(head))
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");

    return 0;
}

