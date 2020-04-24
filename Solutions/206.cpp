#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ListNode* last = NULL;
ListNode* DFS(ListNode* head){
    ListNode* next = head->next;
    head->next = last;
    last = head;
    if(next==NULL) return last;
    return DFS(next);
}

ListNode* reverseList(ListNode* head) {
    if(head==NULL) return head;
    return DFS(head);
}

//ListNode* reverseList(ListNode* head) {
//    if(head==NULL) return head;
//    ListNode* last = NULL;
//    while(head){
//        ListNode* next = head->next;
//        head->next = last;
//        last = head;
//        head = next;
//    }
//    return last;
//}
