#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<TreeNode*> DFS(int l, int r){
    if(r<l) return {NULL};
    vector<TreeNode*> res;
    for(int i=l;i<=r;++i){
        //不能放这里 root = new TreeNode(i)
        vector<TreeNode*> left_l = DFS(l, i-1);
        vector<TreeNode*> right_l = DFS(i+1, r);
        for(int j=0;j<left_l.size();++j)
            for(int k=0;k<right_l.size();++k){
                TreeNode* root = new TreeNode(i); //注意要放这里！！！
                root->left = left_l[j];
                root->right = right_l[k];
                res.push_back(root);
            }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if(n<1) return {};
    return DFS(1, n);
}
