// File Name: b.c
// Author: darkdream
// Created Time: 2014年03月16日 星期日 23时58分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int a[2000];
int ta[2000];
int hs1[1000005];
int hs2[1000005];
int num[3000];
int rans[3000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n , k ;
   scanf("%d %d",&n,&k);
   int min = INT_MAX;
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   memset(hs1,0,sizeof(hs1));
   memset(hs2,0,sizeof(hs2));
   memset(num,0,sizeof(num));
   memset(rans,0,sizeof(rans));
   hs1[0] = 1; 
   ta[0] = a[1];
   min = a[1];
   for(int i = 2;i <= n;i ++ )
   {
       int  p = a[1] + (i-1)*k - a[i];
	   num[i] = p ;
	   ta[i] = a[i] + num[i];	
	   if(ta[i] < min)
		   min = ta[i];
	   if(p < 0 )
	   {
	     hs2[-p] ++;
	   }else hs1[p] ++ ;
   }
   int max = -1;
   int ans = 0 ;
   for(int i = 0;i <= min -1 ;i ++ )
	   if(hs1[i] > max)
	   {
	     max = hs1[i];
		 ans = i ; 
	   }
   for(int i = 1;i <= 1000002 ;i++)
      if(hs2[i] > max)
	  {
	    max = hs2[i];
		ans = -i;
	  }
   int t ; 
   for( t = 1;t <= n;t ++)
   {
        if(num[t] == ans)
			break;
   }
   int tsum = 0 ; 
   for(int i = 1;i < t;i ++)
   {
       rans[i] = a[t] - (t-i) *k - a[i];
	   if(rans[i] != 0)
		   tsum ++ ; 
   }
   for(int i = t+ 1; i <= n;i ++)
   {
   
       rans[i] = a[t] + (i-t) *k - a[i];
	   if(rans[i] != 0)
		   tsum ++ ; 
   }
   printf("%d\n",tsum);
   for(int i = 1;i <= n;i ++)
   {
      if(rans[i] > 0 )
		  printf("+ %d %d\n",i,rans[i]);
	  else if(rans[i] < 0) 
		  printf("- %d %d\n",i,-rans[i]);
   }

return 0 ;
}
