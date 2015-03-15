// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月04日 星期一 23时13分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n , m ; 
  scanf("%d %d",&n,&m);
  if (n >=0 && m >= 0 )
  {
      if(n >= m )
		{
		  if(n == 0 && m== 0)
			  printf("0");
		  else if(n == 1 && m == 0)
			  printf("0");
		  else
		     printf("%d",(n-1)*4 + 1);

		}
	  else
	  {
		  printf("%d",(m-1)*4 +2);
	  
	  }
  }

  else if(n < 0 && m >= 0 )
  {
     if (m >= abs(n))
		 printf("%d",(m-1)*4 +2);
	 else
	   printf("%d",(abs(n)-1)*4 +3);

  }
  else if(n <= 0 && m < 0)
  {  
	  if(m < n)
		  printf("%d",(-m)* 4);
	  else
		  printf("%d",(-n-1)*4+3);
     
  }
  else 
  {
     if (abs(m) >= n - 1)
		 printf("%d",(-m)*4);
	 else
		 printf("%d",(n-1)*4+1);
  }
return 0 ;
}
