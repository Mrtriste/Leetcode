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

Node* last = new Node();

void DFS(Node* root){
    if(!root) return;
    DFS(root->left);
    last->right = root;
    root->left = last;
    last = root;
    DFS(root->right);
}

Node* treeToDoublyList(Node* root) {
    if(!root) return NULL;
    Node* dummy_head = last;
    DFS(root);

    Node* head = dummy_head->right;
    head->left = last;
    last->right = head;
    return head;

}
