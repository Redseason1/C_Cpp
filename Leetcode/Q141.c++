#include <iostream>
#include <set>
using namespace std;

struct ListNode*{
    int val;
    ListNode* next;
}

bool hasCycle(ListNode *head);

int main(void){

    return 0;
}

bool hasCycle(ListNode *head){
    // hash table
    // set<ListNode*> list;
    // while(head != nullptr){
    //     if(list.contains(head)) return true;
    //     list.insert(head);
    //     head = head->next;
    // }
    // return false;

    // fast and slow pointer
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}