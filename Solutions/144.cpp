#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> res;
    while(root || !s.empty()){
        while(root){
            res.push_back(root->val);
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        root = root->right;
    }
    return res;
}

