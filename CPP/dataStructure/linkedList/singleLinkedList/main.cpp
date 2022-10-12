#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next = NULL;

        Node(int value) {
            this->value = value;
        }
};

class LinkedList {
    public:
        Node* head = NULL;

        Node* getLast(void);
        Node* getNode(int index);
        int getLength() {return length;}
        LinkedList append(int value);
        LinkedList amend(int index, int value);
        LinkedList insert(int index, int value);
        LinkedList delete_(int index);
        void traversal(void);
    private:
        int length = 0;
};
// 获取最后节点的指针
Node* LinkedList::getLast(void) {
    Node* last = this->head;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}
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
    if (!this->head) {
        this->head = newNode;
    } else {
        Node* lastNode = this->getLast();
        lastNode->next = newNode;
    }
    this->length += 1;
    return *this;
}
// 改变链表指定位置节点的值
LinkedList LinkedList::amend(int index, int value) {
    if (index >= length || index < 0) {
        cerr << "Inputted wrong index!" << endl;
        return *this;
    }
    Node* target = this->getNode(index);
    target->value = value;
    return *this;
}
// 在链表指定位置插入节点
LinkedList LinkedList::insert(int index, int value) {
    if (index > length || index < 0) {
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
    }
    this->length += 1;
    return *this;
}
LinkedList LinkedList::delete_(int index) {
    if (index >= length || index < 0) {
        cerr << "Inputted wrong index!" << endl;
        return *this;
    }

    Node* target = this->getNode(index);
    if (!index) {
        // index == 0, 删除链表头部节点
        this->head = target->next;
    } else {
        Node* lastNode = this->getNode(index-1);
        lastNode->next = target->next;
    }
    delete target;
    return *this;
}
// 遍历链表
void LinkedList::traversal() {
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
    linkedList.insert(3, 4);
    linkedList.delete_(3);
    linkedList.traversal();
    return 0;
}