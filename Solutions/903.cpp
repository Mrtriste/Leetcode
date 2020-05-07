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

// int DFS(string s){
//     if(s.length()==1) return 1;
//     int res = 0, mod=1e9+7, n=s.length();
//     if(s[0]=='D') res+=DFS(s.substr(1, n-1)), res%=mod;
//     if(s[n-1]=='I') res+=DFS(s.substr(0, n-1)), res%=mod;
//     for(int i=1;i<n;++i){
//         if(s[i]=='D'&&s[i-1]=='I'){
//             res+=DFS(s.substr(0, i)+s.substr(i+1, n-i-1)), res%=mod;
//             s[i-1]='D';
//             res+=DFS(s.substr(0, i)+s.substr(i+1, n-i-1)), res%=mod;
//             s[i-1] = 'I';
//         }
//     }
//     return res;
// }

int numPermsDISequence(string S) {
    int n = S.length(), mod=1e9+7;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // dp[i][j] S的前i个以j为结尾的有效个数
    // 思想是 考虑S的前i个字母，由[0,i]得到的有效排列
    // 当考虑i+1时，是可以根据上面的得到的，即重复子结构
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=i;++j){
            // 等于D, 如果p[i]=j, 那么p[i-1]可以取[j,i]
            // 如果p[i]和前面的重复，把大于等于p[i]的都加1
            // 这样就可以转化了
            if(S[i-1]=='D')
                for(int k=j;k<=i;++k){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            else{
                for(int k=0;k<j;++k){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    int res=0;
    for(int j=0;j<=n;++j){
        res += dp[n][j];
        res%=mod;
    }
    return res;
}