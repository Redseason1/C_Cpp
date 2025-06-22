#include <iostream>
#include <vector>
using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k);

int main(void){

    vector<int> nums = {2,7,11,15};
    int key = 9, k = 1;
    vector<int> output = findKDistantIndices(nums, key, k);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}

vector<int> findKDistantIndices(vector<int>& nums, int key, int k){
    int n = nums.size();
    vector<int> ans;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < i - k || (j < n && nums[j] != key)) j++;
        if (j < n && j <= i + k) ans.push_back(i);
    }
    return ans;
}