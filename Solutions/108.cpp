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

TreeNode* DFS(vector<int> &nums, int l, int r){
    if(l>r) return NULL;
    int mid = l+((r-l)>>1);
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = DFS(nums, l, mid-1);
    root->right = DFS(nums, mid+1, r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return DFS(nums, 0, nums.size()-1);
}

