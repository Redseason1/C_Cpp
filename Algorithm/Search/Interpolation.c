#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

void insertion();
int interPolation(int n);
void show();
void getRandomNum();

int main(){

    getRandomNum();
    show();
    insertion();
    interPolation(7) ? printf("%d is found\n", 7) : printf("Not found\n");
    interPolation(10) != -1 ? printf("%d is found\n", 10) : printf("Not found\n");
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

int interPolation(int n){
    int left = 0;
    int right = MAX_LENGTH - 1;

    while(n >= arr[left] && n <= arr[right] && left <= right){
        int index = left + (n - arr[left]) / (arr[right] - arr[left]) * (right - left);
        if(left == right){
            if(arr[left] == n) return left;
            else return -1;
        }

        if(n == arr[index]) return index;
        else if(n > arr[index]) left = index + 1;
        else right = index - 1;
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