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

int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size(), n=B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j){
            if(A[i]==B[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = 0;
            ans = max(ans, dp[i+1][j+1]);
        }
    return ans;
}

int main() {

    return 0;
}
