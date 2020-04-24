#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}


//vector<int> res;

//void DFS(TreeNode* root){
//    if(!root) return;
//    DFS(root->left);
//    res.push_back(root->val);
//    DFS(root->right);
//}
//
//vector<int> inorderTraversal(TreeNode* root) {
//    TreeNode* root;
//    DFS(root);
//    return res;
//}
