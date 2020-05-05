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

int mincostTickets(vector<int>& days, vector<int>& costs) {
    set<int> s(days.begin(), days.end());
    vector<int> dp(366, 0x3f3f3f3f);
    vector<int> a={1, 7, 30};
    dp[0] = 0;

    for(int j=1;j<=365;++j){
        for(int i=0;i<3;++i){
            if(s.find(j)!=s.end())
                dp[j] = min(dp[j], dp[max(0, j-a[i])]+costs[i]);
            else
                dp[j] = dp[j-1];
        }
    }
    return dp[365];
}