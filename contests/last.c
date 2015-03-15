// File Name: last.c
// Author: darkdream
// Created Time: 2013年09月15日 星期日 16时28分29秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
#define maxn  200005
int a[maxn];
int b[maxn];
int main(){
  int n ;
  long long ans = 0 ;
  while(scanf("%d",&n) != EOF)
  {
	memset(b,-1,sizeof(b));
    for(int i = 1;i <= n;i ++)
	{
	    scanf("%d",&a[i]);
		b[a[i]] = i;
		int left = i ; 
		for(int j = 0; j <=n + 1;j ++)
		{
		   if(b[j] != -1)
		   {
		      if(b[j] >= left)
			  {
				  continue;
			  }
			  else {
			    //ans += j *(left-b[j] +1);
				left = b[j];
			  }
		   }else {
		     ans = left * j;
		   }
		}
		printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
  }

return 0 ;
}
