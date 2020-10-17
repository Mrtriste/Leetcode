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

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    for(int i=0;i<1<<nums.size();++i){
        vector<int> path;
        for(int j=0;j<nums.size();++j){
            if(i&1<<j) path.push_back(nums[j]);
        }
        res.push_back(path);
    }
    return res;
}

int main() {

    return 0;
}
