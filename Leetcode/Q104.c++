#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

int maxDepth(TreeNode* root);

int main(void){

    return 0;
}

int maxDepth(TreeNode* root){
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}