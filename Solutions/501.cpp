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

int num=-1, last, max_num=0;
vector<int> res;

void DFS(TreeNode* root){
    if(!root) return;
    DFS(root->left);
    if(num==-1 || last!=root->val){
        if(num==max_num) res.push_back(last);
        else if(num>max_num) res={last};
        max_num = max(max_num, num);
        num = 1;
    }
    else num++;
    last = root->val;

    DFS(root->right);
}

vector<int> findMode(TreeNode* root) {
    DFS(root);
    if(num==max_num) res.push_back(last);
    else if(num>max_num) res={last};
    return res;
}
