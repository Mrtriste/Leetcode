#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

TreeNode* DFS(vector<int> &pre, vector<int> &in, int l1, int r1, int l2, int r2 ){
    if(l1>r1) return NULL;
    if(l1==r1) return new TreeNode(pre[l1]);
    TreeNode* root = new TreeNode(pre[l1]);
    int idx;
    for(int i=l2;i<=r2;++i) if (in[i]==pre[l1]) {idx=i; break;}
    TreeNode* left = DFS(pre, in, l1+1, l1+idx-l2, l2, idx-1);
    TreeNode* right = DFS(pre, in, l1+idx-l2+1, r1, idx+1, r2);
    root->left = left, root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=preorder.size();
    if(n==0) return NULL;
    return DFS(preorder, inorder, 0, n-1, 0, n-1);
}
