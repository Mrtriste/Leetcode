#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

ListNode* middleNode(ListNode* head) {
    ListNode* i=head, *j=head;
    while(i&&j&&j->next)
        i=i->next, j=j->next->next;
    return i;
}
