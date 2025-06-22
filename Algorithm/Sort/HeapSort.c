#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
int arr[MAX_LENGTH];

void swap(int *a, int *b);
void heapify(int arr[], int size, int i);
void heap();
void getRandomNum();
void show();

int main(){

    getRandomNum();
    show();

    heap();
    show();
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int size, int i){
    //find the largest among all nodes
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]) largest = left;  //if left child > the root
    if(right < size && arr[right] > arr[largest]) largest = right;  //if right child > the root
    if(largest != i){  //coutinue swap and heapify if the root is not the largest
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap(){  //改良版selection，取較大值先排序
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);  //build max heap tree
    for(i = size - 1; i >= 0; i--){  //heap sort
        //heapify the root and get max element
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
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