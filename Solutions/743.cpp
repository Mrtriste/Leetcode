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

struct Node{
    int u, d;
    Node(int u, int d):u(u), d(d){}
};

struct cmp{
    bool operator()(Node &a, Node &b){
        return a.d>b.d;
    }
};

vector<int> dijkstra(vector<vector<Node>>& graph, int n, int k){
    vector<int> dis(n, 0x3f3f3f3f);
    vector<bool> vis(n, 0);
    priority_queue<Node, vector<Node>, cmp> q;
    q.push(Node(k-1, 0));
    while(!q.empty()){
        Node cur = q.top(); q.pop();
        int u = cur.u, d = cur.d;
        if(vis[u]) continue;
        vis[u] = 1;
        dis[u] = d;
        for(int i=0;i<graph[u].size();++i){
            int v = graph[u][i].u, w = graph[u][i].d;
            if(vis[v]) continue;
            q.push(Node(v, d+w));
        }
    }
    return dis;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<Node>> graph(N, vector<Node>());
    for(int i=0;i<times.size();++i){
        vector<int> l = times[i];
        graph[l[0]-1].push_back(Node(l[1]-1, l[2]));
        graph[l[0]-1].push_back(Node(l[1]-1, l[2]));
    }
    vector<int> dis = dijkstra(graph, N, K);
    int mmax = 0;
    for(int i=0;i<N;++i) mmax = max(dis[i], mmax);
    return mmax>=0x3f3f3f3f?-1:mmax;
}
