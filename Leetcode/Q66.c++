#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits);

int main(void){

    vector<int> digits = {1,9};
    vector<int> n = plusOne(digits);
    for(int i : n){
        cout << i << " ";
    }  
    return 0;
}

vector<int> plusOne(vector<int>& digits){
    for(int i = digits.size() - 1; i >= 0; i--){
        digits[i]++;
        digits[i] %= 10;  //判斷是否為個位數的關鍵，不是則回傳vector
        if(digits[i] != 0) return digits;      
    }
    digits.insert(digits.begin(), 1);
    return digits;
}