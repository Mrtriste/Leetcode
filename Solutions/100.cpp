#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool DFS(TreeNode* p, TreeNode* q){
    if(!q&!p) return true;
    if((!p&&q)||(p&&!q)) return false;
    return (p->val==q->val) && DFS(p->left, q->left) && DFS(p->right, q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return DFS(p, q);
}
