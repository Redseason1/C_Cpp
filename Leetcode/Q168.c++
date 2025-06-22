#include <iostream>
using namespace std;

string convertToTitle(int columnNumber);

int main(void){

    int columnNumber = 28;
    string output = convertToTitle(columnNumber);
    cout << output;
    return 0;
}

string convertToTitle(int columnNumber){
    string s;
    while(columnNumber){
        s.insert(s.begin(), 'A' + (columnNumber - 1) % 26);
        columnNumber = (columnNumber - 1) / 26;
    }
    return s;
}