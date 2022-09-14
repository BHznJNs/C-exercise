#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *n1 = l1;
    struct ListNode *n2 = l2;

    struct ListNode *result;
    result->next = NULL;
    struct ListNode *current = result;

    _Bool is_carrying = 0;

    while (n1 || n2) {
        int sum = (n1->val + n2->val);
        if (is_carrying) {
            sum += 1; is_carrying = 0;
        }
        if (sum >= 10) {
            sum -= 10; is_carrying = 1;
        }
        current->val = sum;

        struct ListNode *new_node;
        new_node->next = NULL;
    }
}

// ---------------------------------------------------------------------

struct ListNode* create_node(int value) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}
void arr_to_list(int arr[], int arr_length, struct ListNode *list) {
    struct ListNode *current = list;

    for (int i=0; i<arr_length; i++) {
        if (i) {
            // i != 0
            struct ListNode *new_node = create_node(arr[i]);
            current->next = new_node;
            current = new_node;
        } else {
            // i == 0
            current->val = arr[0];
            current->next = NULL;
        }
    }
}

void list_printer(struct ListNode *node) {
    int i = 0;
    struct ListNode *current = node;

    while (current->next) {
        printf("list[%d]: %d\n", i, current->val);
        i += 1;
        current = current->next;
    }
    printf("list[%d]: %d\n", i, current->val);
}

int get(struct ListNode *list, int index) {}


int main() {
    struct ListNode l1, l2;
    int target1[] = {2, 4, 3};
    int target2[] = {5, 6, 4};
    int target_size = 3;

    arr_to_list(target1, target_size, &l1);
    arr_to_list(target2, target_size, &l2);

    // list_printer(&l1);

    addTwoNumbers(&l1, &l2);

    return 0;
}