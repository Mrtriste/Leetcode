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

int sum = 0;
void DFS(TreeNode* root){
    if(!root) return;
    DFS(root->right);
    sum += root->val;
    root->val = sum;
    DFS(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    DFS(root);
    return root;
}
