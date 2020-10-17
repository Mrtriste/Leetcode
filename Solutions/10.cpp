#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <functional>

using namespace std;

bool isMatch(string s, string p) {
    s = " "+s, p=" "+p;
    int m=s.size(), n=p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
    dp[0][0] = 1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1]||p[j-1]=='.')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1]=='*'){
                if(p[j-2]==s[i-1]||p[j-2]=='.')
                    dp[i][j] = dp[i][j-2]||dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-2];
            }
        }
    }
    return dp[m][n];
}

int main() {

    return 0;
}
