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

//494. 目标和
int findTargetSumWays(vector<int>& nums, int S) {
    int n =nums.size();
    vector<vector<int>> dp(n, vector<int>(2010, 0));
    dp[0][nums[0]+1000] = 1;
    dp[0][-nums[0]+1000] += 1;
    for(int i=1;i<n;++i){
        int a = nums[i];
        for(int t=-1000;t<=1000;++t){
            if(t-a+1000>=0) dp[i][t+1000] += dp[i-1][t-a+1000];
            if(t+a+1000<2010) dp[i][t+1000]+= dp[i-1][t+a+1000];
        }
    }
    return abs(S)>1000?0:dp[n-1][S+1000];
}
