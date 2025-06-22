#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax();
void count(int exp);
void radix();
void show();
void getRandomNum();

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    radix();
    show();
}

int getMax(){
    int max = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 1; i < size; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void count(int exp){
    int output[MAX_LENGTH];
    int i, count[10] = { 0 };  //位數0~9，所以設定count array為長度10，並且初始化每個為0

    for (i = 0; i < MAX_LENGTH; i++) count[(arr[i] / exp) % 10]++;  //紀錄數字出現的次數
    for (i = 1; i < 10; i++) count[i] += count[i - 1];  //計算prefix sum，也就是將當前index的element加上前一個index的element
    for (i = MAX_LENGTH - 1; i >= 0; i--) {  //從array後面往前排序
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];  //對照count array的key-value，接著value-1，把array當前值放進output[value-1]的位置
        count[(arr[i] / exp) % 10]--;  //把index往前一格，主要用在重複的element
    }
    for (i = 0; i < MAX_LENGTH; i++) arr[i] = output[i];
}

void radix(){
    int max = getMax();  //先找最大值，這個max會是count array的長度
    for(int exp = 1; max / exp > 0; exp *= 10) count(exp);  //exp是指數:10^n，位數決定執行次數
}

void show(){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The list: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void getRandomNum(){
    int i, r;
    srand((unsigned)time(NULL));
    for(i = 0; i < MAX_LENGTH; i++){
        r = rand() % 1000;
        arr[i] = r;
    }
}