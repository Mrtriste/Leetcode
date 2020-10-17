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

int numSquares(int n) {
    vector<int> dp(n+1, 0x3f3f3f3f);
    dp[0] = 0;
    for(int j=1;j*j<=n;++j){
        for(int i=j*j;i<=n;++i){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}

int main() {

    return 0;
}
