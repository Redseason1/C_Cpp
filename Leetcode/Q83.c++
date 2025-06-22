#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* deleteDuplicates(ListNode* head);

int main(void){

    return 0;
}

ListNode* deleteDuplicates(ListNode* head){
    ListNode* current = head;
    while(current != nullptr && current->next != nullptr){
        if(current->val == current->next->val) current->next = current->next->next;
        else current = current->next;
    }
    return head;
}