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

int DFS(TreeNode* root){
    if(!root) return 0;
    int left = DFS(root->left);
    if(left==-1) return -1;
    int right = DFS(root->right);
    if(right==-1) return -1;
    return abs(left-right)<2?max(left, right)+1:-1; //max()+1
}

bool isBalanced(TreeNode* root) {
    return DFS(root)!=-1;
}
