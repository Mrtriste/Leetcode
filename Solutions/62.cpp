#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n) {
    int dp[101][101];
    for(int i=0;i<101;++i)
        dp[0][i] = dp[i][0] = 1;
    for(int i=1;i<m;++i)
        for(int j=1;j<n;++j)
            dp[i][j] = dp[i][j-1]+dp[i-1][j];
    return dp[m-1][n-1];
}

