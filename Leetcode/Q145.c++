#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> postorderTraversal(TreeNode* root);

int main(void){

    return 0;
}

vector<int> postorderTraversal(TreeNode* root){
    vector<int> ans;
    function<void(TreeNode*)> postorder = [&](TreeNode* root){
        if(!root) return;   
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    };
    postorder(root);
    return ans;
}