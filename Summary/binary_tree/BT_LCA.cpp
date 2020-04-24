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

// 最近公共祖先
TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return NULL;
    if(root->val==p->val || root->val==q->val) return root;
    TreeNode* left = DFS(root->left, p, q), *right = DFS(root->right, p, q);
    if(left&&right) return root;
    if(!left&&!right) return NULL;
    return left?left:right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return DFS(root, p, q);
}

