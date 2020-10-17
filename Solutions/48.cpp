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

void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n/2;++i){
        for(int j=0;j<(n+1)/2;++j){
            int t=matrix[j][n-1-i];
            matrix[j][n-1-i] = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = t;
        }
    }
}

int main() {

    return 0;
}
