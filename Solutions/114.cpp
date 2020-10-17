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

TreeNode* last = NULL;

void DFS(TreeNode* root){
    if(!root) return;
    DFS(root->right);
    DFS(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
}

void flatten(TreeNode* root) {
    DFS(root);
}

int main() {

    return 0;
}
