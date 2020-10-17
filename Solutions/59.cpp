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

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int num=1;
    int l=0, t=0, r=n-1, d=n-1;
    while(num<=n*n){
        for(int i=l;i<=r;++i) res[t][i]=num++;
        t++;
        for(int i=t;i<=d;++i) res[i][r]=num++;
        r--;
        for(int i=r;i>=l;--i) res[d][i]=num++;
        d--;
        for(int i=d;i>=t;--i) res[i][l]=num++;
        l++;
    }
    return res;
}

int main() {

    return 0;
}
