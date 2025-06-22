#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion();
int binary1(int left, int right, int n);
int binary2(int left, int right, int n);
void show();
void getRandomNum();

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    insertion();

    binary1(0, MAX_LENGTH - 1, 7) != -1 ? printf("%d is found\n", 7) : printf("Not found\n");
    binary2(0, MAX_LENGTH - 1, 10) != -1 ? printf("%d is found\n", 10) : printf("Not found\n");
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

int binary1(int left, int right, int n){  //迭代版
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(arr[middle] == n) return middle;
        else if(n > arr[middle]) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int binary2(int left, int right, int n){  //遞迴版
    if(left <= right){
        int middle = left + (right - left) / 2;
        if(arr[middle] == n) return middle;
        else if(n > arr[middle]) return binary2(middle + 1, right, n);
        else return binary2(left, middle - 1, n);
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