#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *i=headA, *j=headB;
    while(i!=j){
        i = (i?i->next:headB);
        j = (j?j->next:headA);
    }
    return i;
}
