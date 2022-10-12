#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct {
    int length;
    struct Node *head;

    struct Node *(*create_node)();
    struct Node *(*getLast)();

    void (*append)();
    void (*head_insert)();
    int (*get)();
} linked_list;

// --------------------------------------
/* 链表方法 */
// 创建链表节点
Node* create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
};
// 获取链表最后一项
Node* getLast() {
    Node *last = linked_list.head;
    while(last->next) {
        last = last->next;
    }
    return last;
};

// 链表尾部加入节点
void append(int value) {
    Node *new_node = linked_list.create_node(value);

    if (!linked_list.length) {
        // 链表中无节点
        linked_list.head = new_node;
    } else {
        linked_list.getLast()->next = new_node;
    }
    linked_list.length += 1;
};
// 链表头部添加节点
void head_insert(int value){
    Node *new_node = linked_list.create_node(value);
    Node *head = linked_list.head;
    new_node->next = head;
    linked_list.head = new_node;
};
// 链表插入节点
// bool insert(int index, int value) {
//     if (index > linked_list.length - 1) {
//         // 链表越界
//         return false;
//     };

//     Node *new_node = linked_list.create_node(value);
//     Node *target_node = linked_list.get(index);

//     new_node->next = target_node->next;
//     target_node->next = new_node;
//     linked_list.length += 1;
//     return true
// };
// 链表获取节点
int get(int index) {
    if (index > linked_list.length - 1) {
        // 链表越界
        return false;
    };

    Node *target = linked_list.head;
    for (int i=0; i<index; i++) {
        target = target->next;
    };
    return target->value;
};

/* 链表方法 */
// --------------------------------------

// 链表初始化
void linked_list_init() {
    linked_list.length = 0;
    linked_list.head = NULL;

    linked_list.create_node = create_node;
    linked_list.getLast = getLast;

    linked_list.append = append;
    linked_list.head_insert = head_insert;
    linked_list.get = get;
}

int main() {
    linked_list_init();
    linked_list.append(1);
    // linked_list.append(2);
    // linked_list.head_insert(5);
    // const int value = linked_list.get(0);
    printf("linked_list[0]: %d", linked_list.get(0));
    return 0;
}