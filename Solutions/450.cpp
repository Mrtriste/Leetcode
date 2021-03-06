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

TreeNode* get_min(TreeNode* root){
    if(!root->left) return root;
    return get_min(root->left);
}

TreeNode* delete_min(TreeNode* root){
    if(!root->left) return root->right;
    root->left = delete_min(root->left);
    return root;
}

TreeNode* DFS(TreeNode* root, int key){
    if(!root) return NULL;
    if(root->val>key) root->left = DFS(root->left, key);
    else if(root->val<key) root->right = DFS(root->right, key);
    else{ // root is the node
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* next = get_min(root->right);
        next->right = delete_min(root->right); // 先right
        next->left = root->left; //再left
        return next;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    return DFS(root, key);
}
