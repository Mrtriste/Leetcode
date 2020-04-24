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

TreeNode* DFS(TreeNode* root, int val){
    if(!root) return new TreeNode(val);  //root为空的时候就是val应该在的地方
    if(root->val>val) root->left = DFS(root->left, val);
    else if(root->val<val) root->right = DFS(root->right, val);
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    return DFS(root, val);
}
