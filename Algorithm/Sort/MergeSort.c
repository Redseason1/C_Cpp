#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

void merge(int left, int middle, int right);
void mergeSort(int left, int right);
void swap(int *a, int *b);
void getRandomNum();
void show();

int main(){

    getRandomNum();
    show();

    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(0, size - 1);
    show();
}

void merge(int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[left + i];  //copy data to left array
    for (j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];  //copy data to right array

    //merge left array and right array into the merged array
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the remaining left elements into the merged array if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //copy the remaining right elements into the merged array if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right){
    if (left < right) {
        int middle = left + (right - left) / 2;
 
        mergeSort(left, middle);
        mergeSort(middle + 1, right);

        merge(left, middle, right);
    }
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void getRandomNum(){  //洗牌法，先把數字放進陣列，接著透過隨機數當作key，讓起始位置與隨機數key位置交換
    int i, r, tmp;
    srand((unsigned)time(NULL));
    for(i = 0; i < MAX_LENGTH; i++){
        arr[i] = i;
    }

    for(i = 0; i < MAX_LENGTH; i++){
        r = rand() % 10;
        swap(&arr[i], &arr[r]);
    }
}

void show(){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The list: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}