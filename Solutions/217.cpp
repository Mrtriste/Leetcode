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

bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(auto t: nums){
        if(s.find(t)!=s.end()) return true;
        s.insert(t);
    }
    return false;
}

int main() {

    return 0;
}
