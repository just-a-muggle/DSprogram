#include <iostream>
#include <vector>

using namespace std;

struct BiTNode{
    int weight;
    BiTNode *lChild;
    BiTNode *rChild;
    BiTNode(int x): weight(x), lChild(nullptr), rChild(nullptr){}
};

int WPL;

void PreOrder(BiTNode *root, int level){
    if(root == nullptr) return;
    if(root ->lChild == nullptr) WPL += level * root -> weight;
    PreOrder(root->lChild, level + 1);
    PreOrder(root->rChild, level + 1);
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
        if (left < n) nodes[i]->lChild = nodes[left];
        if (right < n) nodes[i]->rChild = nodes[right];
    }
    PreOrder(nodes.at(0), 1);
    cout << "WPL is :  "<< WPL;
  
    for (auto &node : nodes) delete node;
    cout << endl << ">> input any key to exit: ";
    cin.get();
    cin.get();
}