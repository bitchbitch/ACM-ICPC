// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 23时55分52秒

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
int a[1005];
int b[1005];
char str[1005];
int main(){
   int n , p ;
   scanf("%d %d",&n,&p);
   scanf("%s",&str[1]); 
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   for(int i = 1;i <= n;i ++)
   {
     a[i] =  str[i] - 'a' + 1;
   }
   int ans = 0 ;
   //for(int i =1 ;i <= n;i++)
	 //  printf("%d ",a[i]);
   for(int i = n;i >= 1 ;i --)
   {
	 int j ;
	 int s; 
     for(s = a[i] + 1 ; s <= p ;s ++)
	 {
	    if(s != a[i-1] &&( i-2 == -1 || (s != a[i-2]) ))
		{
		   b[i] = s; 
		   b[i-1] = a[i-1];
		   break;
		}
	 }
	 if(s == p + 1)
		 continue;
	 //printf("\n%d %d\n",i,s);
	 for( j = i+1;j<= n;j ++)
	 {
	    for( s = 1; s <= p;s ++) 
		{
	      if(s != b[j-1] && s!= b[j-2])	
		  {
			  b[j] = s;
			  //printf("%d***\n",s);
		      break;
		  }
		}
		if(s == p + 1)
		{
		  break;
		}
	 }
	 if(j == n+1)
	 {
	   ans = i;
	   break;
	 }
	}
   if(!ans)
   {
     printf("NO\n");
	 return 0 ; 
   }
   for(int i = 1;i <= ans -1;i ++)
	   printf("%c",a[i] + 'a' -1 );
   for(int j = ans ;j <= n;j ++)
	   printf("%c",b[j] + 'a' -1);

return 0;
}
