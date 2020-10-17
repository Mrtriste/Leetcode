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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0&&j>=0) nums1[k--] = nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
    while(i>=0) nums1[k--] = nums1[i--];
    while(j>=0) nums1[k--] = nums2[j--];
}

int main() {

    return 0;
}
