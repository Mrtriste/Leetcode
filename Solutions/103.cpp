#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> res;
    queue<TreeNode*> que;
    que.push(root);
    int flag = 1;
    while(!que.empty()){
        int size = int(que.size());
        int i=0;
        vector<int> l(size);
        while(i<size){
            TreeNode* tmp = que.front(); que.pop();
            // push
            int idx = flag?i:size-1-i;
            l[idx] = tmp->val;

            if(tmp->left) que.push(tmp->left);
            if(tmp->right) que.push(tmp->right);
            i++;
        }
        flag = !flag;
        res.push_back(l);
    }
    return res;
}
