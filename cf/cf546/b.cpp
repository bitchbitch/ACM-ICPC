// File Name: b.cpp
// Author: cijianzy
// Created Time: 2015年05月23日 星期六 00时38分19秒

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
int a[4000];
int main(){
    int n; 
    scanf("%d",&n);
    for(int i= 1;i <= n;i ++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int sum =0  ;
    for(int i =2 ;i <= n;i ++)
    {
        if(a[i] <= a[i-1]){
            sum += a[i-1]+ 1 -a[i] ;
            a[i] = a[i-1] + 1; 
        }
    }
    printf("%d\n",sum);
return 0;
}
