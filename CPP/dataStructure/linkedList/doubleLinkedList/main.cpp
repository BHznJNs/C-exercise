#include <iostream>

using namespace std;

class Node {
    public:
        int value;

        Node* prev = NULL;
        Node* next = NULL;

        Node(int value) {
            this->value = value;
        }
};

class LinkedList {
    public:
        Node* head = NULL;
        Node* tail = NULL;

        Node* getNode(int index);
        LinkedList append(int value);
        LinkedList insert(int index, int value);
        void traversal(void);
    private:
        int length = 0;
};
// 获取指定 index 处的节点的指针
Node* LinkedList::getNode(int index) {
    if (index > length || index < 0) {
        cerr << "Inputted wrong index!" << endl;
        return NULL;
    }
    Node* current = this->head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }
    return current;
}
// 在链表尾部插入节点
LinkedList LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!this->length) {
        this->head = newNode;
    } else {
        this->tail->next = newNode;
    }
    this->tail = newNode;
    this->length += 1;
    return *this;
}
// 在链表指定位置插入节点
LinkedList LinkedList::insert(int index, int value) {
    if (index > this->length || index < 0) {
        cerr << "Inputted wrong index!" << endl;
        return *this;
    }

    Node* newNode = new Node(value);
    if (!index) {
        // index == 0, 插入到链表头部
        newNode->next = this->head;
        this->head = newNode;
    } else {
        Node* current = this->getNode(index - 1);
        newNode->next = current->next;
        current->next = newNode;
        if (index == this->length) {
            this->tail = newNode;
        }
    }
    this->length += 1;
    return *this;
}
// 遍历链表
void LinkedList::traversal(void) {
    Node* current = this->head;
    while (current != NULL) {
        cout << current->value << endl;
        current = current->next;
    }
}

int main() {
    LinkedList linkedList;
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    linkedList.traversal();
    return 0;
}