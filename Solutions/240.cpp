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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    if(m==0) return false;
    int n=matrix[0].size();
    int i=0, j=n-1;
    while(i<m&&j>=0){
        if(matrix[i][j]==target) return true;
        if(matrix[i][j]>target) j--;
        else i++;
    }
    return false;
}

int main() {

    return 0;
}
