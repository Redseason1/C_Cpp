#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax();
void bucketSort();
void show();
void getRandomNum();

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    bucketSort();
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

void bucketSort(){
    int max = getMax();
    int bucket[max];
    for (int i = 0; i <= max; i++) bucket[i] = 0;
    for (int i = 0; i < MAX_LENGTH; i++) bucket[arr[i]]++;  //紀錄數字的位置
    for (int i = 0, j = 0; i <= max; i++) {
        while (bucket[i] > 0){
            arr[j++] = i;  //一直遍歷array元素，直到發現最一開始的數字位置，array的起始位置就會放置最一開始的數字
            bucket[i]--;   //找到數值後，當前數字位置歸零，即判斷已經排序
        }
    }
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