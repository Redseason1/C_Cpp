#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

int minDepth(TreeNode* root);

int main(void){

    return 0;
}

int minDepth(TreeNode* root){
    if(!root) return 0;
    if(!root-> left) return 1 + minDepth(root->right);
    if(!root-> right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}