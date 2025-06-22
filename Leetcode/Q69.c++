#include <iostream>
using namespace std;

int mySqrt(int x);

int main(void){

    int n = 4;
    int output = mySqrt(n);
    cout << output;
    return 0;
}

int mySqrt(int x){  //牛頓逼近法
    if(x == 0) return 0;
    double a = 1, b = 0, epsilon = 1e-6;
    while(abs(a - b) > epsilon){
        b = a;
        a = (a + x / a) / 2;
    }
    return a;
}