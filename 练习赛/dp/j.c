// File Name: j.c
// Author: darkdream
// Created Time: 2013年04月10日 星期三 16时15分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int f[200];
int c[105][105];
int main(){

  // freopen("/home/plac/problem/input.txt","r",stdin);
  // freopen("/home/plac/problem/output.txt","w",stdout);
  int n , v ;
  while(scanf("%d %d",&n,&v) != EOF ,n,v)
  {
    for(int i = 1;i <= n;i ++)
		for(int j =1;j <= v ;j++)
			scanf("%d",&c[i][j]);
	memset(f,0,sizeof(f));
	for(int i = 1;i <= n; i++)
		for(int j = v ;j >= 0 ;j --)
		{	int max = f[j];
			for(int t = 1 ;t<= j; t++ )
			{
			  if(f[j-t] + c[i][t] >max)
				  max = f[j-t]+c[i][t];
			}
			f[j] = max;
		}
   printf("%d\n",f[v]);
  }
return 0 ;
}
