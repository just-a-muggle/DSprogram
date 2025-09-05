#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, *LinkList;

int findKthFromEnd(LinkList list, int k) {
    if (!list || k <= 0) return 0;   // 参数非法

    LNode *fast = list->next;         // 快指针，先走 k 步
    LNode *slow = list->next;         // 慢指针，稍后同步

    // 快指针先走 k 步
    for (int i = 0; i < k; ++i) {
        if (!fast) return 0;         // 不足 k 个结点
        fast = fast->next;
    }

    // 同步后移，直到 fast 到达尾结点
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow 即倒数第 k 个结点
    cout << slow->data << endl;
    return 1;
}


int main()
{

}