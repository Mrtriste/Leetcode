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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *i=head, *j=head, *last=NULL;
    while(n--) i=i->next;
    while(i) last=j, i=i->next, j=j->next;
    if(!last) return j->next;
    last->next = j->next;
    return head;
}