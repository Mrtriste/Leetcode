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

bool is_same(TreeNode* s, TreeNode* t){
    if(!s&&!t) return true;
    if(!s||!t) return false;
    return (s->val==t->val)&&is_same(s->left, t->left)&&is_same(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if(!s&&!t) return true;
    if(!s||!t) return false;
    return is_same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}