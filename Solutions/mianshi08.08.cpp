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

vector<string> res;
string path = "";

void DFS(string &s, vector<bool> &vis){
    if(path.length()==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();++i){
        if(vis[i]) continue;
        if(i>0 && s[i]==s[i-1] && vis[i-1]) continue;
        vis[i] = 1;
        path+=s[i];
        DFS(s, vis);
        path.pop_back();
        vis[i] = 0;
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    vector<bool> vis(n, 0);
    sort(S.begin(), S.end());
    DFS(S, vis);
    return res;
}
