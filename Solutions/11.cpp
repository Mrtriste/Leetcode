#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int mmax = 0;
    int i=0, j=height.size()-1;
    while(i<j){
        mmax = max(mmax, min(height[i], height[j])*(j-i));
        if(height[i]<height[j]) i++;
        else j--;
    }
    return mmax;
}
