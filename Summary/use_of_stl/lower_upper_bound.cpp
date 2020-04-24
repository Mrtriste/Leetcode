#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node() {}
    Node(int val):val(val){}
    // Node(int val){this->val=val;}  //这种也可以
    bool operator <(const Node &a) const{
        return val<a.val;
    }
};

int main() {
    //////////////////////////// lower/upper bound查找数组
    int a[10] = {1,2,2,3,3,4,4,5,6,8};
    cout<<lower_bound(a, a+10, 3)<<endl;  // 0x81fe2c
    cout<<upper_bound(a, a+10, 3)<<endl;  // 0x81fe34
    cout<<lower_bound(a, a+10, 3)-a<<endl;  // 3
    cout<<upper_bound(a, a+10, 3)-a<<endl;  // 5
    cout<<upper_bound(a, a+10, 8)-a<<endl;  // 10
    cout<<upper_bound(a, a+10, 9)-a<<endl;  // 10

    cout<<upper_bound(a+1, a+10, 9)-a<<endl;  // 10
    cout<<upper_bound(a+1, a+10, 3)-a<<endl;  // 5

    //////////////////////////// lower/upper bound查找vector
    vector<int> c = {1,2,2,3,3,4,4,5,6,8};
    // cout<<(lower_bound(c.begin(), c.end(), 3))<<endl;  //报错
    cout<<(lower_bound(c.begin(), c.end(), 3)-c.begin())<<endl;  //3
    cout<<(upper_bound(c.begin(), c.end(), 3)-c.begin())<<endl;  //5

    //////////////////////////// lower/upper bound查找vector<Node>
    vector<Node> d(10);
    for(int i=0;i<10;++i) d[i] = Node(a[i]);
    cout<<(lower_bound(d.begin(), d.end(), Node(3))-d.begin())<<endl;  //3 return val<a.val;
    cout<<(upper_bound(d.begin(), d.end(), Node(3))-d.begin())<<endl;  //5 return val<a.val;
    cout<<(lower_bound(d.begin(), d.end(), Node(3))-d.begin())<<endl;  //10 return val>a.val;  错的
    cout<<(upper_bound(d.begin(), d.end(), Node(3))-d.begin())<<endl;  //10 return val>a.val;  错的

    //////////////////////////// 数组转vector
    // vector<int> vec(a,a+10);
    vector<int> vec(a,a+ sizeof(a)/ sizeof(int));
    for(auto v:vec) cout<<v<<" ";
    cout<<endl;

    //////////////////////////// vector转数组
    int *b = new int[vec.size()];
    if(!vec.empty()) memcpy(b, &vec[0], vec.size()* sizeof(int));
    for(int i=0;i<vec.size();++i) cout<<b[i]<<" ";
    cout<<endl;

    return 0;
}
