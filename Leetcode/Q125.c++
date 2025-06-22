#include <iostream>
using namespace std;

bool isPalindrome(string s);

int main(void){

    string s = "A man, a plan, a canal: Panama";
    isPalindrome(s) == true ? cout << "true" : cout << "false";
    return 0;
}

bool isPalindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(!isalnum(s[i])) i++;
        else if(!isalnum(s[j])) j--;
        else if(tolower(s[i]) != tolower(s[j])) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}