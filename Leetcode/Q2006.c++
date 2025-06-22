#include <iostream>
#include <vector>
using namespace std;

int countKDifference(vector<int>& nums, int k);

int main(void){

    vector<int> nums = {1, 2, 2, 1};
    int target = 1;
    int ans = countKDifference(nums, target);
    cout << ans;
    return 0;
}

int countKDifference(vector<int>& nums, int k){
    int size = nums.size(), count = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(abs(nums[i] - nums[j]) == k) count++;
        }
    }
    return count;
}