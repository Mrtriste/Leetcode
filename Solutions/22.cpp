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

vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n+1);
    dp[0] = {""};
    for(int i=1;i<=n;++i){
        // (k) i-1-k
        for(int k=0;k<=i-1;++k){
            for(auto lefts: dp[k]){
                for(auto rights:dp[i-1-k]){
                    string s = "(" + lefts+")"+rights;
                    dp[i].push_back(s);
                }
            }
        }
    }
    return dp[n];
}