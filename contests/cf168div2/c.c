// File Name: c.c
// Author: darkdream
// Created Time: 2013年02月21日 星期四 00时40分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

bool b[1000001000] = {0};
int main(){
    int n , k ;
   scanf("%d %d",&n,&k);
   int  a ,i;
   long long  sum = 0;
   
   for(i =1 ;i <= n; i++)
   {	   scanf("%d",&a);
	       getchar();
	        b[a] = 1;    
	   if (a % k == 0 && a/k !=0 && b[a/k] == 1)
		   sum ++;
		if (1ll*a*k <= 1e9 && b[a*k] == 1 )
			sum ++;
           
   }
  printf("%I64d\n",sum);
   

return 0 ;
}
