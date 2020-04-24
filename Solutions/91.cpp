#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numDecodings(string s) {
    int n=s.length();
    if(s[0]=='0') return 0;
    if(n==1) return 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i=1;i<n;++i){
        if(s[i]=='0'){
            if(s[i-1]=='1'||s[i-1]=='2')
                dp[i] = i>1?dp[i-2]:1;
            else
                return 0;
        }
        else{ //01-09,11-26, 27-99
            string t = s.substr(i-1, 2);
            if(t>="11"&&t<="26")
                dp[i] = dp[i-1] + (i>1?dp[i-2]:1);
            else
                dp[i] = dp[i-1];
        }
    }
    return dp[n-1];
}
