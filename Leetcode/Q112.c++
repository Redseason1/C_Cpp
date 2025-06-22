#include <iostream>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool hasPathSum(TreeNode* root, int targetSum);

int main(void){

    return 0;
}

bool hasPathSum(TreeNode* root, int targetSum){
    function<bool(TreeNode*, int)> dfs = [&](TreeNode* root, int n){
        if(!root) return false;
        n += root->val;
        if(!root->left && !root-> right && n == targetSum) return true;
        return dfs(root->left, n) || dfs(root->right, n);
    };
    return dfs(root, 0);
}