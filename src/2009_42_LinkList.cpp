#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, *LinkList;

int findNode(LinkList L, int k){
    if (!L || k <= 0) return 0;  
    int length = 0;
    LNode *p = L ->next;

    while(p != NULL){
        length ++;
        p = p->next;
    }
    if (k > length) return 0; 
    p = L->next;
    int count = length - k;

    while(count --) p = p->next;

    return p->data;
}

int main()
{

}