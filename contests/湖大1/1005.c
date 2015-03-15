// File Name: 1005.c
// Author: darkdream
// Created Time: 2013年07月16日 星期二 13时33分23秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

long long  to(long long  k )
{
  if (k == 0 )
	  return 1; 
  if(k == 1 )
	  return 2 ;
  if(k %2 == 0 )
	  return to(k/2) * to(k/2)%1000000007;	
  else return to(k/2) * to(k/2) * 2 % 1000000007;

}

int POW	(int t )
{
   int sum = 1; 
   for(int i = 1;i <= t ;i ++)
	   sum *= 2;
   return t-1;
}
long long to1 (int t )
{
   for(int i = 1; ;i ++)
   {
     if((1000000007LL*i+1 ) % t == 0 )
		 return (1000000007*i+1)/t;
   }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char str[10];
   while(scanf("%s",str) != EOF)
   {
      int len = strlen(str);
	  int t ;
	  scanf("%d",&t);
      int ok = 0 ,p;
	  int ans[10];
	  int n =0 ;
	  for(int i = 0 ;i < len ;i ++)
	  {
	      if(str[i] == '0' || str[i] == '5') 
		  {
		    p =  t * len -(len - i );
			n ++;
			ans[n] = p; 
			ok = 1;
		  }

	  }
	  long long sum = 0; 
	  if(ok)
		{
		  for(int i = 1;i <= n;i ++)
		  {
		     sum += to(ans[n])*(to(len*t-1)*to(to1(POW(len)))%1000000007)%1000000007;
		  }
		}
       else printf("0\n");
   }
return 0 ;
}
