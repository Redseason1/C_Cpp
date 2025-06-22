#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows);

int main(void){

    int numRows = 5;
    vector<vector<int>> list = generate(numRows);
    for(auto i : list){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}

vector<vector<int>> generate(int numRows){
    vector<vector<int>> a;
    a.push_back(vector<int>(1, 1));  //row: 1, column: 1
    for(int i = 0; i < numRows - 1; i++){
        vector<int> b;
        b.push_back(1);
        for(int j = 0; j < a[i].size() - 1; j++){
            b.push_back(a[i][j] + a[i][j + 1]);
        }
        b.push_back(1);
        a.push_back(b);
    }
    return a;
}