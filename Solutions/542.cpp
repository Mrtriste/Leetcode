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

int dir[4][2] = {{1,0},{-1,0}, {0,-1}, {0,1}};

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> vis = vector(m, vector<bool>(n, 0));
    // vector<vector<int>> res = vector(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(matrix[i][j]==0) q.push({i, j});
    int dis = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;++i){
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y=p.second;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            matrix[x][y] = dis;
            for(int j=0;j<4;++j){
                int xx = x+dir[j][0], yy = y+dir[j][1];
                if(xx>=0&&xx<m&&yy>=0&&yy<n)
                    q.push({xx, yy});
            }

        }
        dis++;
    }
    return matrix;
}
