////////////////////
/// Author: Achang
/// Date: 2025/9/7
/// Version: 1.0
////////
#include <iostream>
#include <vector>

using namespace std;
struct BiTNode{
    int data;
    BiTNode *lChild;
    BiTNode *rChild;
    BiTNode(int x): data(x), lChild(nullptr), rChild(nullptr){}
};

int temp = -100010;
bool isBST = true;

void InOrder(BiTNode *root){
    if(root == nullptr) return;
    InOrder(root ->lChild);
    if(root->data >= temp) temp = root->data;
    else isBST = false;
    InOrder(root->rChild);
}

///测试///
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
        if (left < n) nodes[i]->lChild = nodes[left];
        if (right < n) nodes[i]->rChild = nodes[right];
    }

    InOrder(nodes.at(0));
    if (isBST)
        cout << "Yes, it is BST";
    else 
        cout << "No, it is not BST";
  
    
    for (auto &node : nodes) delete node;
    cout << endl << ">> input any key to exit: ";
    cin.get();
    cin.get();
}
