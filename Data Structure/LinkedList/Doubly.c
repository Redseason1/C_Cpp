#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *head;

void insertAtHead(int v);
void insertNth(Node *node, int v);
Node *search(int v);
void modify(Node *node, int v);
void delete(int v);
void sort();
void reverse();
void insertAtTail(int v);
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
    printf("The list: tail=");
    Node *current = head;
    while(current != NULL){
        printf("%d=", current->data);
        current = current->next;
    }
    printf("head\n");

    insertAtTail(13);
    show();

    return 0;
}

void insertAtHead(int v){
    Node *current = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        current->next = NULL;
        current->prev = NULL;
        current->data = v;
        head = current;
    }else{
        current->data = v;
        current->prev = NULL;
        current->next = head;
        head->prev = current;
        head = current;
    }
};

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
        current->prev = tmp;
        current->next = NULL;
    }
};

void insertNth(Node *node, int v){
    Node *current = (Node*)malloc(sizeof(Node));
    current->data = v;
    current->next = node->next;
    current->prev = node;
    node->next = current;
    node->next->prev = current;
}

Node *search(int v){
    Node *current = head;
    while(current != NULL){
        if(current->data == v) return current;
        current = current->next;
    }
    return NULL;
}

void modify(Node *node, int v){
    node->data = v;
}

void delete(int v){
    Node *current = head;
    // Node *tmp;
    while(current->next != NULL){
        if(current->next->data == v){
            // tmp = current->next;
            // current->next = tmp->next->next;
            // tmp->next->prev = current;
            // free(tmp);
            current->next = current->next->next;
            current->next->next->prev = current;   
        }
        current = current->next;
    }
}

void sort(){
    int tmp;
    for(Node *i = head; i->next != NULL; i = i->next){
        for(Node *j = head; j->next != NULL; j = j->next){
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
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void show(){
    Node *current = head;
    printf("The list: head=");
    while(current != NULL){
        printf("%d=", current->data);
        current = current->next;
    }
    printf("tail\n");
}