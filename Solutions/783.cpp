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

int last = -1000, mmin=0x3f3f3f3f;

void DFS(TreeNode* root){
    if(!root) return;
    DFS(root->left);
    mmin = min(mmin, root->val-last);
    last = root->val;
    DFS(root->right);
}

int minDiffInBST(TreeNode* root) {
    DFS(root);
    return mmin;
}
