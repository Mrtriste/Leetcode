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

int longestValidParentheses(string s) {
    int n = s.length();
    vector<int> dp(n, 0);
    int res = 0;
    for(int i=1;i<n;++i){
        if(s[i]==')'){
            int t = i-1-dp[i-1];
            if(t>=0 && s[t]=='('){
                dp[i] = dp[i-1]+2+(t-1>=0?dp[t-1]:0);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}