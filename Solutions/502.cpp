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

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    vector<pair<int, int>> a;
    for(int i=0;i<Profits.size();++i)
        a.push_back({Capital[i], Profits[i]});
    sort(a.begin(), a.end());

    priority_queue<int> q;
    int res = W, i=0;
    while(k--){
        for(;i<a.size() && a[i].first<=W;++i) q.push(a[i].second);
        if(q.empty()) return res;
        int t = q.top(); q.pop();
        W += t;
        res += t;
    }
    return res;
}