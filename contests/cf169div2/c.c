// File Name: c.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 00时55分43秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[200001];
int b[200001];
int comp(const void *a , const void *b)
{
    return  *(int*)b - *(int*)a;
}
int main(){
  int n , m ;
  scanf("%d %d",&n,&m);
  for (int i = 0;i < n;i++)
  {
   scanf("%d",&a[i]);
  }
   memset(b,0,sizeof(b));
   __int64 sum  = 0 ;
   for(int i = 1;i <= m ;i++)
	{
	  int x, y ;
	  scanf("%d %d",&x,&y);
	  for( x;  x <= y ; x++)
		   b[x-1] ++;

	}
   
  qsort(a,n,sizeof(int),comp);
  qsort(b,n,sizeof(int),comp);

  for(int i = 0 ;i < n;i++ )
  { if(b[i] == 0)
	  break;
    sum += b[i]*a[i];
  }
 printf("%I64d",sum);

return 0 ;
}
