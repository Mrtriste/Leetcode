#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp{
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    priority_queue<ListNode*, vector<ListNode*>, cmp> que;
    for(int i=0;i<k;++i) if(lists[i])que.push(lists[i]);

    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while(!que.empty()){
        ListNode* tmp = que.top(); que.pop();
        cur->next = tmp;
        cur = cur->next;
        tmp = tmp->next;
        if(tmp) que.push(tmp);
    }
    return head->next;
}
