// File Name: j1.c
// Author: darkdream
// Created Time: 2013年04月14日 星期日 16时38分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define k 1000000007
int a[100005];

int comp(const void *a , const void *b)
{
  return *(int *)a -*(int *)b;
}
int main(){

   freopen("/home/plac/problem/J.in","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   for(int s = 1; s <= t; s++)
   {
      int n ;
	  long long int sum = 0  ;
	  long long int summ = 0;
	
	  scanf("%d",&n);
       for(int i = 0 ;i <n ; i ++)
       {
	     scanf("%d",&a[i]);
		 sum += a[i];
	   }
	   qsort(a,n,sizeof(int),comp);
	   for(int i = 0 ;i < n-1  ;i ++)
        {
		  int temp;
		  if(i > 0)
		  temp = a[i] - a[i-1] +1;
		  else
			 temp = a[i];
		  if(temp == 1)
		  {
		     sum -= 1;
			 summ += n-i-1;
		  }
		  else
		  {
		   summ += (sum*(temp-1)-(temp-2)*(temp-1)/2*(n-i)) % k +(n-i-1); 
		   sum = sum - (temp)*(n-i)+(n-i-1);
		  }
		}
	   printf("Case %d: %lld\n",s,summ%k);
   }
return 0 ;
}
