// File Name: b.c
// Author: darkdream
// Created Time: 2013年03月19日 星期二 13时49分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     int n , m ;
	 scanf("%d %d",&n,&m);
     if(m+1 == n  )
	 {
		 printf("0\n");
		 continue;
	 }
	 else  if(m +1 > n )
		 printf("-1\n");
	 else
	 {
	    int ans = 0 ;
	    int sum =  0 ;;
		for(int x = 1 ; x <=sqrt(n)+1  ; x ++)
		{
             if((n-m - x )%(2*x -1) == 0)
				{
				 int y = (n- m - x)/(2*x - 1);
				 
				  if( x + y <= m)
				  { 
				     ans =  1;
					  if(x + y  > sum )
					  {  sum = x+y;
					  }
					 
				  }
					 
				}
		}
		if(ans)
			printf("%d\n",m - sum);
		else
			printf("-1\n");
       
	 }
   }
return 0 ;
}
