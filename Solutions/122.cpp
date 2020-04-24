#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int mmin = 0x3f3f3f, max_diff=0;
    for(int i=0;i<n;++i){
        if(prices[i]-mmin>0){
            max_diff+=prices[i]-mmin;
            mmin = prices[i];
        }
        else
            mmin = min(mmin, prices[i]);
    }
    return max_diff;
}
