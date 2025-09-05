#include <iostream>
using namespace std;

// 定义单链表结点
struct Node {
    int data;      // 数据域
    Node* next;    // 指针域
    Node(int val = 0) : data(val), next(nullptr) {} // 默认构造，头结点 data 可设为0
};

// 带头结点的头插法
Node* createListHeadInsert(int arr[], int n) {
    Node* head = new Node(); // 创建头结点
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        newNode->next = head->next; // 插入到头结点后
        head->next = newNode;
    }
    return head;
}

// 带头结点的尾插法
Node* createListTailInsert(int arr[], int n) {
    Node* head = new Node();  // 创建头结点
    Node* tail = head;        // 尾指针初始指向头结点
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode; // 尾插
        tail = newNode;       // 更新尾指针
    }
    return head;
}

// 打印链表（跳过头结点）
void printList(Node* head) {
    Node* p = head->next; // 从第一个有效结点开始
    while (p != nullptr) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// 释放链表（包含头结点）
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "带头结点的头插法:" << endl;
    Node* headInsertList = createListHeadInsert(arr, n);
    printList(headInsertList);

    cout << "带头结点的尾插法:" << endl;
    Node* tailInsertList = createListTailInsert(arr, n);
    printList(tailInsertList);

    // 释放内存
    freeList(headInsertList);
    freeList(tailInsertList);

    return 0;
}
