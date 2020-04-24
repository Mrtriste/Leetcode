#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if(n==1) return triangle[0][0];
    // vector<int> dp(n, 0);
    // for(int j=0;j<n;++j) dp[j] = triangle[n-1][j];
    // vector<int> dp = triangle[n-1];
    for(int i=n-2;i>=0;--i)
        for(int j=0;j<=i;++j)
            triangle[n-1][j] = min(triangle[n-1][j], triangle[n-1][j+1]) + triangle[i][j];
    return triangle[n-1][0];
}
