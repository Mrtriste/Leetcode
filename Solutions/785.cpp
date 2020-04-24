#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int a[110], n;

bool DFS(int node, int color, vector<vector<int>> &graph){
    if(a[node]!=-1) return a[node]==color;
    a[node] = color;
    for(auto neigh: graph[node])
        if(!DFS(neigh, 1-color, graph)) return false;
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    n = graph.size();
    for(int i=0;i<n;++i){
        memset(a, -1, sizeof(a));
        if(!DFS(i, 0, graph)) return false;
    }
    return true;
}