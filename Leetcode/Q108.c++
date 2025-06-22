#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* sortedArrayToBST(vector<int>& nums);

int main(void){

    return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode*{
        if(l > r) return nullptr;
        int mid = (l + r) / 2;
        auto left = dfs(l, mid - 1);
        auto right = dfs(mid + 1, r);
        return new TreeNode(nums[mid], left, right);
    };
    return dfs(0, nums.size() - 1);
}