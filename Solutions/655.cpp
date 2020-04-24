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

int get_height(TreeNode*root){
    if(!root) return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}

void DFS(TreeNode* root, vector<vector<string>>&m, int l, int r, int row){
    if(l>r) return;
    if(!root) return;
    int mid = l+((r-l)>>1);
    m[row][mid] = to_string(root->val);
    DFS(root->left, m, l, mid-1, row+1);
    DFS(root->right, m, mid+1, r, row+1);
}

vector<vector<string>> printTree(TreeNode* root) {
    int h = get_height(root);
    int w = (int)pow(2, h) - 1;
    vector<vector<string>> m(h, vector<string>(w, ""));
    DFS(root, m, 0, w-1, 0);
    return m;
}
