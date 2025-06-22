#include <iostream>
#include <unordered_map>
using namespace std;

char repeatedCharacter(string s);

int main(void){

    string s = "eesll";
    char c = repeatedCharacter(s);
    cout << c;
    return 0;
}

// char repeatedCharacter(string s) {  solution 1
//     unordered_map<char, int>charList;
//     char c;
//     for(int i = 0; i < s.length(); i++){
//         int count = 1;
//         if(charList.find(s[i]) == charList.end()) charList[s[i]] = count;     
//         else{
//             c = s[i];
//             break;
//         } 
//     }
//     return c;
// }

char repeatedCharacter (string s)   //solution 2
{
    for (int i = 1; i < s.size (); i++){
        for (int j = i - 1; j >= 0; j--){
            if(s [i] == s [j]) return s[i];
        } 
    }
    return 'n';
}