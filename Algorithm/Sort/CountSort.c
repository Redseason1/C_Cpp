#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void count();
void show();
void getRandomNum();

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    count();
    show();
}

void count(){
    int output[MAX_LENGTH];
    int i, count[10] = { 0 };  //位數0~9，所以設定count array為長度10，並且初始化每個為0

    for (i = 0; i < MAX_LENGTH; i++) count[arr[i]]++;  //紀錄數字出現的次數
    for (i = 1; i < 10; i++) count[i] += count[i - 1];  //計算prefix sum，也就是將當前index的element加上前一個index的element
    for (i = MAX_LENGTH - 1; i >= 0; i--) {  //從array後面往前排序
        output[count[arr[i]] - 1] = arr[i];  //對照count array的key-value，接著value-1，把array當前值放進output[value-1]的位置
        count[arr[i]]--;  //把index往前一格，主要用在重複的element
    }
    for (i = 0; i < MAX_LENGTH; i++) arr[i] = output[i];
}

void show(){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The list: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void getRandomNum(){  //洗牌法，先把數字放進陣列，接著透過隨機數當作key，讓起始位置與隨機數key位置交換
    int i, r, tmp;
    srand((unsigned)time(NULL));
    for(i = 0; i < MAX_LENGTH; i++){
        arr[i] = i;
    }

    for(i = 0; i < MAX_LENGTH; i++){
        r = rand() % 10;
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
}