#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums);

int main(void){

    vector<int> nums = {3,2,3};
    int output = majorityElement(nums);
    cout << output;
    return 0;
}

int majorityElement(vector<int>& nums){  //找眾數，數列長度為奇數下
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}