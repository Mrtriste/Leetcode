#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0x3f3f3f3f));
    dp[0][1] = dp[1][0] = 0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i-1][j-1];
    return dp[m][n];
}
