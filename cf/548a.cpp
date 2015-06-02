// File Name: 548a.cpp
// Author: cijianzy
// Created Time: 2015年06月02日 星期二 15时19分09秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
char str[1010];
int solve(int l , int r ){
    for(int i = l ;i <= r;i ++)
    {
        if(str[i] != str[r-(i-l)])
            return 0 ; 
    }
    return 1; 
    
}
int main(){
    scanf("%s",str);
    int k ; 
    scanf("%d",&k);
    int len = strlen(str);
    int s = len / k ; 
    if(k > len )
    {
        puts("NO");
        return 0 ; 
    }
    for(int i = 0 ;i < len ;i += s ){
        if(solve(i,i+s-1) ==0 )
        {
            puts("NO");
            return 0 ; 
        }
    } 
    puts("YES");

return 0;
}
