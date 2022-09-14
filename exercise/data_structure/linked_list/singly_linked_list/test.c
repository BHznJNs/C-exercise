#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int value;
    struct list_node *next;
} list_node;

// ----------------------------------------------------

list_node* create_node(int value) {
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void list_node_init(list_node *node, int value) {
    node->value = 1;
    node->next = NULL;
}

// ----------------------------------------------------

void arr_to_list(int arr[], int arr_length, list_node *list) {
    list_node *current = list;

    for (int i=0; i<arr_length; i++) {
        if (i) {
            // i != 0
            list_node *new_node = create_node(arr[i]);
            current->next = new_node;
            current = new_node;
        } else {
            // i == 0
            list_node_init(current, arr[0]);
        }
    }
}

void list_printer(list_node *node) {
    int i = 0;
    list_node *current = node;

    while (current->next) {
        printf("list[%d]: %d\n", i, current->value);
        i += 1;
        current = current->next;
    }
    printf("list[%d]: %d\n", i, current->value);
}

// ----------------------------------------------------

int main() {
    list_node l1, l2;
    // list_node_init(&l1, 2);

    int arr[] = {1, 2, 3, 4};
    arr_to_list(arr, 4, &l1);
    list_printer(&l1);
    return 0;
}