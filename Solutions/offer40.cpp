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

int partition(vector<int>& arr, int l, int r){
    int i=l, j=r;
    int x = arr[i];
    while(i<j){
        while(i<j && arr[j]<x) j--;
        if(i<j) swap(arr[i++], arr[j]);
        while(i<j && arr[i]>=x) i++;
        if(i<j) swap(arr[j--], arr[i]);
    }
    arr[i] = x;
    return i;
}

void merge_sort(vector<int>& arr, int k, int l, int r){
    if(l<r){
        int pos = partition(arr, l, r);
        if(pos==k) return;
        if(pos<k){
            merge_sort(arr, k, l, k-1);
            merge_sort(arr, k, k+1, r);
        }
    }
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    merge_sort(arr, k, 0, arr.size()-1);
    vector<>
}

int main() {

    return 0;
}
