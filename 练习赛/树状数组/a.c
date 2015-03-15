// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月22日 星期五 09时46分00秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int c[1000005], n ;
int lowbit (int x)
{
  return x&(-x);
}
int read(int x )
{
    int res = 0 ;
	while(x >= 1)
	{
	 res += c[x];
	  x -= lowbit(x);
	}
	return res;
}
int update(int x, int i)
{
    while(i <= n )
	{
	  c[i] += x;
	  i += lowbit(i);
	}
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   for(int k = 1;  k <= t; k ++)
   {
	  memset(c,0,sizeof(c));
	  scanf("%d",&n);
	  for(int i = 1; i<= n; i++)
	  {  int h;
		  scanf("%d",&h);
	    update(h,i);
	  }
        
	  getchar();
	  printf("Case %d:\n",k);
	  char d[10];
	  while(scanf("%s",d)!= EOF)
	  {
	    int a, b ;	
		if(d[0] == 'Q')
        {
			scanf("%d %d",&a,&b);
			getchar();
		    printf("%d\n",read(b) - read(a-1));
            
		}
		else if(d[0] == 'A')
	    {
			 scanf("%d %d",&a,&b);
             getchar();
			 update(b,a);
		}
		else if(d[0] == 'S')
		{
			 scanf("%d %d",&a,&b);
             getchar();
			 b = -b;
			 update(b,a);
		}
		else break;
	  }
       
	  
   }
return 0 ;
}
