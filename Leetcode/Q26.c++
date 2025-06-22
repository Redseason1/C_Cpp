#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums);

int main(void){

    vector<int> nums = {1,1,2};
    // vector<int>::iterator u = unique(nums.begin(), nums.end());
    // for(u = nums.begin(); u != nums.end(); u++){
    //     cout << *u;
    // }
    int n = removeDuplicates(nums);
    cout << n;
    return 0;
}

int removeDuplicates(vector<int>& nums){
    nums.erase(unique(nums.begin(), nums.end()), nums.end());  //erase(unique回傳nums重複的起始index, nums的最後index)，erase為消除index範圍內元素
    return nums.size();
}