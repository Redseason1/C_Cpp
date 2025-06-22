#include <iostream>
using namespace std;

int lengthOfLastWord(string s);

int main(void){

    string s ="    fly me   to   the moon  ";
    int n = lengthOfLastWord(s);
    cout << n;
    return 0;
}

int lengthOfLastWord(string s){
    int right = s.size() - 1, count = 0;
    while(s[right] == ' ') right--;
    for(int i = right; i >= 0; i--){
        if(s[i] == ' ') break;
        else count++;
    }
    return count;
}