#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size(), n=obstacleGrid[0].size();
    long long dp[101][101] = {0};
    dp[0][1] = 1;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(obstacleGrid[i-1][j-1]==1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
    return dp[m][n];
}
