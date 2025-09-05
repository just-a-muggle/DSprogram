#include <iostream>

using namespace std;


typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;

// 求单链表的长度
int listLen(LinkList L)
{
    int length = 0;
    LNode *p = L->next;
    while(p != NULL)
    {
        length ++;
        p = p ->next;
    }
    cout << "链表长度 = " << length << endl;
    return length;
}

// 返回单链表的中间节点
LNode * findMidNode(LinkList L){
    int length = 0;
    LNode * p = L->next;

    while(p != NULL){
        length ++;
        p = p ->next;
    }

    int count = 0;
    p = L -> next;
    while(p != NULL){
        count ++;
        if(count == length / 2) break;
        p = p -> next;
    }
    return p;
}