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

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<vector<int>>> res(target+10);
    res[0] = {{}};
    for(int i=0;i<candidates.size();++i){
        int t=candidates[i];
        for(int j=t;j<=target;++j){
            for(int k=0;k<res[j-t].size();++k){
                vector<int> tmp=res[j-t][k];
                tmp.push_back(t);
                res[j].push_back(tmp);
            }
        }
    }
    return res[target];
}

int main() {

    return 0;
}
