// File Name: 325b.c
// Author: darkdream
// Created Time: 2013年07月19日 星期五 16时44分33秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
long long int up(long long int  n)
{
    double t = log(n)/log(2);
	return int(t);
}
long long  Pow(long long p)
{
   long long  sum = 1; 
   for(long long i = 1; i <= p ;i ++)
	  sum = sum * 2 ;
   return sum ;
}
int  cmp(const void *a , const void *b)
{
   return *(long long *)a - *(long long *)b;
}
long long ans[100] = {0},pre =0  ;
int  fen(long long n , long long p)
{
   long long  up = 0 ; 
   long long  high; 
   if(p == 1)
   { 
	   high = n; 
	   if(high >= 2 *1e9)
         high = 2 * 1e9; 
   }
   else
   {
	   high = n/(p-1) + 1;
	   
       if(high >= 2*1e9)
		   high = 2*1e9;
   }
   long long mid =  (up + high)/2;
   //printf("%I64d**\n",high);
   while(up <= high)
   {
      mid = (up + high )/2;
	  if(mid*(mid-1)/2 + mid*(p-1) > n || mid*(mid-1)/2 +mid*(p-1) < 0  || mid*(mid-1)/2+mid*(p-1) < up*(up-1)/2 + up*(p-1) )
		  high = mid-1;
	  else if(mid*(mid-1)/2 + mid*(p-1) < n)
		  up = mid + 1;
	  else 
	  {
		 if(mid % 2 == 0 )
			 break;
		 pre++;
		 ans[pre] = mid*p;
		 return 1; 
	  }
   }
   return 0 ;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   long long int n ; 
   scanf("%I64d",&n);
   long long  p = up(n) + 1;
   int ok = 0 ;
   for(long long  i = 0 ;i <= p;i ++)
   {
       if(fen(n,Pow(i)))
		   ok = 1;
   }
   if(!ok)
	   printf("-1\n");
   else
   {
      //qsort(ans+1,pre,sizeof(long long ),cmp);
	  for(int i = 1;i <= pre; i ++)
		  if(ans[i] != ans[i-1])
			  printf("%I64d\n",ans[i]);
   }
return 0 ;
}
