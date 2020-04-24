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
    if(!root->left) return root->right;
    root->left = DFS(root->left);
    return root;
}

TreeNode* delete_min_node(TreeNode* root){
    return DFS(root);
}

