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

//109. 有序链表转换二叉搜索树

// [head, tail)
TreeNode* DFS(ListNode*head, ListNode* tail){
    if(head==tail) return NULL;
    ListNode* i=head, *j = head;
    while(j!=tail&&j->next!=tail) i=i->next, j=j->next->next;
    if(j!=tail) j=j->next;
    TreeNode* root = new TreeNode(i->val);
    root->left = DFS(head, i);
    root->right = DFS(i->next, j);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return DFS(head, NULL);
}

