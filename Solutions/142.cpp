#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode *i=head, *j=head;
    while(i&&j&&j->next){
        j=j->next->next, i=i->next;
        if(i==j) break;
    }
    if(!j||!j->next) return NULL;
    j = head;
    while(i!=j) i=i->next, j=j->next;
    return i;
}
