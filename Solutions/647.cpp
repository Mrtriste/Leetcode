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

int countSubstrings(string s) {
    int n=s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    int res=n;
    for(int i=0;i<n;++i) dp[i][i]=1;
    for(int k=2;k<=n;++k){
        for(int i=0;i+k-1<n;++i){
            int j=i+k-1;
            if(s[i]==s[j]&&(i+1==j||dp[i+1][j-1])){
                dp[i][j] = 1;
                res += 1;
            }
        }
    }
    return res;
}

int main() {

    return 0;
}
