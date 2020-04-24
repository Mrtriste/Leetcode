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

TreeNode* DFS(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2){
    if(l1>r1) return NULL;
    TreeNode* root = new TreeNode(postorder[r2]);
    int pos;
    for(int i=l1;i<=r1;++i){
        if(inorder[i]==postorder[r2]){
            pos = i;
            break;
        }
    }
    root->left = DFS(inorder, postorder, l1, pos-1, l2, pos-l1+l2-1);
    root->right = DFS(inorder, postorder, pos+1, r1, pos-l1+l2, r2-1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size()==0) return NULL;
    return DFS(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}
