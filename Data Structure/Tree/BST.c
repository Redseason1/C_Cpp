#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

Node *newNode(int v);
Node *insert(Node *root, int v);
Node *search(Node *root, int v);
Node *delete(Node * root, int v);
Node *findMin(Node *root);
Node *findMax(Node *root);
void inOrder(Node *root);
void preOrder(Node *root);
void postOrder(Node *root);

int main(){

    Node *root = newNode(20);
    insert(root, 5);  
    insert(root, 1);  
    insert(root, 15);  
    insert(root, 9);  
    insert(root, 7);  
    insert(root, 12);  
    insert(root, 30);  
    insert(root, 25);  
    insert(root, 40);  
    insert(root, 45);  
    insert(root, 42);
    inOrder(root);
    printf("\n");
    
    Node *node = search(root, 7);
    if(node != NULL) printf("%d is found\n", node->data);

    Node *min = findMin(root);
    Node *max = findMax(root);
    if(min != NULL && max != NULL){
        printf("The min node: %d\n", min->data);
        printf("The max node: %d\n", max->data);
    } 

    delete(root, 9);
    inOrder(root);
    printf("\n");

    printf("Inorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);

    return 0;
}

Node *newNode(int v){
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = v;
    root->leftChild = NULL;
    root->rightChild = NULL;
    return root;
}

Node *insert(Node *root, int v){
    if(root == NULL) return newNode(v);
    else if(v < root->data) root->leftChild = insert(root->leftChild, v);
    else root->rightChild = insert(root->rightChild, v);
    return root;
}

void inOrder(Node *root){  //由小到大排序
    if(root != NULL){
        inOrder(root->leftChild);
        printf("%d ", root->data);
        inOrder(root->rightChild);
    }
}

void preOrder(Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%d ", root->data);     
    }
}

Node *search(Node *root, int v){
    if(root == NULL) return NULL;
    else if(root->data == v) return root;
    else if(v < root->data) return search(root->leftChild, v);
    else return search(root->rightChild, v);
}

Node *findMin(Node *root){
    if(root == NULL) return NULL;
    else if(root->leftChild != NULL) return findMin(root->leftChild);
    return root;
}

Node *findMax(Node *root){
    if(root == NULL) return NULL;
    else if(root->rightChild != NULL) return findMax(root->rightChild);
    return root;
}


Node *delete(Node *root, int v){
    if(root == NULL) return NULL;
    else if(v < root->data) return delete(root->leftChild, v);  //刪除左子節點指定的值
    else if(v > root->data) return delete(root->rightChild, v); //刪除右子節點指定的值
    else{
        if(root->leftChild == NULL && root->rightChild == NULL){  //左右子節點都為空，刪除root
            free(root);
            return NULL;
        }
        else if(root->leftChild == NULL || root->rightChild == NULL){  //左右子節點其中一邊為空，保留子節點值，刪除root
            Node *tmp = root;
            if(root->leftChild == NULL) tmp = root->rightChild;
            else tmp = root->leftChild;
            free(root);
            return tmp;
        }
        else{   //刪除最下層右子節點的左子節點
            Node *tmp = findMin(root->rightChild);
            root->data = tmp->data;
            root->rightChild = delete(root->rightChild, tmp->data);
        }
    }
    return root; 
}