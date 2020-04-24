#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c=0, k;
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while(l1 || l2){
        int a=0, b=0;
        if(l1) a=l1->val;
        if(l2) b=l2->val;
        k = (c+a+b)%10;
        c = (c+a+b)/10;
        ListNode *tmp = new ListNode(k);
        cur->next = tmp;
        cur = cur->next;
        if(l1)l1=l1->next;
        if(l2) l2=l2->next;
    }
    if(c!=0){
        ListNode *tmp = new ListNode(c);
        cur->next = tmp;
    }
    return head->next;
}
