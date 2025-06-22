#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *head;

Node *createNode(int v);
void insertAtHead(int v);
void insertAtTail(int v);
void insertNth(Node *node, int v);
Node *search(int v);
void modify(Node *node, int v);
void delete(int v);
void sort();
void reverse();
void show();
void showRecursion(Node *node);

int main(){

    Node *tmp;
    int val;
    
    // printf("Enter the numbers; -1 to quit\n");
    // do{  
    //     scanf("%d", &val);
    //     if(val == -1) break;
    //     insert(val);   
    // }while(val != -1);
    for(int i = 0; i < 10; i++){
        //tmp = createNode(i);
        insertAtHead(i); 
    }
    show();
    //showRecursion(head);
    
    if (search(5) != NULL){
        Node *node = search(5);
        modify(node, 11);
    }
    show();
    //showRecursion(head);

    
    delete(11);
    show();
    //showRecursion(head);

    insertNth(search(6), 55);
    show();
    //showRecursion(head);

    sort();
    show();
    //showRecursion(head);

    reverse();
    printf("The list: null-");
    Node *current = head;
    while(current != NULL){
        printf("%d-", current->data);
        current = current->next;
    }
    printf("head\n");
    //showRecursion(head);

    insertAtTail(13);
    show();

    return 0;
}

Node *createNode(int v){  //創造無數個節點，next都指向null
    Node *current = (Node*)malloc(sizeof(Node));
    current->data = v;
    current->next = NULL;
    return current;
}

void insertAtHead(int v){  //把current node link到head，head link到current node，插入的node link head
    Node *current = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        current->data = v;
        current->next = NULL;
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
        current->next = NULL;
    }
}

void show(){
    Node *current = head;
    printf("The list: head-");
    while(current != NULL){
        printf("%d-", current->data);
        current = current->next;
    }
    printf("null\n");
}

void showRecursion(Node *node){
    if(node == NULL) return;
    printf("%d ", node->data);
    showRecursion(node->next);
}

void insertNth(Node *node, int v){  //先創建欲插入node，將current node link到欲被插入的node後，和被插入的node link的節點
    //Node *current = createNode(v);
    Node *current = (Node*)malloc(sizeof(Node));
    current->data = v; 
    current->next = node->next;  //current node連結後一個node
    node->next = current;   //前一個node連結current node
}

Node *search(int v){
    Node *current = head;
    while(current->next != NULL){
        if(current->data == v){
            //printf("Found %d at position [%d]\n", tmp->data, count);
            return current;
        }
        current = current->next;
    }
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
    Node *current = head;
    while(current->next != NULL){
        if(current->next->data == v){
            current->next = current->next->next;
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