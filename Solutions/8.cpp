#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int myAtoi(string str) {
    int i=0;
    while(str[i]==' ')
        ++i;
    if(!(str[i]=='+'||str[i]=='-'||(str[i]>='0'&&str[i]<='9')))
        return 0;
    int flag = 1;
    if(str[i]=='+')
        flag = 1, ++i;
    else if(str[i]=='-')
        flag= -1, ++i;

    int res = 0;
    int MIN = (1<<31), MAX = 0x7fffffff;
    while(str[i]<='9' && str[i]>='0'){
        int a = int(str[i]-'0');
        if(flag==-1&&(res<MIN/10||(res==MIN/10&&a>8)))
            return MIN;
        if(flag==1&&(res>MAX/10||(res==MAX/10&&a>7)))
            return MAX;
        res = res*10+a*flag;
        ++i;
    }
    return res;
}
