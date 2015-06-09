// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月07日 星期日 17时37分23秒

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
#define maxn 2000
using namespace std;
int hsp[2000];
int hsm[2000];
int n,tmp,ok;
int ch[maxn][2];
int p[maxn];
int m[maxn];

void solve(int &x, int lp,int rp,int lm,int rm){
    if(rp < lp )
        return ; 
    x = p[lp];
    if(lp ==rp){
        return ; 
    }
    solve(ch[x][0],lp+1,lp+(hsm[p[lp]]-lm),lm,hsm[p[lp]]-1);
    solve(ch[x][1],lp+(hsm[p[lp]]-lm)+1,rp,hsm[p[lp]]+1,rm);
}
void print(int x){
    if(x == 0 )
        return ; 
    swap(ch[x][0],ch[x][1]);
    print(ch[x][0]);
    print(ch[x][1]);
    if(ok == 0){
        printf("%d",x);
        ok = 1; 
    }else{
        printf(" %d",x);
    }
}
int main(){
    int T; 
    time_t be,en;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    be = clock();
    scanf("%d",&T);
    while(T--){
         memset(ch,0,sizeof(ch));
         scanf("%d",&n);
         for(int i = 1 ;i <= n;i ++){ 
            scanf("%d",&p[i]);
            hsp[p[i]] = i ; 
         }
         for(int i = 1;i <= n;i ++){
            scanf("%d",&m[i]);
            hsm[m[i]] = i ; 
         }
         solve(ch[1][0],2,hsm[1],1,hsm[1]-1);
         solve(ch[1][1],hsm[1]+1,n,hsm[1]+1,n);
         ok = 0 ; 
         print(1);
         puts("");
    }
    en = clock();
    printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
