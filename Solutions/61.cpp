#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL) return head;
    int len = 0;
    ListNode* tail, *cur=head;
    while(cur) {
        cur=cur->next, len++;
        if(cur&&cur->next==NULL) tail=cur;
    }
    k = k%len;
    if(k==0) return head;
    k = len-k, len=1, cur=head;
    while(len<k) cur=cur->next, len++;
    ListNode* res = cur->next;
    cur->next=NULL, tail->next=head;
    return res;
}
