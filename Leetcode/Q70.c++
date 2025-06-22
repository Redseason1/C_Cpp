#include <iostream>
using namespace std;

int climbStairs(int n);

int main(void){

    int n = 4;
    int output = climbStairs(n);
    cout << output;
    return 0;
}

int climbStairs(int n){
    int ways[n + 1];
    ways[0] = 1;
    ways[1] = 1;
    for(int i = 2; i <= n; i++){
        ways[i] = ways[i - 1] + ways[i - 2];
    }       
    return ways[n];
}