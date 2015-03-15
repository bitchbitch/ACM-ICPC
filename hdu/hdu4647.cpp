#include <string.h>
#include <stdlib.h>
#include <stdio.h>
const int maxn = 111111;
long long  a[maxn];
int  cmp(const void *a , const void * b)
{
   if( *(long long  *)a > *(long long *)b)
    return -1 ;
   if(*(long long *)a == *(long long *)b )
	   return 0 ; 
   if(*(long long *)a < *(long long *)b)
	   return 1; 
}
int main()
{
  int n , m ;
  //freopen("1005.in","r",stdin);

  while(scanf("%d %d",&n,&m) != EOF)
  {
     memset(a,0,sizeof(a));
     for(int i = 1;i <= n;i ++){
        scanf("%I64d",&a[i]);
        a[i] = a[i]* 2;
     }
     int t1,t2;
     long long t3;
     for(int i = 1;i <= m;i ++)
     {
       scanf("%d %d %I64d",&t1,&t2,&t3);
       a[t1] += t3;
       a[t2] += t3;
     }

     qsort(a+1,n,sizeof(long long ),cmp);
     long long sum = 0 ;
     int p = 0 ;
     for(int i = 1;i <= n; )
     {
       sum += (a[i] - a[i+1]);
       i = i + 2;

     }
     printf("%I64d\n",sum/2);
  }
  return 0 ;
}
