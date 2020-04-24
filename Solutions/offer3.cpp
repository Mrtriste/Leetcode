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

int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<nums.size();++i){
        int x = nums[i]%n;
        nums[x] += n;
    }

    for(int i=0;i<nums.size();++i)
        if(nums[i]/n>1)
            return i;
    return 0;
}
