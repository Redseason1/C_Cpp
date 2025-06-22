#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int distinctAverages(vector<int>& nums);

int main(void){

    vector<int> nums = {4,1,4,0,3,5};
    int n = distinctAverages(nums);
    cout << n;
    return 0;
}

int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_set<float> vis;
    int i = 0;
    int n = nums.size() - 1;
    while(i <= n){
        vis.insert((nums[i] + nums[n]) / 2.0);
        i++;
        n--;
    }
    return vis.size();
}