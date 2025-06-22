#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int>&nums, int target);
int arithmeticTriplets(vector<int>& nums, int diff);

int main(void){

    vector<int> nums = {4,5,6,7,8,9};
    int diff = 2;
    int ans = arithmeticTriplets(nums, diff);
    cout << ans;
    return 0;
}

bool binarySearch(vector<int>&nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int arithmeticTriplets(vector<int>& nums, int diff){
    int counter = 0;
    for (int i = 0; i < nums.size(); i++){
        if(binarySearch(nums, nums[i] + diff) && binarySearch(nums, nums[i] + (2 * diff))) counter ++;
    }
    return counter;
}