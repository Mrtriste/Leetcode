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

ListNode* reverse(ListNode* head, ListNode* tail){  //tail
    ListNode* last = NULL;
    while(head!=tail){
        ListNode* tmp = head->next;
        head->next = last;
        last = head;
        head = tmp;
    }
    return last;
}

ListNode* DFS(ListNode* head, int k){
    ListNode* i=head, *j=head;
    for(int p=0;p<k;++p){
        if(!j) return head;
        j = j->next;
    }
    ListNode* new_head = reverse(i, j);
    i->next = DFS(j, k);
    return new_head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head) return head;
    return DFS(head, k);
}
