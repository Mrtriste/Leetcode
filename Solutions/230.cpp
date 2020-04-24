#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stack;
    while (true){
        while (root){
            stack.push(root);
            root=root->left;
        }
        root=stack.top(); stack.pop();
        k-=1;
        if(k==0) return root->val;
        root = root->right;
    }
}

//int res, i=0, flag=0;
//
//int InOrder(TreeNode* root, int k){
//    if(root==NULL) return 0;
//    if(flag) return 0;
//    InOrder(root->left, k);
//    i+=1;
//    if(i==k){
//        flag=1;
//        res = root->val;
//        return 0;
//    }
//    InOrder(root->right, k);
//}

//int kthSmallest(TreeNode* root, int k) {
//    InOrder(root, k);
//    return res;
//}
