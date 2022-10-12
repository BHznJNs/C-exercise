#include <stdio.h>
#include <stdlib.h>

struct {
    struct Node* root;
} binary_tree;

typedef struct Node {
    int value;
    
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node *)calloc(2, sizeof(Node));
    new_node->value = value;
    new_node->left  = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int value, Node* current) {
    Node* new_node = create_node(value);
    if (!binary_tree.root) {
        // root 不存在
        binary_tree.root = new_node;
        return;
    }

    if (value == current->value) {
        return;
    } else if (value > current->value) {
        if (!current->right) {
            current->right = new_node;
        } else {
            insert(value, current->right);
        }
    } else if (value < current->value) {
        if (!current->left) {
            current->left = new_node;
        } else {
            insert(value, current->left);
        }
    }
}

int main() {
    binary_tree.root = NULL;
    insert(5, binary_tree.root);
    insert(2, binary_tree.root);
    insert(8, binary_tree.root);
    insert(4, binary_tree.root);

    printf("%d\n", binary_tree.root->left->value);
    printf("%d\n", binary_tree.root->right->value);
    printf("%d\n", binary_tree.root->left->right->value);
    return 0;
}