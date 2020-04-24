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

//700. 二叉搜索树中的搜索

TreeNode* DFS(TreeNode* root, int val){
    if(!root) return NULL;
    if(root->val==val) return root;
    else if(root->val>val) return DFS(root->left, val);
    else return DFS(root->right, val);
}

TreeNode* searchBST(TreeNode* root, int val) {
    return DFS(root, val);
}

