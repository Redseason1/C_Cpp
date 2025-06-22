#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

bool isHappy(int n);

int main(void){

    int n = 19;
    int output = isHappy(n);
    output == true ? cout << "true" : cout << "false";
    return 0;
}

bool isHappy(int n){
    unordered_set<int> list;        
    while(n != 1 && !list.count(n)){  //如果n不為1或n重複，則不是快樂數
        list.insert(n);
        int sum = 0;
        while(n > 0){
            sum += pow(n % 10, 2);
            n /= 10;
        }
        n = sum;                      
    }
    return n == 1;
}