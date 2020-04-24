#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> res;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = int(que.size());
        vector<int> l;
        while(size--){
            TreeNode* tmp = que.front(); que.pop();
            l.push_back(tmp->val);
            if(tmp->left)que.push(tmp->left);
            if(tmp->right) que.push(tmp->right);
        }
        res.push_back(l);
    }
    return res;
}
