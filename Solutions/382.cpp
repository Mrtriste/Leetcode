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

int getRandom() {
    int cnt = 1, x;
    ListNode* p = head;
    while(p){
        int r = rand()%cnt;
        if(r==0) x=p->val;
        p = p->next, cnt++;
    }
    return x;
}
