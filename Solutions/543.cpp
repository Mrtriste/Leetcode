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

int res=0;

int DFS(TreeNode* root){
    if(!root) return 0;
    int l=DFS(root->left), r=DFS(root->right);
    res = max(res, l+r+1);
    return max(l, r)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    DFS(root);
    return res-1;
}

int main() {

    return 0;
}
