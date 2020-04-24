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

bool canJump(vector<int>& nums) {
    if(nums.size()==1) return true;
    int t = nums.size()-1;
    for(int i=nums.size()-2;i>=0;--i){
        if(nums[i]+i>=t) t=i;
    }
    return t==0;
}

