#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int vis[60][60];
int m,n,cnt, max_area=0;
int dir[4][2] = {{0,1}, {0,-1},{-1, 0}, {1,0}};

void DFS(int x, int y, vector<vector<int>> &grid){
    if(vis[x][y]) return;
    vis[x][y] = 1, cnt+=1;
    for(int i=0;i<4;++i){
        int xx = x+dir[i][0], yy=y+dir[i][1];
        if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy])
            DFS(xx, yy, grid);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    memset(vis, 0, sizeof(vis));
    m=grid.size(), n=grid[0].size();
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j){
            if(grid[i][j] && !vis[i][j]){
                cnt = 0;
                DFS(i, j, grid);
                max_area = max(max_area, cnt);
            }
        }
    return max_area;
}
