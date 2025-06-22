#include <iostream>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isBalanced(TreeNode* root);

int main(void){

    return 0;
}

bool isBalanced(TreeNode* root){
    function<int(TreeNode*)> height = [&](TreeNode* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if(l == -1 || r == -1 || abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    };
    return height(root) >= 0;
}