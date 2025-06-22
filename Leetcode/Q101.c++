#include <iostream>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSymmetric(TreeNode* root);

int main(void){

    return 0;
}

bool isSymmetric(TreeNode* root){
    function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->val != root2->val) return false;
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    };
    return dfs(root, root);
}