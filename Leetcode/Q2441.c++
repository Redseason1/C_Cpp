#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findMaxK(vector<int>& nums);

int main(void){

    vector<int> nums = {-1,2,-3,3};
    int n = findMaxK(nums);
    cout << n;
    return 0;
}

int findMaxK(vector<int>& nums){
    unordered_set<int> vis(nums.begin(), nums.end());
    int output = -1;
    for(int i : vis){
        if(vis.count(-i)) output = max(output, i);
    }
    return output;
}