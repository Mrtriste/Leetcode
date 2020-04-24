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

vector<int> par;

int find(int a){
    int root = a;
    while(par[root]!=root) root = par[root];
    while(a!=root){
        int t = par[a];
        par[a] = root;
        a = t;
    }
    return root;
}

void Union(int a, int b){
    int x = find(a), y = find(b);
    if(x!=y) par[x] = y;
}

int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    par = vector<int>(n, 0);
    for(int i=0;i<n;++i) par[i] = i;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(M[i][j]) Union(i, j);
    int cnt = 0;
    for(int i=0;i<n;++i)
        if(par[i]==i) cnt++;
    return cnt;
}
