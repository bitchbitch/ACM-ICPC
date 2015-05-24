// File Name: c.cpp
// Author: cijianzy
// Created Time: 2015年05月23日 星期六 22时09分47秒

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
map<LL,int> mp;
struct node{
  int ip[5];    
}a[1005],b[100];
int main(){
    int t; 
    scanf("%d",&t);
    for(int ca = 1; ca <= t ; ca ++){
        int n , m ; 
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;i ++){
            scanf("%d.%d.%d.%d",&a[i].ip[1],&a[i].ip[2],&a[i].ip[3],&a[i].ip[4]);
        }
        for(int i = 1;i <= m;i ++){
            scanf("%d.%d.%d.%d",&b[i].ip[1],&b[i].ip[2],&b[i].ip[3],&b[i].ip[4]);
        }
        printf("Case #%d:\n",ca);
        for(int i = 1;i <= m;i ++){
            mp.clear();
            int sum = 0 ; 
            LL x ;
            for(int j = 1;j <= n ;j ++){
                x = (a[j].ip[1]&b[i].ip[1] )+ (a[j].ip[2]&b[i].ip[2] )*1ll*1000 +(a[j].ip[3]&b[i].ip[3]) *1ll*1000000 +  (a[j].ip[4]&b[i].ip[4]) *1ll*1000000000; 
                if(!mp[x]){
                    mp[x] = 1; 
                    sum ++ ; 
                }
            }
            printf("%d\n",sum);
        }
    }
return 0;
}
