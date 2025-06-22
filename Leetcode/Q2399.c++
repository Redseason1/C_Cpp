#include <iostream>
#include <vector>
using namespace std;

bool checkDistances(string s, vector<int>& distance);

int main(void){

    string s = "abaccb";
    vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool check = checkDistances(s, distance);
    check == true ? cout << "true" : cout << "false";
    return 0;
}

bool checkDistances(string s, vector<int>& distance){
    int d[26] = {};
    for (int i = 1; i <= s.size(); i++) {
        int j = s[i - 1] - 'a';
        if (d[j] && i - d[j] - 1 != distance[j]) return false;
        d[j] = i;
    }
    return true;
}