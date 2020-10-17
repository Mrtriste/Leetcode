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

struct Node{
    Node(int xx, int c):x(xx), cnt(c){}
    int x;
    int cnt;
};

struct cmp{
    bool operator ()(Node& a, Node& b){
        return a.cnt>b.cnt;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();++i) mp[nums[i]] += 1;
    priority_queue<Node, vector<Node>, cmp> q;
    for(auto it=mp.begin();it!=mp.end();++it){
        q.push(Node(it->first, it->second));
        if(q.size()>k) q.pop();
    }

    vector<int> res;
    while(!q.empty()){
        Node t=q.top(); q.pop();
        res.push_back(t.x);
    }
    return res;
}

int main() {

    return 0;
}
