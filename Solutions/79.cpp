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

int vis[210][210];
int dir[4][2] = {{1,0},{-1, 0}, {0,1},{0,-1}};

bool DFS(vector<vector<char>>& board, string &word, int x, int y, int k){
    if(k==word.size()) return true;
    int m=board.size(), n=board[0].size();
    for(int i=0;i<4;++i){
        int xx=i+dir[i][0], yy=j+dir[i][1];
        if(xx<0||xx>=m||yy<0||yy>=n||vis[xx][yy]) continue;
        if(board[xx][yy]==word[k]){
            vis[xx][yy]=1;
            if(DFS(board, word, xx, yy, k+1)) return true;
            vis[xx][yy]=0;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m=board.size(), n=board[0].size();
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(board[i][j]==word[0]){
                vis[i][j]=1;
                if(DFS(board, word, i, j, 1)) return true;
                vis[i][j]=0;
            }
        }
    }
    return false;
}

int main() {

    return 0;
}
