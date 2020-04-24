#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

vector<vector<int>> res;
vector<vector<int>> path = {{0,0}};
int dir[2][2] = {{0, 1}, {1, 0}};
int flag = 0, m, n;

void DFS(vector<vector<int>>& obstacleGrid, int x, int y){
    if(flag) return;
    if(x==m && y==n){
        flag = 1, res = path;
        return;
    }
    obstacleGrid[x][y] = 1;
    for(int i=0;i<2;++i){
        int xx = x+dir[i][0], yy = y+dir[i][1];
        if(xx>m || yy>n || obstacleGrid[xx][yy]) continue;
        path.push_back({xx, yy});
        DFS(obstacleGrid, xx, yy);
        path.pop_back();
    }
}

vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    m = obstacleGrid.size()-1, n = obstacleGrid[0].size()-1;
    if(obstacleGrid[0][0] || obstacleGrid[m][n]) return {};
    DFS(obstacleGrid, 0, 0);
    return res;
}