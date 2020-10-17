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

int translateNum(int num) {
    string s=to_string(num);
    int n=s.size();
    vector<int> dp(n, 0);
    if(n==1) return 1;
    dp[0] = 1;
    if(s[0]=='0') dp[1]=1;
    else if(atoi(s.substr(0, 2).c_str())<26) dp[1]=2;
    else dp[1]=1;
    for(int i=2;i<n;++i){
        if(s[i-1]=='0') dp[i]=dp[i-1];
        else if(atoi(s.substr(i-1, 2))<26) dp[i]=dp[i-2]+dp[i-1];
        else dp[i]=dp[i-1];
    }
    return dp[n-1];
}

int main() {

    return 0;
}
