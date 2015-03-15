// File Name: f.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 20时57分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000005];
int b[1000005];
int c[1000005];
void is()
{
  a[1] = 1;
  for(int i = 2 ;i <= 1000; i ++)
  {
	  if(!a[i])
      {
	    int k = i*i;
		while(k <= 1000000)
		{
		    a[k] = 1;
			k= k+i;
		}
	  }
  }
  int sum = 1 ;
  for(int i = 1;i <= 1000000; i ++)
  {
    if(a[i] == 0)
	{
	  b[i] = sum;
	  sum++;
	}
  }
  for(int i = 2 ;i <= 1000 ;i ++)
   {
	   if(!a[i])
       for(int j = i ; j*i <= 1000000; j ++)
	   {
		   int k = j*i;
		   if(i > c[k]);
		     c[k] = i;
		   if(a[j] == 0  && j > c[k] )
			   c[k] = j ;
	   }
   }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(c,0,sizeof(c));
   is();
   b[1] = 0;
    int n ;
	while(scanf("%d",&n) != EOF)
	{
	  if(b[n])
	  {
	    printf("%d\n",b[n]);
	  }
	  else
	  {
	    printf("%d\n",b[c[n]]);
	  }
	}
return 0 ;
}
