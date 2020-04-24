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

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int i=m-1, j=n-1, k=A.size()-1;
    while(i>=0 && j>=0) A[k--] = (A[i]>B[j])?A[i--]:B[j--];
    while(i>=0) A[k--] = A[i--];
    while(j>=0) A[k--] = B[j--];
}
