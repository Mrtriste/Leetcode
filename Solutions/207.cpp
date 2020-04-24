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

bool topu(vector<vector<int>> &G, vector<int> &degree){
    int n = G.size();
    queue<int> q;
    for(int i=0;i<n;++i) if(degree[i]==0) q.push(i);

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<G[u].size();++i){
            int v = G[u][i];
            degree[v]--;
            if(degree[v]==0) q.push(v);
        }
    }

    for(int i=0;i<n;++i) if(degree[i]>0) return 0;
    return 1;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> G(numCourses);
    vector<int> degree(numCourses, 0);
    for(int i=0;i<prerequisites.size();++i){
        int u = prerequisites[i][0], v=prerequisites[i][1];
        G[v].push_back(u);
        degree[u]++;
    }
    return topu(G, degree);
}
