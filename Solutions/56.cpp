#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

bool cmp(vector<int> &a, vector<int> &b){
    return a[0]!=b[0]?a[0]<b[0]:a[1]<b[1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()==0) return {};
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    int l=intervals[0][0], r = intervals[0][1];
    for(int i=1;i<intervals.size();++i){
        int ll = intervals[i][0], rr = intervals[i][1];
        if(ll<=r) r = max(r, rr);
        else{
            res.push_back({l, r});
            l = ll, r = rr;
        }
    }
    res.push_back({l, r});
    return res;
}
