#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node(int val) : val(val) {}
};

// sort的比较函数，
bool cmp1(Node &a, Node &b) {
    // return a.val<b.val;  //sort后从小到大 1 2 4 6 7 9
    return a.val > b.val;  //sort后从大到小 9 7 6 4 2 1
}

// priority_queue
struct cmp2 {
    bool operator()(Node &a, Node &b) {
        return a.val < b.val;  // 最大的先出 9 7 6 4 2 1
//      return a.val>b.val;  // 最小的先出 1 2 4 6 7 9
    }
};

int main() {
    int a[6] = {6, 4, 1, 7, 2, 9};

    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0] > b[0];
    });

    //////////////////////////////////////////////////////// sort
    //括号里是什么顺序返回的就是什么顺序
    // 从小到大：return a.val<b.val; less<int>()
    // 从大到小：return a.val>b.val; greater<int>()
    ////////////////////////// sort Node cmp1
    vector<Node> l;
    for (int i = 0; i < 6; ++i) l.push_back(Node(a[i]));
    sort(l.begin(), l.end(), cmp1);
    for (int i = 0; i < 6; ++i) cout << l[i].val << " ";

    /////////////////////////  sort int greater/less
    sort(a, a+6, greater<int>());  // 9 7 6 4 2 1
    sort(a, a+6, less<int>());  // 1 2 4 6 7 9
    for(int i=0;i<6;++i) cout<<a[i]<<" ";



    ///////////////////////////////////////////////////////// priority_queue
    // 先按sort排好序，最后面的优先级最大
    // return a.val<b.val; less<int>(): 从小到大排好，最后面优先级最高，最大的先出
    // return a.val>b.val; greater<int>(): 从大到小排好，最后面优先级最高，最小的先出

    ////////////////////////// priority_queue Node cmp2
    priority_queue<Node, vector<Node>, cmp2> que;
    for(int i=0;i<6;++i) que.push(Node(a[i]));
    while (!que.empty()){
        Node t = que.top(); que.pop();
        cout<<t.val<<" ";
    }

    ////////////////////////// priority_queue int greater/less
//    priority_queue<int, vector<int>, greater<int>> que; // 1 2 4 6 7 9
//    priority_queue<int, vector<int>, less<int>> que; // 9 7 6 4 2 1
//    for(int i=0;i<6;++i) que.push(a[i]);
//    while (!que.empty()){
//        int t = que.top(); que.pop();
//        cout<<t<<" ";
//    }

    return 0;
}
