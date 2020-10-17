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

void deleteNode(ListNode* node) {
    node->val=node->next->val;
    node->next = node->next->next;
}

int main() {

    return 0;
}
