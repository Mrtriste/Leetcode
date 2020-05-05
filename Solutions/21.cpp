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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1||!l2) return l1?l1:l2;
    ListNode* head=new ListNode();
    ListNode* cur=head;
    while(l1&&l2){
        if(l1->val>l2->val) cur->next=l2, l2=l2->next, cur=cur->next;
        else cur->next = l1, l1=l1->next, cur=cur->next;
    }
    if(l1) cur->next=l1;
    if(l2) cur->next=l2;
    return head->next;
}