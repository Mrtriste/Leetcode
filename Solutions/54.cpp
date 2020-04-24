#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m==0) return {};
    int n=matrix[0].size();
    vector<int> res = {};
    int i=0,j=0,imin=0,jmin=0,imax=m-1,  jmax=n-1, cnt=0;
    while(cnt<m*n){
        while(j<=jmax) res.push_back(matrix[i][j++]), cnt+=1;
        imin++, j--, i=imin;
        if(cnt>=m*n) break;
        while(i<=imax) res.push_back(matrix[i++][j]), cnt+=1;
        jmax--, i--, j=jmax;
        if(cnt>=m*n) break;
        while(j>=jmin) res.push_back(matrix[i][j--]), cnt+=1;
        imax--, j++, i=imax;
        if(cnt>=m*n) break;
        while(i>=imin) res.push_back(matrix[i--][j]), cnt+=1;
        jmin++, i++, j=jmin;
        if(cnt>=m*n) break;
    }
    return res;
}
