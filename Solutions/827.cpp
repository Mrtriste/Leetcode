#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

int vis[51][51], dp[51][51], bianhao[51][51];
int m,n,cnt;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


void DFS(int x, int y, vector<vector<int>>& grid){
    if(x<0||y<0||x>=m||y>=n||vis[x][y]||!grid[x][y]) return;
    vis[x][y] = 1;
    cnt+=1;
    for(int i=0;i<4;++i)DFS(x+dir[i][0], y+dir[i][1], grid);
}

int largestIsland(vector<vector<int>>& grid) {
    m=grid.size(), n=grid[0].size();
    memset(dp, 0, sizeof(dp));
    memset(bianhao, -1, sizeof(dp));
    int liantong_idx = 0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j] && !dp[i][j]){
                cnt = 0;
                memset(vis, 0, sizeof(vis));
                DFS(i, j, grid);
                for(int ii=0;ii<m;++ii)
                    for(int jj=0;jj<n;++jj)
                        if(vis[ii][jj]) dp[ii][jj] = cnt, bianhao[ii][jj] = liantong_idx;
                liantong_idx++;
            }
        }
    }

    int ans=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            // cout<<bianhao[i][j]<<" ";
            if(grid[i][j]) continue;
            int sum=1;
            set<int> s;
            for(int k=0;k<4;++k){
                int xx=i+dir[k][0], yy=j+dir[k][1];
                if(xx>=0 && xx<m && yy>=0 && yy<n && s.find(bianhao[xx][yy])==s.end())
                    sum+=dp[xx][yy],s.insert(bianhao[xx][yy]);

            }
            ans = max(sum, ans);
        }
        // cout<<endl;
    }
    return ans==0?m*n:ans;
}

