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

TreeNode* DFS(TreeNode* t1, TreeNode* t2){
    if(!t1&&!t2) return NULL;
    if(!t1||!t2) return t1?t1:t2;
    t1->val += t2->val;
    t1->left = DFS(t1->left, t2->left);
    t1->right = DFS(t1->right, t2->right);
    return t1;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    return DFS(t1, t2);
}
