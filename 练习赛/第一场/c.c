// File Name: c.c
// Author: darkdream
// Created Time: 2013年04月11日 星期四 19时08分32秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n , m ;
int a[20005];
int lowbit(int x)
{
  return x&(-x);
}
int sum(int x)
{
  int res =0 ;
  while(x >= 1  )
  {
      res += a[x];
	  x -= lowbit(x);

  }
  return res;
  
}
void update(int x,  int i  )
{
    while(x <= n)
	{
	   a[x] += i;
	   x += lowbit(x);
	}
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   while(scanf("%d %d",&n,&m) != EOF)
   {
	    memset(a,0,sizeof(a));
        int u,p;
		for(int i = 1;i <= m ;i++)
		{
		  scanf("%d %d",&u,&p);
		  if(u >p)
		  {
		    int temp = u ;
			u = p ;
			p = temp;
		  }
		  update(u,1);
		  update(p,-1);

		}
		//for(int i = 1;i <= n; i++)
		//	printf("%d ",a[i]);
		int sum1= 0;
		for(int i = 1 ; i<= n; i ++)
		{
		  if(sum(i) <= 0)
			  sum1++;
		}

		printf("%d\n",sum1);
   }
return 0 ;
}
