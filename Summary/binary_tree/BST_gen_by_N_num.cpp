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

//96. 不同的二叉搜索树
// Cn = C_0*C_n-1 +C_1*C_n-2+...+C_n-1*C_0
int numTrees(int n) {
    vector<long long> dp(n+10, 0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;++i)
        for(int j=0;j<i;++j)
            dp[i] += dp[j]*dp[i-1-j];
    return dp[n];
}

//C(0) = 1; C(n+1) = C(n)*[2(2n+1)/n+2]
int numTrees(int n) {
    long long C=1;
    for(int i=0;i<n;++i)
        C = C*2*(2*i+1)/(i+2);  //C放前面，(2*i+1)/(i+2)是小数
    return C;
}

int main() {

    return 0;
}

