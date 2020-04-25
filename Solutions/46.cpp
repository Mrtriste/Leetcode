#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void DFS(vector<int>& nums, vector<bool>& vis){
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();++i){
        if(vis[i]) continue;
        vis[i] = 1;
        path.push_back(nums[i]);
        DFS(nums, vis);
        path.pop_back();
        vis[i] = 0;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<bool> vis(n, 0);
    DFS(nums, vis);
    return res;
}


//vector<vector<int>> res;
//vector<int> path;
//
//void DFS(vector<int> &nums, int depth){
//    if(depth==nums.size()){
//        res.push_back(path);
//        return;
//    }
//    for(int i=depth;i<nums.size();++i){
//        swap(nums[depth], nums[i]);
//        path.push_back(nums[depth]);
//        DFS(nums, depth+1);
//        path.pop_back();
//        swap(nums[depth], nums[i]);
//    }
//}
//vector<vector<int>> permute(vector<int>& nums) {
//    DFS(nums, 0);
//    return res;
//}
