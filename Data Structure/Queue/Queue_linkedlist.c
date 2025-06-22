#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *front;
Node *rear;

void insert(int v);
void delete();
void show();

int main(){

    for(int i = 0; i < 10; i++){
        insert(i);
    }
    show();

    delete();
    show();
}

void insert(int v){
    Node *current = (Node*)malloc(sizeof(Node));
    current->data = v;
    if(front == NULL){
        front = current;  
        rear = current;   
        front->next = NULL;  
        rear->next = NULL;  
    }else{
        rear->next = current;  
        rear = current;  
        rear->next = NULL; 
    }
}

void delete(){
    Node *current;
    current = front;  
    front = front->next;  
    free(current); 
}

void show(){
    Node *current = front;
    printf("front ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("rear\n");
}