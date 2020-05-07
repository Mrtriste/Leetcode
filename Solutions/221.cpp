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

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    int m =matrix.size(), n=matrix[0].size();
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            dp[i][j] = matrix[i][j]-'0';
            if(i&&j&&matrix[i][j]=='1')
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
            ans = max(ans, dp[i][j]*dp[i][j]);
        }
    }
    return ans;
}