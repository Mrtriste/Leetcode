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

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> set;
    for(int i=0;i<wordDict.size();++i) set.insert(wordDict[i]);

    int n=s.size();
    vector<bool> dp(n+1, 0);
    dp[0] = 1;
    for(int i=0;i<n;++i){
        if(!dp[i]) continue;
        for(int j=i;j<n;++j){
            string t = s.substr(i, j-i+1);
            if(set.find(t)!=set.end()) dp[j+1]=1;
        }
    }
    return dp[n];
}

int main() {

    return 0;
}
