#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(NULL) {}
};

// void func(LNode L, int n){
//     LNode* head1 = new LNode(); // 创建一个头结点用于头插

//     LNode* p1 = L.next;
//     while(n--) p1 = p1->next; //这里的n是原单链表的长度一半N/2
//     //当前的p1指向的是N/2的第一个节点
//     while(p1->next != NULL)
//     {
//         LNode *p_ = p1->next;
//         p1->next = head1->next;
//         head1->next = p1;
//     }
// }
Node* findMiddle(Node* head) //快慢指针法寻找中点
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseList(Node* head) //头插法
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void reorderList(Node* head)
{
    if(!head || !head->next) return;

    //找中点
    Node* mid = findMiddle(head);
    Node* l1 = head;
    Node* l2 = mid->next;
    mid->next = NULL; //将前后两部分分开

    l2 = reverseList(l2); //逆转后面的部分

    while(l1 && l2)
    {
        Node* n1 = l1->next;
        Node* n2 = l2->next;

        l1->next = l2;
        l2->next = n1;

        l1 = n1;
        l2 = n2;
    }
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(1);
    Node* p = head;

    for(int i = 2; i<= 6; i++)
    {
        p->next = new Node(i);
        p = p->next;
    }

    cout << "原链表: ";
    printList(head); 

    reorderList(head);

    cout << "重排后: ";
    printList(head);

    cin.get();
}