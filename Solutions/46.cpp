#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void DFS(vector<int> &nums, int depth){
    if(depth==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=depth;i<nums.size();++i){
        swap(nums[depth], nums[i]);
        path.push_back(nums[depth]);
        DFS(nums, depth+1);
        path.pop_back();
        swap(nums[depth], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    DFS(nums, 0);
    return res;
}
