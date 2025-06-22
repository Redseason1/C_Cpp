#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

void insertion();
int binary(int left, int right, int n);
int exponential(int n);
int min(int a, int b);
void show();
void getRandomNum();

int main(){

    getRandomNum();
    show();
    insertion();

    exponential(7) != -1 ? printf("%d is found\n", 7) : printf("Not found\n");
    exponential(10) != -1 ? printf("%d is found\n", 10) : printf("Not found\n");
}

void insertion(){  //選擇最大或最小值插入最起始位置
    int j, tmp;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

int min(int a, int b){
    if(a > b) return b;
    else return a;
}

int exponential(int n){
    if(arr[0] == n) return 0;

    int index = 1;
    while(index < MAX_LENGTH && arr[index] <= n){
        index *= 2;
    }
    return binary((index / 2), min(index - 1, MAX_LENGTH - 1), n);
}

int binary(int left, int right, int n){  //遞迴版
    if(left <= right){
        int middle = left + (right - left) / 2;
        if(arr[middle] == n) return middle;
        else if(n > arr[middle]) return binary(middle + 1, right, n);
        else return binary(left, middle - 1, n);
    }
    return -1;
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