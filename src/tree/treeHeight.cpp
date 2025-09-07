////////////////////
/// Author: Achang
/// Date: 2025/9/5
/// Version: 1.0
////////
#include <iostream>
#include <vector>
using namespace std;

struct BiTNode{
    int data;
    BiTNode *lChild;
    BiTNode *rChild;
    BiTNode(int x): data(x), lChild(NULL), rChild(NULL){}
};

int height = 0;
void func1_preOrder(BiTNode *root, int n){  //采用先序遍历
    if(root == NULL) return;
    if(n > height) height = n;  //更新树的高度

    func1_preOrder(root->lChild, n + 1); //遍历左子树
    func1_preOrder(root->rChild, n + 1); //遍历右子树
}

int func2_postOrder(BiTNode *root){ 
    if(root == NULL) return 0;
    int left = func2_postOrder(root->lChild);   //通过递归迭代左子树的高度
    int right = func2_postOrder(root->rChild);  //通过递归迭代右子树的高度

    if(left > right) return left + 1;           //比较并且选择迭代左还是右，最终的答案在此处给出
    else return right + 1;
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

    func1_preOrder(nodes.at(0), 1);
    cout << ">> use func1_preOrder:" << height <<endl;

    cout << ">> use func2_postOrder:"<< func2_postOrder(nodes.at(0)) << endl;
    
    for (auto &node : nodes) delete node;
    cout << endl << ">> input any key to exit: ";
    cin.get();
    cin.get();
}
