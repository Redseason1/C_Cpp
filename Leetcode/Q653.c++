#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};


int main(void){

    return 0;
}

bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);  //由小到大排序
    int i = 0, j = nums.size() - 1;
    while(i < j){
        int sum = nums[i] + nums[j];
        if(sum == k) return true;
        (sum < k) ? i++ : j--;
    }
    return false;
}

void inorder(TreeNode* node, vector<int> &nums){
    if(!node) return;
    inorder(node->left, nums);
    nums.push_back(node->val);
    inorder(node->right, nums);
}