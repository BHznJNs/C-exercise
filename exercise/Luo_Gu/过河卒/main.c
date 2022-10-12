#include <stdio.h>
#include <stdlib.h>

int bx, by; // B 点坐标
int hx, hy; // 马坐标
int sum;

int* control_points[9]; // 控制点数组
int cp_length; // 控制点数组大小

struct {
    struct Node* root;
} binary_tree;

typedef struct Node {
    int value[2];

    struct Node* left;
    struct Node* right;
} Node;

// 计算控制点
void cp_compute(int* cp[], int* length) {
    int arr_x[9] = {1, 2, 2, 1, 0, -1, -2, -2, -1};
    int arr_y[9] = {-2, -1, 1, 2, 0, 2, 1, -1, -2};

    for (int i=1; i<9; i++) {
        int x = hx + arr_x[i];
        int y = hy + arr_y[i];

        if (x > bx || x < 0 || y > by || y < 0) {
            continue;
        } else {
            cp[*length] = (int *)malloc(2 * sizeof(int));
            cp[*length][0] = x; cp[*length][1] = y;
            *length += 1;
        }
    }
}

int compare(int pos1[2], int pos2[2]) {
    int x1, y1, x2, y2;
    x1 = pos1[0]; x2 = pos2[0];
    y1 = pos1[1]; y2 = pos2[1];
    if (x1 == x2 && y1 == y2) {
        return 0;
    }
    if (x1 < x2 && y1 == y2) {
        return 1;
    }
    if (x1 == x2 && y1 < y2) {
        return 2;
    }
    if (x1 < x2 && y1 < y2) {
        return 3;
    }
}

void pos_printer(Node* node) {
    int* value = node->value;
    printf("[%d, %d]\n", value[0], value[1]);
}

Node* create_node(int value[]) {
    Node* new_node = (Node *)calloc(2, sizeof(Node));
    new_node->value[0] = value[0];
    new_node->value[1] = value[1];
    new_node->left  = NULL;
    new_node->right = NULL;
    return new_node;
}

// -----------------------------------------------------------
void check_insert(Node* current, Node* new_node, int value);
void insert(int value[], Node* current) {
    Node* new_node = create_node(value);
    if (!binary_tree.root) {
        // root 不存在
        binary_tree.root = new_node;
        return;
    }
    const int compared = compare(current->value, value);

    if (compared == 0) {
        return;
    } else if (compared == 1) {
        check_insert(current, new_node, 0);
    } else if (compared == 2) {
        check_insert(current, new_node, 1);
    } else {
        check_insert(current, new_node, 0);
        check_insert(current, new_node, 1);
    }
}
//                                           0 -> left; 1 -> right
void check_insert(Node* current, Node* new_node, int value) {
    if (value == 0) {
        if (!current->left) {
            current->left = new_node; 
        } else {
            insert(new_node->value, current->left);
        }
    } else {
        if (!current->right) {
            current->right = new_node; 
        } else {
            insert(new_node->value, current->right);
        }
    }
}
// -----------------------------------------------------------

void traverse(Node* node) {
    if (node->value == NULL) {
        // 空节点
        return;
    }
    if (node->left==NULL && node->right==NULL) {
        // 底端节点
        sum += 1;
        return;
    }
    for (int i=0; i<cp_length; i++) {
        int* cp_pos = control_points[i];
        // 遇到控制点
        if (compare(node->value, cp_pos) == 0) {
            return;
        }
    }
    traverse(node->left);
    traverse(node->right);
}

int main() {
    binary_tree.root = NULL;
    // bx = 6; by = 6;
    // hx = 3; hy = 3;
    scanf("%d %d %d %d", &bx, &by, &hx, &hy);

    cp_compute(control_points, &cp_length);

    for (int i=0; i<bx+1; i++) {
        for (int j=0; j<by+1; j++) {
            int pos[] = {i, j};

            for (int i=0; i<cp_length; i++) {
                int* cp_pos = control_points[i];
                // 遇到控制点
                if (compare(pos, cp_pos) == 0) {
                    continue;
                }
            }
            insert(pos, binary_tree.root);
        }
    }

    traverse(binary_tree.root);
    printf("%d\n", sum);
    return 0;
}