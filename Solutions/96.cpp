#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//C(0) = 1; C(n+1) = C(n)*[2(2n+1)/n+2]
int numTrees(int n) {
    long long C=1;
    for(int i=0;i<n;++i)
        C = C*2*(2*i+1)/(i+2);  //C放前面，(2*i+1)/(i+2)是小数
    return C;
}


//int numTrees(int n) {
//    vector<long long> dp(n+10, 0);
//    dp[0] = dp[1] = 1;
//    for(int i=2;i<=n;++i)
//        for(int j=0;j<i;++j)
//            dp[i] += dp[j]*dp[i-1-j];
//    return dp[n];
//}
