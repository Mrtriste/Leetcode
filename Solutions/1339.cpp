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

long long sum = 0;
long long mmax = INT_MIN;

void DFS1(TreeNode* root){
    if(!root) return;
    sum += root->val;
    DFS1(root->left);
    DFS1(root->right);
}

long long DFS2(TreeNode* root){
    if(!root) return 0;
    long long l = DFS2(root->left);
    long long r = DFS2(root->right);
    long long t = l+r+root->val;
    mmax = max(mmax, (sum-t)*t);
    return t;

}

int maxProduct(TreeNode* root) {
    DFS1(root);
    DFS2(root);
    return mmax%int(1e9+7);
}
