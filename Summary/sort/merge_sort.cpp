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

void merge(vector<int> &a, int l, int mid, int r, vector<int> tmp) {
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        tmp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = 0; i < k; ++i) a[l + i] = tmp[i];
}

void merge_sort(vector<int> &a, int l, int r, vector<int> tmp) {
    if (l < r) {
        int mid = l + ((r - l) >> 1);
        merge_sort(a, l, mid, tmp);
        merge_sort(a, mid + 1, r, tmp);
        merge(a, l, mid, r, tmp);
    }
}

int main() {
    vector<int> a = {1, 2, 8, 3, -1, -5, 5, 7, 0, -3, -1, 0};
    vector<int> tmp(a.size(), 0);
    merge_sort(a, 0, a.size() - 1, tmp);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";

    return 0;
}

