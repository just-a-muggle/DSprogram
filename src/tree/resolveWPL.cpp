#include <iostream>

using namespace std;

struct BiTNode{
    int weight;
    BiTNode *lChild;
    BiTNode *rChild;
    BiTNode(int x): weight(x), lChild(nullptr), rChild(nullptr){}
};

void 