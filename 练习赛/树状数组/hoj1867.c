// File Name: hoj1867.c
// Author: darkdream
// Created Time: 2013年03月27日 星期三 15时18分41秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000005];
int b[1000005];
int m;
int lowbit (int x)
{
   return x &(-x);
}
int update(int x,int i )
{
	while(x <= m)
	{
	  b[x] += i ;
	  x = x +lowbit(x);
	}
}
int sum(int x)
{
   int res = 0 ;
   while(x >= 1)
   {
      res += b[x];
	  x -= lowbit(x);

   }
   return res;
}
int isprime(int x)
{
  if (x <= 1 )
	  return 0 ;
   for(int i = 2 ; i <= sqrt(x) ; i ++ )
	   if(x % i == 0  )
		   return  0;
  return 1;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n,t,k = 1;
   while(scanf("%d %d %d",&m,&n,&t) != EOF)
   {  memset(b,0,sizeof(b));
       memset(a,0,sizeof(a));
	   if(m== 0 && n==0 && t == 0)
		 break;
	   printf("CASE #%d:\n",k);
       k++;
       for(int i = 1;i <= m;i ++)
	   {
	     a[i] = t ;
	   }
	   int ok = isprime(t);
	   for(int i = 1;i <= n ;i ++)
	   {
		   int ta,tb,tc;
		   scanf("%d %d %d",&ta,&tb,&tc);
		   if(ta)
		   {
			 if(ok)
		     printf("%d\n",sum(tc)-sum(tb-1) +(tc-tb+1));
			 else
			 printf("%d\n",sum(tc)-sum(tb-1));
		   }
		   else
		   {
		      if(isprime(a[tb]))
			  {  if(!isprime(a[tb]+tc))
				  	  update(tb,-1);
                  a[tb]+= tc;
			  }
			  else
			  {
			     if(isprime(a[tb]+tc))
					 update(tb,1);
			     a[tb]+=tc;
			  }
		   }
	   }
   printf("\n");
   }
return 0 ;
}
