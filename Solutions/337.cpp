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

//rob, not
vector<int> DFS(TreeNode* root){
    if(!root) return{0,0};
    vector<int> left = DFS(root->left), right=DFS(root->right);
    int rob = root->val + left[1] + right[1];
    int notrob = max(left[0], left[1]) + max(right[0], right[1]);
    return {rob, notrob};
}

int rob(TreeNode* root) {
    vector<int> res = DFS(root);
    return max(res[0], res[1]);
}

int main() {

    return 0;
}
