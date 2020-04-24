#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int reverse(int x) {
    int res=0, MAX=0x7fffffff, MIN=(1<<31); //qufan+1
    while(x!=0){
        int mod=x%10;
        x /= 10;
        if(res>MAX/10||(res==MAX/10&&mod>7)) return 0;
        if(res<MIN/10||(res==MIN/10&&mod<-8)) return 0;

        res = res*10+mod;
    }
    return res;
}
