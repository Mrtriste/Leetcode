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

int dir[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};

void DFS(vector<vector<char>>& grid, int x, int y){
    grid[x][y] = '0';
    for(int i=0;i<4;++i){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        int m = grid.size(), n=grid[0].size();
        if(xx<0||yy<0||xx>=m||yy>=n||grid[xx][yy]=='0') continue;
        DFS(grid, xx, yy);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    for(int i=0;i<grid.size();++i)
        for(int j=0;j<grid[0].size();++j){
            if(grid[i][j]=='1'){
                num += 1;
                DFS(grid, i, j);
            }
        }
    return num;
}
