// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月06日 星期一 15时36分38秒

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
#define maxn 1000005
using namespace std;
int n , k ; 
char str[1000005];
int next[maxn];
int len ; 
void getnext(char *p )
{
   len = strlen(p);
   next[0] = -1;
   int k = -1;
   int j = 0 ; 
   while(j < len)
   {
       if(k == -1 || p[j] == p[k])
	   {
	     ++ k ; 
		 ++ j; 
		 next[j] = k ;
	   }else{
	      k = next[k];
	   }
   }
}
int fa[maxn];
int dp[maxn];
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",str);
	getnext(str);
	if(k == 1)
	{
	for(int i = 1; i <= len ;i ++)
		putchar('1');
	return 0 ; 
	}
	printf("\n");
	int  tmp = 0;
	for(int i = 1; i <= len ;i ++)
	{
	   int ok = 0 ; 

	   tmp --;
	   if(tmp > 0 && next[i] == next[i-1]+1)
	   {
	      ok = 1;
	   }
	   if(next[i] !=  next[i-1] + 1)
	   {
	     tmp = 0 ;  
	   }
       if(i % k == 0 && next[i] != 0 && i % (i - next[i]) ==0 && (i/(i-next[i]))%k == 0)
	   {
         ok = 1; 
		 tmp = i /k ; 
	   }else if(i % (k+1) == 0 && next[i] != 0 && i % (i - next[i]) ==0 && (i/(i-next[i]))%(k+1) == 0)
	   {
		   ok = 1; 
	   }
	   if(ok)
		   printf("1");
	   else printf("0");
	}
    printf("\n");
	
return 0;
}
