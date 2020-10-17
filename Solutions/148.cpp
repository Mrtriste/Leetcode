#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <functional>

using namespace std;

ListNode* merge(ListNode* a, ListNode* b){
    ListNode* i=a, *j=b;
    ListNode* head = new ListNode();
    ListNode* cur=head;
    while(i&&j){
        if(i->val<j->val) cur->next=i, i=i->next;
        else cur->next=j, j=j->next;
        cur=cur->next;
    }
    while(i) cur->next=i, i=i->next, cur=cur->next;
    while(j) cur->next=j, j=j->next, cur=cur->next;
    return head->next;
}

ListNode* merge_sort(ListNode* head) {
    if(head&&head->next==NULL) return head;
    ListNode* i=head, *j=head, *last;
    while(j&&j->next){
        last = i;
        i=i->next, j=j->next->next;
    }
    last->next=NULL;
    head = merge_sort(head);
    i = merge_sort(i);
    return merge(head, i);
}

ListNode* sortList(ListNode* head) {
    if(!head) return head;
    return merge_sort(head);
}

int main() {

    return 0;
}
