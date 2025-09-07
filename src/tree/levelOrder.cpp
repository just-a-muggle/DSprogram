////////////////////
/// Author: Achang
/// Date: 2025/9/5
/// Version: 1.0
////////

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

struct BiTNode
{
    int data;
    BiTNode *lChild;
    BiTNode *rChild;
    BiTNode(int x):data(x),lChild(NULL),rChild(NULL){}
};

vector<int> levelOrder(BiTNode *root)
{
    queue<BiTNode *> queue;
    queue.push(root);

    vector<int> vec;

    while (!queue.empty())
    {
        BiTNode *node = queue.front();
        queue.pop();
        vec.push_back(node->data);

        if(node->lChild != NULL) queue.push(node->lChild);
        if(node->rChild != NULL) queue.push(node->rChild);
    }
    return vec;
}

int main()
{
    BiTNode *root = new BiTNode(1);
    root->lChild = new BiTNode(2);
    root->rChild = new BiTNode(3);
    root->lChild->lChild = new BiTNode(4);
    root->lChild->rChild = new BiTNode(5);
    root->rChild->rChild = new BiTNode(6);

    vector<int> res = levelOrder(root);

    cout << "Level Order Traversal: ";
    for(int x : res) cout << x << " ";
    cout << endl;

    cin.get();
    cin.get();
}