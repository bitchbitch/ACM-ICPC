// File Name: c.c
// Author: darkdream
// Created Time: 2014年01月17日 星期五 23时51分56秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[100005];
int cmp(const void *a ,const void *b)
{
  return *(int *)a  - *(int *)b;
}
int ans[100005];
int main(){
   int n;
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&a[i]);
   if(n == 1)
   {
     printf("-1\n");
	 return 0 ;
   }
   qsort(a+1,n,sizeof(int),cmp);
   int min = a[2] - a[1];
   if(n == 2)
   {
     if((a[2]-a[1])% 2 == 0 )
	 {
	   if(a[2] - a[1] == 0 )
	   printf("1\n%d\n",a[2]);
	   else printf("3\n%d %d %d\n",a[1]- min,a[1] + min/2,a[2] + min);
	 }else {
	    printf("2\n%d %d\n",a[1] - min,a[2] + min);
	 }
	 return  0 ;
   }
   int ok = 1 ;
   int tempa,tempb;
   for(int i = 3; i <= n;i ++)
   {
	   //printf("%d**\n",min);
       if(a[i] != a[i-1] + min )
		{
          if(ok == 2)
		   { ok = 0 ;
		     break;
		   }
		  else if(ok == 1){
			ok = 2;
		    if(a[i] - a[i-1] == min/2  && i == 3)
			{
				if(min% 2 == 1)
					ok = 0 ; 
				tempa = a[i-1] - min/2;
				min = min/2;
			}
			else if(min == (a[i] - a[i-1])/2)
			{
			     if((a[i] - a[i-1]) % 2 == 1)
					 ok = 0; 
				 tempa = a[i-1] + min;
			}else ok = 0 ; 
		  }
		}
	   if(ok == 0 )
		   break;
   }
   if(ok != 1 )
   { 
	   if(ok == 0 )
	      printf("0\n");
	   else if(ok == 2)
		   printf("1\n%d\n",tempa);
   
   }
   else {
     if(min == 0 )
		 printf("1\n%d\n",a[1]);
	 else   printf("2\n%d %d\n",a[1] - min,a[n] + min);
	
   }

   
  
   
return 0 ;
}
