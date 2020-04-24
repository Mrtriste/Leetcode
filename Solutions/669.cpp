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

TreeNode* DFS(TreeNode* root, int L, int R){
    if(!root) return NULL;
    if(root->val<L) return DFS(root->right, L, R);
    if(root->val>R) return DFS(root->left, L, R);
    root->left = DFS(root->left, L, R);
    root->right = DFS(root->right, L, R);
    return root;
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
    return DFS(root, L, R);
}
