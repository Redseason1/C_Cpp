#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int a, int b);
void insertion(int l, int r);
void merge(int l, int m, int r);
void tim();
void show();
void getRandomNum();

#define MAX_LENGTH 10
#define RUN 32
int arr[MAX_LENGTH];

int main(){

    getRandomNum();
    show();

    tim();
    show();
}

int min(int a, int b){
    return a > b ? b : a;
}

void insertion(int l, int r){
    for (int i = l + 1; i <= r; i++) { 
        int tmp = arr[i]; 
        int j = i - 1; 
        while (j >= l && arr[j] > tmp){ 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = tmp; 
    }
}

void merge(int l, int m, int r){
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i]; 
  
    int i = 0; 
    int j = 0; 
    int k = l; 

    while (i < len1 && j < len2) { 
        if (left[i] <= right[j]) { 
            arr[k] = left[i]; 
            i++; 
        } 
        else { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    }

    while (i < len1) { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 

    while (j < len2) { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
}   

void tim(){
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i += RUN) insertion(i, min((i + RUN - 1), (size - 1)));
    for(int j = RUN; j < size; j = 2 * j){
        for (int left = 0; left < size; left += 2 * j){
            int mid = left + j - 1; 
            int right = min((left + 2 * j - 1), (size - 1));
            if(mid < right) merge(left, mid, right);
        }
    }
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