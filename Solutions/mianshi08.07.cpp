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
vector<bool> vis;

void DFS(string &s){
    if(path.length()==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();++i){
        if(vis[i]) continue;
        path+=s[i];
        vis[i]=1;
        DFS(s);
        vis[i] = 0;
        path.pop_back();
    }
}

vector<string> permutation(string S) {
    int n = S.size();
    vis = vector<bool>(n, 0);
    DFS(S);
    return res;
}
