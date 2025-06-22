#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *head;

void push(int v);
void pop();
void show();
void peek();

int main(){
    
    for(int i = 0; i < 10; i++){
        push(i);
    }
    pop();
    show();
    peek();

    return 0;
}

void push(int v){
    Node *current = (Node*)malloc(sizeof(Node));

    if(head == NULL){
        current->data = v;
        current->next = NULL;
        head = current;
    }else{
        current->data = v;
        current->next = head;
        head = current;
    }
}

void pop(){
    Node *current;
    current = head;
    head = head->next;
    free(current);
}

void show(){
    Node *current = head;
    printf("The stack\n");
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void peek(){
    Node *top = head;
    if(top != NULL) printf("The peek: %d\n", top->data);
    else printf("The stack is empty");
}