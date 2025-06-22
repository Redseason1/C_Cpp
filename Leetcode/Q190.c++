#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n);

int main(void){

    uint32_t n = 11111111111111111111111111111101;
    int output = reverseBits(n);
    cout << output;
    return 0;
}

uint32_t reverseBits(uint32_t n){
    uint32_t ans = 0;
    for (int i = 0; i < 32 && n; ++i) {
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ans;
}