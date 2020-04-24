#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/solution/mian-shi-ti-53-ii-0n-1zhong-que-shi-de-shu-zi-er-f/
    //我们做二分查找最后跳出来的i,j指向的是什么？--j在分界线前一个，i在分界面后一个
    //就是上面链接中的红绿之间的线，分成左边数组和右边数组，下面的代码返回的就是右边数组的第一个索引
    //这样我们就能明白为什么else j=mid-1; 因为i==j的时候要跳出，i要+1, 就指向右边数组的第一个了
    //最后跳出的时候，i比j大1，j是分界线的前一个，i是分界线的后一个

    //*************************
    //突然想出个很好的判断边界的办法
    //最重要的是找到那条分界线，我们每轮保留的a[i:j]一定要不脱离分界线，这样才能确定分界线，
    // 即左数组最后一个元素位置+1 或者 右数组第一个元素位置-1
    //举个不脱离分界线的例子
    //lower_bound:左边数组全部a[i]<x,右边a[i]>=x; 那么a[mid]>=x时右边就全舍去，j=mid-1; a[mid]<x左边全舍去，i=mid+1
    //upper_bound:左边数组全部a[i]<=x,右边a[i]>x; 那么a[mid]>x时右边就全舍去，j=mid-1; a[mid]<=x左边全舍去，i=mid+1
    //*************************
    vector<int> a = { -1, 2, 2, 4, 4, 4, 5, 6, 7 };
    int x = 4;

    int i=0, j=a.size()-1;
    //！！！！最后一个循环一定是i==j，mid=i=j，分为两种情况，mid指向左边数组最后一个 或者 右边数组第一个
    // 如果mid指向左边数组最后一个元素，那么i=i+1后跳出，i在分界线后，j在分界线前
    // 如果mid指向右边数组第一个元素，那么j=j-1后跳出，i在分界线后，j在分界线前
    //所以我们每轮保留的a[i:j]只要不脱离分界线即可
    while(i<=j){
        int mid = i+((j-i)>>1);
        if(a[mid]>=x) // >= 下界； > 上界
            //左边数组，最后i==j的时候会向后跳一个
            j=mid-1; //为什么可以mid+1而不是mid，j=mid-1不是全指向左边数组了吗 ，因为i==j的时候要跳出，i要+1, 就指向右边数组的第一个了
        else
            //右边数组
            i=mid+1;
    }
    cout<<i<<endl;
    return 0;
}
