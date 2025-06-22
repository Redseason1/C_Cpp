#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target);

int main(void){

    vector<int> nums = {1,3,5,6};
    int target = 2;
    int n = searchInsert(nums, target);
    cout << n;

    // nums.insert(nums.begin() + n, target);
    // for(int i : nums){
    //     cout << i << " ";
    // }
    return 0;
}

int searchInsert(vector<int>& nums, int target){  //BS: 搜尋數值所在的index、可插入未在數列內的數值的index
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid;
        else left = mid + 1;
    }
    return left;
}