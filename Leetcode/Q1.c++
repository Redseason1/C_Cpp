#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main(void){

    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> output = twoSum(nums, target);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> discovered;

    for(int i = 0; i < nums.size(); i++){
        int num = target - nums[i];
        if(discovered.find(num) == discovered.end()) discovered[nums[i]] = i;
        else return {discovered[num], i};
    }
    return {};
}