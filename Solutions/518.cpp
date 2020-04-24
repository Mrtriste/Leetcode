#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int change(int amount, vector<int>& coins) {
    if(amount<=0) return 1;
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(int j=0;j<coins.size();++j)
        for(int i=1;i<=amount;++i)
            if(i-coins[j]>=0) dp[i] += dp[i-coins[j]];
    return dp[amount];
}
