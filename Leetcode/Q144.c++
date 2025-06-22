#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> preorderTraversal(TreeNode* root);

int main(void){

    return 0;
}

vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    function<void(TreeNode*)> preorder = [&](TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    };
    preorder(root);
    return ans;
}