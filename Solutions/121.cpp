#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int mmin=0x3f3f3f3f, max_diff=0;
    for(int i=0;i<prices.size();++i){
        mmin = min(mmin, prices[i]);
        max_diff = max(max_diff, prices[i]-mmin);
    }
    return max_diff;
}
