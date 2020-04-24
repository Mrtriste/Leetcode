#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numDistinct(string s, string t) {
    int m=s.size(), n=t.size();
    if(n==0) return 0;
    if(m<n) return 0;
    vector<vector<long>> dp(m);
    for(int i=0;i<m;++i) dp[i] = vector<long>(n, 0);
    int cnt=0;
    for(int i=0;i<m;++i){
        if(s[i]==t[0]) cnt++;
        dp[i][0] = cnt;
    }
    for(int i=0;i<n;++i)
        if(s.substr(0, i+1)==t.substr(0, i+1)) dp[i][i]=1;
    for(int i=1;i<m;++i)
        for(int j=1;j<min(i, n);++j){
            if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    return dp[m-1][n-1];
}
