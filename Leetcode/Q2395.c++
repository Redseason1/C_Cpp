#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool findSubarrays(vector<int>& nums);

int main(void){

    vector<int> nums = {1,2,3,4,5};
    bool check = findSubarrays(nums);
    check == true ? cout << "true" : cout << "false";
    return 0;
}


bool findSubarrays(vector<int>& nums) {
    unordered_set<int> vis;
    for(int i = 1; i < nums.size(); i++){
        int sum = nums[i] + nums[i - 1];
        if(vis.count(sum)) return true;
        vis.insert(sum);
    }
    return false;
}