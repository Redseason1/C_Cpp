#include <iostream>
using namespace std;

int titleToNumber(string columnTitle);

int main(void){

    string columnTitle = "AB";
    int output = titleToNumber(columnTitle);
    cout << output;
    return 0;
}

int titleToNumber(string columnTitle){
    int ans = 0;
    for (char c : columnTitle) {
        ans = ans * 26 + (c - 'A' + 1);
    }
    return ans;
}