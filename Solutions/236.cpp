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

TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return NULL;
    if(root==p||root==q) return root;
    TreeNode *left = DFS(root->left, p, q), *right = DFS(root->right, p, q);
    if(!left&&!right) return NULL;
    if(left&&right) return root;
    return left?left:right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return DFS(root, p, q);
}