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

int missingNumber(vector<int>& nums) {
    int res = 0;
    for(int i=0;i<=nums.size();++i) res^=i;
    for(int i=0;i<nums.size();++i) res^=nums[i];
    return res;
}
