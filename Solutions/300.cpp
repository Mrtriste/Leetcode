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

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int *dp = new int[n];
    int len = 0;
    dp[len++] = nums[0];
    for(int i=1;i<n;++i){
        if(nums[i]>dp[len-1]) dp[len++] = nums[i];
        else{
            int pos = lower_bound(dp, dp+len, nums[i])-dp;
            dp[pos] = nums[i];
        }
    }
    return len;
}
