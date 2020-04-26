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

int jump(vector<int>& nums) {
    int n = nums.size();
    int end=0, mmax=0, cnt=0;
    for(int i=0;i<n-1;++i){
        mmax = max(mmax, i+nums[i]);
        if(end==i){
            end=mmax;
            cnt+=1;
        }
    }
    return cnt;
}