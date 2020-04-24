#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool DFS(TreeNode* l, TreeNode* r){
    if(!l&&!r) return true;
    if(!l||!r) return false;
    return (l->val==r->val) && DFS(l->left, r->right) && DFS(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return DFS(root->left, root->right);
}
