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

TreeNode* DFS(TreeNode* root){
    if(!root) return NULL;
    root->left = DFS(root->left);
    root->right = DFS(root->right);
    if(!root->left&&!root->right&&!root->val) return NULL;
    return root;
}

TreeNode* pruneTree(TreeNode* root) {
    return DFS(root);
}
