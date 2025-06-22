#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main(void){

    return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *a = headA, *b = headB;
    while(a != b){
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}