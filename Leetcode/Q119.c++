#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex);

int main(void){

    int rowIndex = 3;
    vector<int> list = getRow(rowIndex);
    for(auto i : list){        
        cout << i << " ";       
    }
    return 0;
}

vector<int> getRow(int rowIndex){
    vector<int> a(rowIndex + 1, 1);
    for(int i = 2; i < rowIndex + 1; i++){
        for(int j = i - 1; j > 0; j--){
            a[j] += a[j - 1];
        }
    }
    return a;
}