#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int max_depth = 0;

void DFS(TreeNode* root, int depth){
    if(root==NULL) return;
    max_depth = max(max_depth, depth);
    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

int maxDepth(TreeNode* root) {
    DFS(root, 1);
    return max_depth;
}
