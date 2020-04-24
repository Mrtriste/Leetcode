#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int res = INT_MIN;
int DFS(TreeNode* root){
    if(root==NULL) return 0;
    int left = DFS(root->left), right = DFS(root->right);
    int heng = root->val + max(0, left) + max(0, right);
    int val = root->val + max(0, max(left, right));
    res = max(res, heng);
    return val;
}

int maxPathSum(TreeNode* root) {
    DFS(root);
    return res;
}
