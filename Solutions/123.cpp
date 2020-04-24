#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    // dp[i]:第i天卖最大获得多少利润，单调增
    vector<int> dp(n);
    int mmin = 0x3f3f3f3f, max_diff = 0;
    for (int i = 0; i < n; ++i) {
        mmin = min(mmin, prices[i]);
        max_diff = max(max_diff, prices[i] - mmin);
        dp[i] = max_diff;
    }

    // dp1[i]:第i天买最大获得多少利润，单调减
    // vector<int> dp1(n);
    int mmax = 0;
    max_diff = 0;
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        mmax = max(mmax, prices[i]);
        max_diff = max(max_diff, mmax-prices[i]);
        // dp1[i] = max_diff;
        res = max(res, max_diff+dp[i]);
    }

    return res;
}
