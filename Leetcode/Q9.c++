#include <iostream>
using namespace std;

bool isPalindrome(int x);

int main(void){

    int x = 0;
    bool check = isPalindrome(x);
    check == true ? cout << "true" : cout << "false";
    return 0;
}

bool isPalindrome(int x){
    if(x < 0) return false;
    int n = x, y = 0;
    while(n > 0){
        y = y * 10 + n % 10;
        n /= 10;
    }
    return x == y;
}