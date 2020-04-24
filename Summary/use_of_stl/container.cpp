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

LONG_LONG_MIN, LONG_LONG_MAX, INT_MIN, INT_MAX;

void test_vector(){
    vector<int> a = {1,2,3,4,5};
    for(auto num:a) cout<<num<<" ";

    vector<int> b = {6,6,6,6,6,6,6,6};
    b.swap(a);

    for(auto num:a) cout<<num<<" ";
    for(auto num:b) cout<<num<<" ";

    a.clear();
    for(auto num:a) cout<<num<<" ";
}

void test_unordered_map(){
    unordered_map<int, int> map;
    map[1] = 1;
    map.erase(1);
}

void test_map(){
    map<pair<int, int>, int> m;
    int a=1, b=2;

    pair<int, int> p={a,b};
    m[p] = 10;
    m[p] += 1;
    cout<<m[p]<<endl;
    m[p] = 1;
    cout<<m[p]<<endl;

    m[make_pair(5,6)] = 3;
    m[{3,4}] = 5;
    cout<<m[{5,6}]<<" "<<m[{3,4}]<<endl;
    cout<<m.count({2,3})<<endl;  // count只有0或1两种值，表示是否存在

    map<pair<int, int>, int> pre;
    pre.swap(m);
    cout<<pre[{3,4}]<<endl;
}

void test_list(){
    list<int> mylist1, mylist2;
    list<int>::iterator it;

//    mylist1.push_front(1);
//    mylist1.push_back(1);
//    mylist1.pop_front();
//    mylist1.pop_back();
//    mylist1.front();
//    mylist1.back();
//    mylist1.size();

    // set some initial values:
    for (int i=1; i<=4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4

    for (int i=1; i<=3; ++i)
        mylist2.push_back(i*10);   // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                         // points to 2

    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
    // mylist2 (empty)
    // "it" still points to 2 (the 5th element)
    //此处的it由于是指向的mylist1,splice后，此迭代器依然存在于
    //mylist1中，故而不失效，而后面的splice，由于it指向的地址被插入到
    //mylist2中，而使迭代器it失效

    mylist2.splice (mylist2.begin(),mylist1, it);
    // mylist1: 1 10 20 30 3 4
    // mylist2: 2
    // "it" is now invalid.
    it = mylist1.begin();
    advance(it,3);           // "it" points now to 30

    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
    // mylist1: 30 3 4 1 10 20
    //注意此处mylist前后交换了，这可以用作list形如循环移位的操作
    cout << "mylist1 contains:";
    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    cout << "mylist2 contains:";
    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

void test_method(){
        //////////////////////////vector
    vector<int> v;
    v.push_back(0);
    v.front();
    v.back();
    v.pop_back();
    v.size();
    v.empty();

    //////////////////////////deque
    deque<int> dq;
    dq.push_back(0);
    dq.push_front(0);
    dq.front();
    dq.back();
    dq.pop_back();
    dq.pop_front();

    //////////////////////////stack
    stack<int> s;
    s.push(0);
    s.top();
    s.pop();
    s.size();
    s.empty();

    //////////////////////////queue
    queue<int> q;
    q.push(0);
    q.front();
    q.pop();
    q.size();
    q.empty();

    //////////////////////////priority_queue
    priority_queue<int> pq;
    pq.push(0);
    pq.top();
    pq.pop();
    pq.size();
    pq.empty();
}

int main() {
//    test_vector();
//    test_map();
    test_list();

    string sr = "ahidhocsh";
    sort(str.begin(), str.end());

    return 0;
}
