// File Name: a.c
// Author: darkdream
// Created Time: 2013年04月12日 星期五 18时55分47秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int a[1000005];
int MAX (int a, int b)
{
  if(a < b )
  {
    return b;
	
  }
  else 
	  return a;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ,k ;
   while(scanf("%d %d",&n,&k) != EOF)
   {
	   memset(a,0,sizeof(a));
	    int sum = 0 ;
	    int max = INT_MIN;
        for(int i = 1;i <= n ; i++)
		{
              scanf("%d",&a[i]);
	    }
		int i , j ,ti , tj;
	    ti = 1;
		tj = 1;
		sum = a[1];
        for(int i = 2;i <= n; i++)
		{
		   if(sum < 0)
		   {
		     sum = 0 ;
			 ti = i+1;
		   }
		   sum += a[i];
		   if(sum  > max)
		   {
		     if(i-ti+1 >=k)
			 {
			   max = sum;
			 }

		   }
		}
		if(max = INT_MIN)
		{
		    max = INT_MIN;	
		    sum = a[1];
	        for(int i = 2;i <= n;i ++)
			{ 

			   if(i >= k)
			   {  sum += a[i] -a[i-k];
				   if(sum > max)
					   max = sum;
			   }
			   else
			   {
			       sum +=a[i];
			   }
			   
			}
		}
   

		printf("%d\n",max);
   }
return 0 ;
}
