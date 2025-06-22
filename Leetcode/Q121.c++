#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices);

int main(void){

    vector<int> prices = {7,1,5,3,6,4};
    int profit = maxProfit(prices);
    cout << profit;
    return 0;
}

int maxProfit(vector<int>& prices){
    int ans = 0, mi = prices[0];
    for(int i : prices){
        mi = min(i, mi);
        ans = max(ans, i - mi);    
    }
    return ans;
}