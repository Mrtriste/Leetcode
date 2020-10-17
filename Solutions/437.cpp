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
int ssum=0;
map<int, int> mp;

void DFS(TreeNode* root, int sum){
    if(!root) return;
    ssum+=root->val;
    res += mp[ssum-sum];
    mp[ssum] += 1;
    DFS(root->left, sum);
    DFS(root->right, sum);
    mp[ssum] -= 1;
    ssum -= root->val;
}

int pathSum(TreeNode* root, int sum) {
    mp[0] = 1;
    DFS(root, sum);
    return res;
}

int main() {

    return 0;
}
