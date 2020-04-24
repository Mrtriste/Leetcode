#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

vector<vector<int>> res;
int s = 0;

void DFS(TreeNode* root, vector<int> &path, int sum){
    s += root->val;
    path.push_back(root->val);

    if(!root->left&&!root->right){
        if(sum==s) res.push_back(path);
    }

    if(root->left) DFS(root->left, path, sum);
    if(root->right) DFS(root->right, path, sum);

    path.pop_back();
    s -= root->val;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(!root) return {};
    vector<int> p;
    DFS(root, p, sum);
    return res;
}
