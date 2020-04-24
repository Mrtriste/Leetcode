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

deque<int> q;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    for(int i=0;i<k-1;++i){
        while(!q.empty()&&nums[q.back()]<nums[i]) q.pop_back();
        q.push_back(i);
    }
    for(int i=k-1;i<nums.size();++i){
        while(!q.empty() && i-q.front()>=k) q.pop_front();
        while(!q.empty()&& nums[q.back()]<nums[i]) q.pop_back();
        q.push_back(i);
        res.push_back(nums[q.front()]);
    }
    return res;
}
