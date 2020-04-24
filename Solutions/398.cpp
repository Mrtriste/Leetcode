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

int pick(int target) {
    int cnt=0, index;
    for(int i=0;i<nums.size();++i){
        if(nums[i]==target){
            cnt+=1;
            int r=rand()%cnt;
            if(r==0) index=i;
        }
    }
    return index;
}
