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

int minArray(vector<int>& numbers) {
    int l=0, r=numbers.size()-1;
    while(l<r){
        int mid = l+((r-l)>>1);
        if(numbers[mid]>numbers[r]) l=mid+1;
        else if(numbers[mid]<numbers[r]) r=mid;
        else r--;
    }
    return numbers[l];
}