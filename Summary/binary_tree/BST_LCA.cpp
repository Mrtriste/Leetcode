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

//235. 二叉搜索树的最近公共祖先

/////////////////////// method1 通用：任意二叉树都适用
TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return NULL;
    if(root->val==p->val || root->val==q->val) return root;
    TreeNode* left = DFS(root->left, p, q), *right = DFS(root->right, p, q);
    if(left&&right) return root;
    if(!left&&!right) return NULL;
    return left?left:right;
}

/////////////////////// method2 利用了二叉搜索树的性质：递归实现
TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
    int left = p->val, right = q->val;
    if(left>right) swap(left, right);
    if(root->val<left) return DFS(root->right, p, q);
    if(root->val>right) return DFS(root->left, p, q);
    return root;
}

/////////////////////// method3 利用了二叉搜索树的性质：迭代实现
TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
    int left = p->val, right = q->val;
    if(left>right) swap(left, right);
    while(1){
        if(root->val<left) root=root->right;
        else if(root->val>right) root=root->left;
        else return root; //不管是等于p/等于p/在p,q中间，都返回root
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return DFS(root, p, q);
}

