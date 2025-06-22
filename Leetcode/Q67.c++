#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b);

int main(void){

    string a = "11";
    string b = "1"; 
    string s = addBinary(a, b);
    cout << s;
    return 0;
}

string addBinary(string a, string b){
    string output;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int count = 0;
    while(i >= 0 || j >= 0 || count){  //0: false, 1: true
        count += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
        output.push_back((count % 2) + '0');  //由後插入，ex: 0 -> 0 -> 1
        count /= 2;
        i--;
        j--;
    }
    reverse(output.begin(), output.end());  //所以需要反轉
    return output;
}