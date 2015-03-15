// File Name: b.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 12时15分47秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[1000007];
int a[1000007];
int b[1000007];

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%s",str);
   char *p;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   p = str;
   int t = 0 ;
   long long int sum = 0 ;
   while(strstr(p,"heavy")!=NULL)
   {
	   t++;
       a[t] = strstr(p,"heavy") - str ;
	   p = strstr(p,"heavy")+ 5;
	   
   }
   int k = 0 ;
   p = str;
   while(strstr(p,"metal") != NULL)
   {
	   k++;
       b[k] = strstr(p,"metal") - str ;
	   p = strstr(p,"metal") + 5;
   }
   int next = 1; 
   for(int i = 1; i<= t; )
   {
	  if(next == k +1) 
		  break;
      if(a[i] < b[next])
	  {
		  sum += k - next +1;
	      i ++ ;
	  }
	  else
		 next  ++;
   }
   printf("%I64d\n",sum);
return 0 ;
}
