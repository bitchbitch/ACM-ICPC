// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年03月25日 星期三 12时32分43秒

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
char str[1000];
int tt;
int a[100];
int op[100];
int m ;
int solve1()
{
	 int ta[100];
	 int tp[100];
	 memcpy(ta,a,sizeof(a));
	 memcpy(tp,op,sizeof(op));
	 int tk = tt; 
	 int ok = 0; 
     while(!ok)
	 {
		 ok = 1; 
	     for(int i = 1;i < tk ;i ++)
		 {
		   if(tp[i] == 2 )
		   {
		      ok = 0 ; 
              ta[i] = ta[i]*ta[i+1];
			  for(int j = i+2;j <= tk ;j ++)
			  {
			      ta[j-1] = ta[j];
				  tp[j-2] = tp[j-1];
			  }
			  tk -- ; 
			  break;
		   }
		 }
	 }
     int ans = ta[1];
     for(int i = 1;i < tk;i ++)
	 {
	    if(tp[i] == 1) 
			ans += ta[i+1];
		else ans *= ta[i+1];
	 }
	 //printf("%d\n",ans);
	 if(ans == m )
		 return 1; 
	 return 0 ;
	 
}
int solve2()
{
     int ans = a[1];
     for(int i = 1;i < tt;i ++)
	 {
	    if(op[i] == 1) 
			ans += a[i+1];
		else ans *= a[i+1];
	 }
	 //printf("%d\n",ans);
	 if(ans == m )
		 return 1; 
	 return 0 ;
}
int main(){
    scanf("%s",str);
	scanf("%d",&m);
	int len = strlen(str); 
    int t = 0 ;
	tt = 0 ; 
	for(int i = 0 ;i < len ;i ++)
	{
        if(str[i] <= '9' && str[i] >= '0')	
		{
		   t = t * 10 + str[i] - '0' ;   
		}else{
		   tt ++ ;
		   //printf("***\n");
		   if(str[i] == '+')
             {
			   op[tt] = 1;
			 }else op[tt] = 2; 
           a[tt] = t ;
		   t = 0 ;
		}
	}
	tt ++ ; 
	a[tt] = t;
	int tt1 = solve1();
	int tt2 = solve2();
	if(tt1&& tt2)
	{
	   puts("U");
	}else if(tt1)
	{
	   puts("M");
	}else if(tt2)
		puts("L");
	else puts("I");
return 0;
}
