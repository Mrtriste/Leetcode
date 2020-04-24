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

//面试题 04.09. 二叉搜索树序列
vector<vector<int>> res;

void DFS(TreeNode* root, vector<TreeNode*> l, vector<int> &path){
    if(root->left) l.push_back(root->left);
    if(root->right) l.push_back(root->right);
    if(l.size()==0){
        res.push_back(path);
        return;
    }
    for(int i=0;i<l.size();++i){
        TreeNode* next = l[i];
        path.push_back(next->val);
        vector<TreeNode*> next_l;
        for(int j=0;j<i;++j) next_l.push_back(l[j]);
        for(int j=i+1;j<l.size();++j) next_l.push_back(l[j]);
        DFS(next, next_l, path);
        path.pop_back();
    }

}

vector<vector<int>> BSTSequences(TreeNode* root) {
    if(!root) return {{}};
    vector<int> path = {root->val};
    DFS(root, {}, path);
    return res;
}
