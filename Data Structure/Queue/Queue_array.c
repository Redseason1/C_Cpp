#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 5
#define EMPTY (-1)

int queue[MAX_LENGTH];
int head = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void show();

int main(){

    for(int i = 0; i < 5; i++){
        enqueue(i);
    }
    show();

    dequeue();
    show();

    return 0;
}

void enqueue(int value){
    if(rear >= MAX_LENGTH-1) printf("overflow");
    rear++;
    queue[rear] = value;
}

void dequeue(){
    if(rear == EMPTY) printf("it's empty");
    int result = queue[head + 1];

    //shift all of the element forword
    for (int i = 1; i <= rear;i++){
        queue[i - 1] = queue[i];
    }
    queue[rear] = 0;
    rear--;
}

void show(){
    int size = sizeof(queue) / sizeof(queue[0]);
    printf("The queue: ");
    for(int i = 0; i < size; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}