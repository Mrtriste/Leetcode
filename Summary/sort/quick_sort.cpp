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

int partion(vector<int> &a, int l, int r) {
    int i = l, j = r, x = a[l];
    while (i < j) {
        while (i < j && a[j] > x) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] < x) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = x;
    return i;
}

void quick_sort(vector<int> &a, int l, int r) {
    if (l < r) {
        int position = partion(a, l, r);
        quick_sort(a, l, position - 1);
        quick_sort(a, position + 1, r);
    }
}

int main() {
    vector<int> a = {1, 2, 8, 3, -1, -5, 5, 7, 0, -3, -1, 0};
    quick_sort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";

    return 0;
}

