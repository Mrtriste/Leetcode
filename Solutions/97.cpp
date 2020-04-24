#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m=s1.size(), n=s2.size();
    if(m+n!=s3.size()) return false;
    vector<vector<bool>> dp(m+1);
    for(int i=0;i<=m;++i) dp[i]=vector<bool> (n+1, 0);
    dp[0][0] = 1;
    for(int i=1;i<=m;++i)
        if(s1[i-1]==s3[i-1] && dp[i-1][0]==1) dp[i][0] = 1;
    for(int i=1;i<=n;++i)
        if(s2[i-1]==s3[i-1] && dp[0][i-1]==1) dp[0][i] = 1;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j){
            int k = i+j-1;
            if(dp[i-1][j]==1 && s1[i-1]==s3[k]) dp[i][j] = 1;
            if(dp[i][j-1]==1 && s2[j-1]==s3[k]) dp[i][j] = 1;
        }
    return dp[m][n];
}
