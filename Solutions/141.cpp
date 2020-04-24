#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool hasCycle(ListNode *head) {
    ListNode *i=head, *j = head;
    while(i&&j&&j->next){
        i=i->next, j=j->next->next;
        if(i==j) return true;
    }
    return false;
}
