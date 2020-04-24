//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//struct cmp{
//    bool operator()(ListNode *a,ListNode *b){
//        return a->val > b->val;
//    }
//};
//
//int main() {
//    vector<ListNode*> lists;
//    int k = lists.size();
//    priority_queue<ListNode*, vector<ListNode*>, cmp> que;
//    for(int i=0;i<k;++i) if(lists[i])que.push(lists[i]);
//
//    ListNode* head = new ListNode(0);
//    ListNode* cur = head;
//    while(!que.empty()){
//        ListNode* tmp = que.top(); que.pop();
//        cur->next = tmp;
//        cur = cur->next;
//        tmp = tmp->next;
//        if(tmp) que.push(tmp);
//    }
//    return head->next;
//
//    return 0;
//}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

///////////////////////////////////////
// 默认是 从大到小原理：if(a<b) swap(a,b);
// 所以可以改变<内部的大小比较
//struct Node{
//    int v, d;
//    Node(){}
//    Node(int vv, int dd) :v(vv), d(dd){}
//    bool operator<(const Node& b)const{
//        return d > b.d; // 从小到大
//    }
//};
// priority_queue<Node> q;

// 传cmp参数时，内部比较的操作：if(cmp(a,b)) swap(a,b);
struct cmp{
    bool operator ()( int a, int b){
        return a > b;  // 从小到大
    }
};

struct cmp1{
    bool operator()(int a, int b){
        return a < b;  //从大到小
    }
};

int  main(){
//    priority_queue<int> q;// 默认是 从大到小。
    priority_queue <int, vector<int>, less<int>> q;//从大到小
//    priority_queue <int, vector<int>, greater<int> > q; //从小到大，需要vector
//    priority_queue <int, vector<int>, cmp1> q;// return a < b; 从大到小，需要vector
//    priority_queue <int, vector<int>, cmp> q;// return a > b; 从小到大，需要vector

    q.push(10);
    q.push(2);
    q.push(3);
    q.push(15);
    q.push(1);

    while(!q.empty() ){
        int t =q.top(); q.pop();
        cout<<t<<endl;
    }
    return 0;
}
