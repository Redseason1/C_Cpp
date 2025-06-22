#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *head;

Node *insertAtHead(int v);
void insertAtTail(int v);
void insertNth(Node *node, int v);
Node *search(int v);
void modify(Node *node, int v);
void delete(int v);
void sort();
void reverse();
void show();

int main(){

    for(int i = 0; i < 10; i++){
        insertAtHead(i); 
    }
    show();

    if (search(5) != NULL){
        Node *node = search(5);
        modify(node, 11);
    }
    show();

    delete(11);
    show();

    insertNth(search(6), 55);
    show();

    sort();
    show();

    reverse();
    printf("The list: -");
    Node *current = head;
    while(current != NULL){
        printf("%d-", current->data);
        current = current->next;
    }
    printf("head\n");
}

Node *insertAtHead(int v){  
    Node *current = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        current->data = v;
        current->next = current;  //與siglely不同，最後指向自己
        head = current;
    }else{
        current->data = v;
        current->next = head->next;
        head->next = current;
    }
}

void insertAtTail(int v){
    Node *current = (Node*)malloc(sizeof(Node));
    Node *tmp;
    if(head == NULL) insertAtHead(v);
    else{
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        current->data = v;
        tmp->next = current;
        current->next = head->next;
    }
}

void insertNth(Node *node, int v){
    Node *current = (Node*)malloc(sizeof(Node));
    current->data = v;
    current->next = node->next;  //current node連結後一個node
    node->next = current;   //前一個node連結current node
}

void show(){
    if (head == NULL) printf("\nList is empty\n");
    else {
        Node *current = head->next;
        printf("The list: head-");
        do {
            printf("%d-", current->data);
            current = current->next;
        } while (current != head->next);
    }
    printf("\n");
}

Node *search(int v){
    Node *current = head->next;
    do{
        if(current->data == v){
            //printf("Found %d at position [%d]\n", tmp->data, count);
            return current;
        }
        current = current->next;
    }while(current != head->next);
    //printf("Not found %d in the linkedlist\n", v);
    return NULL;
}

void modify(Node *node, int v){
    // Node *current = head;
    // while(current->next != NULL){
    //     if(current->data == v1){
    //         current->data = v2;
    //     }
    //     current = current->next;
    // }
    node->data = v;
}

void delete(int v){
    Node *current = head->next;
    do{
        if(current->next->data == v){
            current->next = current->next->next;
        }
        current = current->next;
    }while(current->next != head->next);
}

void sort(){
    int tmp;
    for(Node *i = head->next; i != head; i = i->next){
        for(Node *j = head->next; j != head; j = j->next){
            if(i->data > j->data){
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void reverse(){
    Node *current, *prev, *next;
    current = head->next;
    prev = NULL;
    while(current != head){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}