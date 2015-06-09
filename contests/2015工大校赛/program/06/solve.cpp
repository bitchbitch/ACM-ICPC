// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 21时40分16秒
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

int hs[5005];
int ans[5005];
void solve(){
   ans[1] = 1; 
   ans[2] = 2; 
   for(int i = 1;i <= 5000 ;i++)
       hs[i] = 1;
   
   for(int i = 3;i <= 5000; i ++){
       int mx = 1e9;
        for(int j = 1;j <= i-1;j ++){
            for(int k = hs[j];k <= i-1;k ++){
                if(j != k ){
                    int t = ans[j]*2 + ans[k]*3; 
                    if(t > ans[i-1]){
                        hs[j] = k; 
                        if(t < mx)
                            mx = t; 
                        break;
                    }
                }
            }    
        }
        ans[i] = mx; 
   }
}/*
int main(){
    time_t be,en;
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    be = clock();
    int T;
    solve();   
    scanf("%d",&T);
    int n; 
    while(T--){
    scanf("%d",&n);
    printf("%d\n",ans[n]);
    }
    en = clock();
    printf("%lf",(en-be)*1.0/CLOCKS_PER_SEC);
   return 0;
}*/
int main()
{   int n,t,k,i,j,h,a[30000];
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    time_t en,be;
    int T;
    be = clock();
        a[1]=1;a[2]=2;k=2;
        for (t=3;t<=5000;t++)
        {
            k++;
            for (h=0,i=2;i<t;i++)
            {for (j=1;j<i;j++)
                if (k==2*a[i]+3*a[j]||k==2*a[j]+3*a[i])
                {h=1;a[t]=k;break;}
                if (h==1) break;
            }
            if (h==0) t--;
        }
    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    en = clock();
    printf("%lf",(en-be)*1.0/CLOCKS_PER_SEC);
    return 0 ; 
}
