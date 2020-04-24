#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(auto v:nums) sum+=v;
    if(sum&1) return false;
    sum >>= 1;

    vector<bool> dp(sum+1, false);
    dp[0] = 1;
    for(auto v: nums)
        for(int i=sum;i>=1;--i)
            if(i-v>=0 && dp[i-v]) dp[i] = 1;
            // if(i-v>=0) dp[i] = dp[i-v]; 这样是错的 应该是 dp[i] = dp[i-v]||dp[i]
    return dp[sum];
}
