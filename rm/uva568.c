// File Name: uva568.c
// Author: darkdream
// Created Time: 2013年03月03日 星期日 16时44分48秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 10000
bool a[N+5];
int b[N];
int c[N];
int find()
{
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  for(int i = 2;i <= sqrt(N) ; i++)
  {
    if (a[i] == 0 )
	{
	   int t = i * i ;
	   while(t <= N )
	   {
	    a[t] = 1;
		t = t + i ;
	   }
	}
  }
  int t = 1 ;
  for(int i =  2; i <= N ;i ++)
	  if(a[i] == 0)
	   	  b[t++] = i ;
  return t-1;
}
int md(int k , int t)
{
   if(k == 1)
	   return b[t]%10;
   else
   {
     if (k %2 == 0)
		 return (md(k/2,t)%10)*(md(k/2,t)%10)%10;
	 else
		 return (md(k/2,t)%10)*(md(k/2,t)%10)*(b[t]%10)%10;
   }
}
int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int k = find();
  int n ;
  while(scanf("%d",&n) !=EOF)
  {
	 memset(c,0,sizeof(c));
     for (int i = 1;i <= k ;i ++)
	 {
		int temp = n , p = 0 ;
		while(temp / b[i]  >= 1)
		{	c[i] += temp /b[i];
		    temp = temp /b[i];
		}
	 }
	c[1] = c[1] - c[3];
	c[3] = 0;
	int p = 1; 
	for(int i = 1;i <= k ;i++)
      if (c[i] != 0)
		  p = (p * md(c[i],i))%10;
	printf("%5d -> %d\n",n,p);
  }
return 0 ;
}
