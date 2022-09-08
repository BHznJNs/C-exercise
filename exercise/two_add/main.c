#include <stdio.h>

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
    // 
}

// ---------------------------------------------------------------------

struct ListNode* create_node(int value) {
    struct ListNode *new_node = NULL;
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

void list_init(struct ListNode list, int* target, int target_size) {
    list.val = target[0];

    struct ListNode *node = list;

    for (int i=1; i < target_size; i++) {
        struct ListNode *new_node = create_node(target[i]);
        node.next = new_node;
        node = new_node;
    }
}

int main() {
    struct ListNode l1, l2;
    int target1[] = {2, 4, 3};
    int target2[] = {5, 6, 4};
    int target_size = 3;

    list_init(l1, target1, target_size);

    return 0;
}