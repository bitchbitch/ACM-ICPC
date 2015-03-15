// File Name: a.c
// Author: darkdream
// Created Time: 2013年05月19日 星期日 21时02分51秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int a[104] = {0};
   int b[104] = {0};
   int n;
   int is100,is10,is1,is0;
   is100  = is10 = is1 = is0 = 0 ;
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   int sum  = 0 ;
   for(int i = 1;i <= n;i ++)
   {
      if(a[i] == 0)
	  {
	     b[i] = 1;
		 is10 = 1;
		 sum++;
		 break;
	  
	  }
   }
   for(int i = 1;i <= n;i ++)
   {
   
	  if(a[i] == 100)
	  {
	    b[i] = 1;
		is100 = 1;
		sum++;
		break;
	  }
   }
   for(int i = 1;i <= n;i ++)
   {
	  if(a[i] %  10 == 0 && b[i] != 1)
	  {
	    b[i] = 1;
		is10 = 1;
		sum++;
		break;
	  }
   }
   for(int i = 1;i <= n;i ++)
   {
	  if(a[i] < 10 && b[i] != 1 )
	  {
	    b[i] = 1;
		is1 = 1;
		sum++;
		break;
	  }


   
   }
   if(is0 || is100 &&!is1 && !is10)
   {
     for(int i = 1;i <=n;i ++)
	 {
	    if(a[i] %10 != 0)
		{
		  b[i] = 1;
		  sum++;
		  break;
		}
	 }
   }
   printf("%d\n",sum);
   for(int i= 1; i  <= n;i ++)
   {
     if(b[i] == 1)
	{
	    printf("%d ",a[i]);
	}
   }
return 0 ;
}
