////////////////////
/// Author: Achang
/// Date: 2025/9/5
/// Version: 1.0
////////
#include <iostream>
#include <vector>

using namespace std;

struct BiTNode{ //Binary Tree Node
    int data;                  //节点数据
    BiTNode *lchild, *rchild;  //左孩子和右孩子
    BiTNode(int x): data(x), lchild(NULL), rchild(NULL){}
};

void visit(BiTNode *root){
    if(root != NULL){
        cout << root->data << " ";
    }
}

void PreOrder(BiTNode *root){   //前序遍历
    if(root != NULL){
        visit(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void InOrder(BiTNode *root){    //中序遍历
    if(root != NULL){
        InOrder(root->lchild);
        visit(root);
        InOrder(root->rchild);
    }
}

void PostOrder(BiTNode *root){  //后序遍历
    if(root != NULL){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        visit(root);
    }
}

int main()
{   
    int n;
    cout << ">> create binary_tree: " << endl << ">> inputs how many Nodes you need :";
    cin >> n;

    if (n == 0) {
        cout << ">> Empty tree." << endl;
        return 0;   
    }   

    vector<BiTNode*> nodes;
    nodes.reserve(n); //为nodes动态数组分配至少n个元素空间

    for(int i = 0; i < n; i++) nodes.push_back(new BiTNode(i));

    for(int i = 0; i < n; i ++){ //构建的是完全二叉树
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n) nodes[i]->lchild = nodes[left];
        if (right < n) nodes[i]->rchild = nodes[right];
    }
    
    cout << endl << ">> PreOrder: ";
    PreOrder(nodes.at(0));
    cout << endl << ">> InOrder: ";
    InOrder(nodes.at(0));
    cout << endl << ">> PostOrder: ";
    PostOrder(nodes.at(0));

    
    cout << endl << ">> input any key to exit: ";
    cin.get();
    cin.get();
}