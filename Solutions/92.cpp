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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    int k=n-m;
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* cur=head, *last=dummy;
    while(--m) last=cur, cur=cur->next;
    ListNode* next=cur->next, *after=cur;
    while(k--){
        ListNode* tmp=next->next;
        next->next=cur;
        cur=next, next = tmp;
    }
    last->next = cur;
    after->next = next;
    return dummy->next;
}

int main() {

    return 0;
}
