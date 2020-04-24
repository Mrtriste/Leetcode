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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    q.push(root);

    stack<vector<int>> s;

    while(!q.empty()){
        int size = q.size();
        vector<int> tmp;
        for(int i=0;i<size;++i){
            TreeNode* cur = q.front(); q.pop();
            tmp.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        s.push(tmp);
    }

    vector<vector<int>> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
