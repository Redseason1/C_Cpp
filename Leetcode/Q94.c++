#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> inorderTraversal(TreeNode* root);

int main(void){

    return 0;
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> output;
    stack<TreeNode*> stk;
    while(root || stk.size()){
        if(root){
            stk.push(root);
            root = root->left;
        }
        else{
            root = stk.top();
            stk.pop();
            output.push_back(root->val);
            root = root->right;
        }
    }
    return output;
}