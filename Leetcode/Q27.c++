#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val);

int main(void){

    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int n = removeElement(nums, val);
    for(int i : nums){
        cout << i << " ";
    }
    // cout << n;
    return 0;
}

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for(int i : nums){
        if(i != val) nums[k++] = i;
    }
    return k;
}