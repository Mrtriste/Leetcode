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

ListNode* reverse(ListNode* head){
    ListNode* last = NULL, *t;
    while(head){
        t = head->next;
        head->next = last;
        last = head;
        head = t;
    }
    return last;
}

bool isPalindrome(ListNode* head) {
    if(!head||!head->next) return true;
    ListNode* i=head, *j = head;
    while(j&&j->next) i=i->next, j=j->next->next;
    if(j) i = i->next;
    ListNode* p=head, *q=reverse(i);
    while(q){
        if(p->val!=q->val) return false;
        p = p->next, q=q->next;
    }
    return true;
}
