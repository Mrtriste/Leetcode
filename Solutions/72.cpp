#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m=word1.length(), n=word2.length();
    // 注意申请时 m,n都要+1，因为还要比较空字符与字符串
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int j=0;j<=n;j++)
        dp[0][j] = j;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;++j)
            if(word1[i-1]==word2[j-1])// 这里dp[i][j]比较的是第i个和第j个字符，因为比较空字符占了1个位置
                dp[i][j] = dp[i-1][j-1];
            else{
                int t = min(dp[i-1][j], dp[i][j-1]);  //
                dp[i][j] = min(t, dp[i-1][j-1]) + 1;
            }
    return dp[m][n];
}
