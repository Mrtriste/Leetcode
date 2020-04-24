#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long last = LONG_LONG_MIN;

bool DFS(TreeNode* root){
    if(!root) return true;
    if(!DFS(root->left)) return false;
    if(root->val<=last) return false;
    last = root->val;
    return DFS(root->right);
}

bool isValidBST(TreeNode* root) {
    return DFS(root);
}

//bool DFS(TreeNode* root, long long l, long long r){
//    if(!root) return true;
//    if(root->val>=r || root->val<=l) return false;
//    return DFS(root->left, l, root->val) && DFS(root->right, root->val, r);
//}
//
//bool isValidBST(TreeNode* root) {
//    return DFS(root, LONG_LONG_MIN, LONG_LONG_MAX);
//}
