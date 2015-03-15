// File Name: b.c
// Author: darkdream
// Created Time: 2013年07月17日 星期三 10时57分18秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int a[2005];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n,limit;
  while(scanf("%d %d",&n,&limit) != EOF)
  {
	  int time2 = 0;
	  int time3 = 0;
      int sum = 0 ;
	  for(int i =1 ;i <= n;i ++)
	  { 
		  scanf("%d",&a[i]);
		  if(a[i] > limit &&(a[i] % limit == 0 || a[i] %limit >= 2))
		  {
		    sum += a[i]/ limit;
			a[i] = a[i] % limit;
		  }
	      if(a[i] %2 == 1 )
			{
			  time2 += (a[i]-3)/2;
			  time3 ++;
			}
		  else time2 += a[i]/2;

	  
	  }

	  if(limit  % 2 == 1 ) 
	  {
		if(limit == 3)
		{
		   sum += time2 + time3; 
		}
		else 
		{
	      int k = limit/2 ;
          int k2 = time2/(k-1);
	      if(k2  > time3)
		  {
		    sum += time3;
			sum += ceil((time2-time3*(k-1))*1.0/k);
		  }
		  else 
		  {
		     sum += k2;
             sum += ceil((time3-k2)*1.0/(int)(limit/3));
		  }
		
		}
	  }
	  else 
	  {
	    int  k = limit/2;
		int  k1 = limit/3;
        if(time2 % k == 0 )
		{
		  sum += time2/k;
		  sum += time3%k1 == 0 ?time3/k1:time3/k1 + 1;
		}
		else 
		{
             sum += time2/k +1;
			 int rest = time2 % k ;
			 rest = limit - (rest*2);
			 time3 = time3 - rest/3;
		     sum += time3%k1 == 0 ?time3/k1:time3/k1 + 1;
		
		}
	  
	  }

	printf("%d\n",sum);
  }

return 0 ;
}
/*
 *3 3
 8 2 2 
 *
 *
 */
