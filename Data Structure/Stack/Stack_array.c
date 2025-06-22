#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 5
#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define STACK_EMPTY INT_MIN

int stack[MAX_LENGTH];
int top = EMPTY;

bool push(int val);
void pop();
void peek();
void show();

int main(){

    int num;
    for(int i = 1; i < 6; i++){
        push(i);
    }
    show();
    peek();

    pop();
    
    show();
    peek();
    return 0;
}

bool push(int val){
    if (top >= MAX_LENGTH - 1) return false;  //isFull()
    top++;
    stack[top] = val;
    return true;
}

void pop(){
    if (top == EMPTY) printf("it's empty");  //isEmpty()
    stack[top] = 0;
    top--;
}

void peek(){
    printf("The peek: %d\n", stack[top]);
}

void show(){
    int size = sizeof(stack) / sizeof(stack[0]);
    printf("The stack: \n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
    printf("\n");
}