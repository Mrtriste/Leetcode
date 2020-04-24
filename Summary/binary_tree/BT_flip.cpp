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

//226. 翻转二叉树
TreeNode* DFS(TreeNode* root){
    if(!root) return NULL;
    TreeNode* tmp = DFS(root->left);
    root->left = DFS(root->right);
    root->right = tmp;
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    return DFS(root);
}

