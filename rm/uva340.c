// File Name: uva340.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 16时52分41秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[2000], b[2000],c[20] , d[20];

int main(){
  int n , t = 1;
  while(scanf("%d",&n) , n )
  {
   memset(c,0,sizeof(c));
	for (int i = 1 ;i<= n;i++)
	{	scanf("%d" ,&a[i]);
		c[a[i]] ++;

	}
	printf("Game %d:\n",t);
	while(1)
	{
	 int sum1 = 0 ,sum2 = 0;
	 for(int i  = 1; i <= 9 ;i++)
		 d[i] = c[i];
	  for(int i = 1;i <= n ; i++ )
		  scanf("%d",&b[i]);
     if(b[1] == 0)
		 break;
	   for(int i = 1;i <= n;i++)
	   {
	     if(b[i] == a[i])
		 {	 sum1++;
	         d[b[i]] --;
		 }    
	   }
	   for(int i =  1; i<= n;i++)
	   {
	      if(b[i] != a[i])
		  {
		     if(d[b[i]] != 0)
			 {	 sum2++;
			    d[b[i]]--;
			 }
		  }
	   }
     printf("    (%d,%d)\n",sum1,sum2);

	}

   t ++;
  }

return 0 ;
}
