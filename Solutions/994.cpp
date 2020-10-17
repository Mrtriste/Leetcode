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
    Node(int i, int j):i(i),j(j){}
    int i,j;
};

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    if(m==0) return 0;
    int n=grid[0].size();
    queue<Node> q;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]==2) q.push(Node(i, j));
        }
    }
    int res=-1;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node t=q.front(); q.pop();
            int x=t.i, y=t.j;
            for(int i=0;i<4;++i){
                int xx=x+dir[i][0], yy=y+dir[i][1];
                if(xx<0||xx>=m||yy<0||yy>=n||grid[xx][yy]!=1) continue;
                grid[xx][yy] = 2;
                q.push(Node(xx, yy));
            }
        }
        res++;
    }
    res = max(res, 0);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]==1) return -1;
        }
    }
    return res;
}

int main() {

    return 0;
}
