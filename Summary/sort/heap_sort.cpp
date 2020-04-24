#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

//从小到大排,要建立大顶堆，每次找到最大的a[0],放到最后
void max_heap_fix_down(vector<int> &a, int i, int n){
    int dad = i, son=2*i+1;
    while(son<n){
        if(son+1<n && a[son]<a[son+1]) son++; //希望找到左右节点中更大的son
        if(a[dad]>a[son]) return;
        swap(a[dad], a[son]);
        dad = son, son = 2*son+1;
    }
}

//从大到小排,要建立小顶堆，每次找到最小的a[0],放到最后
void min_heap_fix_down(vector<int> &a, int i, int n){
    int dad = i, son = 2*i+1;
    while (son<n){
        if(son+1<n && a[son]>a[son+1]) son++; //希望找到左右节点中更小的son
        if(a[dad]<a[son]) return;
        swap(a[dad], a[son]);
        dad = son, son = 2*son+1;
    }
}

void heap_sort(vector<int> &a, int n){
    for(int i=(n-1)/2;i>=0;--i)
//        max_heap_fix_down(a, i, n); // 从小到大排序
        min_heap_fix_down(a, i, n);
    for(int i=n-1;i>=0;--i){
        swap(a[0], a[i]);
//        max_heap_fix_down(a, 0, i); // 从小到大排序
        min_heap_fix_down(a, 0, i);
    }

}

int main() {
    vector<int> a = {1, 2, 8, 3, -1, -5, 5, 7, 0, -3, -1, 0};
    heap_sort(a, a.size());
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<" ";

    return 0;
}

