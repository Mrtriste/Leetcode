#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(amount<=0) return 0;
    vector<int> dp(amount+1,0x3f3f3f3f);
    dp[0] = 0;
    for(int j=0;j<coins.size();++j)
        for(int i=1;i<=amount;++i)
            if(i-coins[j]>=0)
                dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
    return dp[amount]>=0x3f3f3f?-1:dp[amount];
}
