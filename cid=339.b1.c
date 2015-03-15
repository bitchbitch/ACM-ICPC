#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MIN(a,b) (a)<(b)?(a):(a)
#define MAX(a,b) (a)>(b)?(a):(b)

const int N = 100110;
int rope[N],n,c[N],num[N];

int lowbit (int x)
{
 return x&(-x);
}

int read(int x)
{
   int res = 0 ;
   while (x >= 1)
   {
     res += c[x];
	 x -= lowbit(x);
   }
   return res;
}

void update(int x)
{
   while (x <= N)
   {
    c[x] += 1  ;
     x += lowbit(x);
   }
   
}
int main()
{
  int t ;
  scanf("%d",&t);
  while (t--)
  {
    int n ;
	memset(c,0,sizeof (c));
	memset (num, 0 , sizeof (num));
	scanf("%d",&n);
	int  i, j , k, max = 0;
	for (i = 1; i <= n ; i++)
	   {
	     scanf("%d",&rope[i]);
		 update(rope[i]);
		 num[rope[i]]++;
         max = MAX(max,rope[i]);

	   }
	int ans = n ; 
	for (i = 1; i <= max ; i ++)
	{
	  if (num[i]>0)
	  {
	      int x =ceil(i/2.);
		  ans = MAX(ans ,(read (max) - read(x-1) +num[i]));  
	  }
	}
	printf("%d\n",ans);
  }
  return 0 ;
}
