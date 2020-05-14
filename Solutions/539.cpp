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

int to_int(string s){
    return ((s[0]-'0')*10 + (s[1]-'0'))*60 + (s[3]-'0')*10 + s[4]-'0';
}

int findMinDifference(vector<string>& timePoints) {
    vector<int> vis(1440*2, 0);
    for(int i=0;i<timePoints.size();++i){
        int stamp = to_int(timePoints[i]);
        vis[stamp] += 1;
        vis[stamp+1440] = vis[stamp];
    }
    int mmin = 0x3f3f3f3f, last = -100000;
    for(int i=0;i<1440*2;++i){
        if(vis[i]>=2) return 0;
        if(vis[i]) mmin = min(mmin, i-last), last = i;
    }
    return mmin;
}