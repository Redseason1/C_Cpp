#include <iostream>
using namespace std;

int hammingWeight(int n);

int main(void){

    int n = 11;
    int output = hammingWeight(n);
    cout << output;
    return 0;
}

int hammingWeight(int n){
    int ans = 0;
    while (n) {
        n -= (n & -n);
        ans++;
    }
    return ans;
}