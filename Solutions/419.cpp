#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

int cnt = 0;
int m,n;
vector<vector<int>> vis;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};

void DFS(int x, int y, vector<vector<char>> &board){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    for(int i=0;i<4;++i){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&board[xx][yy]=='X')
            DFS(xx, yy, board);
    }
}

int countBattleships(vector<vector<char>>& board) {
    m=board.size(), n=board[0].size();
    vis.resize(m);
    for(int i=0;i<m;++i) vis[i] = vector<int>(n, 0);
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j){
            if(board[i][j]=='X' && !vis[i][j]){
                cnt += 1;
                DFS(i,j, board);
            }
        }
    return cnt;
}
