#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSameTree(TreeNode* p, TreeNode* q);

int main(void){

    return 0;
}

bool isSameTree(TreeNode* p, TreeNode* q){  //DFS
    if(p == q) return true;  //判斷兩樹是否都為空
    if(!(p && q) || p->val != q->val) return false;  //判斷任一樹是否為空，或者兩樹不為空，則判斷兩樹的根是否相等
    return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);  //根相等，則繼續判斷葉的值
}