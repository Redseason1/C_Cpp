#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums);

int main(void){

    vector<int> nums = {2,2,1};
    int n = singleNumber(nums);
    cout << n;
    return 0;
}

int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int i : nums){
        ans ^= i;  //XOR
    }
    return ans;
}