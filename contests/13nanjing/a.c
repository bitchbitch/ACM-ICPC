// File Name: a.c
// Author: darkdream
// Created Time: 2014年05月14日 星期三 18时11分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[1000005];
int main(){
	int  t;
	scanf("%d",&t);
	while(t--)
	{
		int n , m ;
		scanf("%d %d",&n,&m);
		scanf("%s",str);
		int len = strlen(str);
		int p =0 ; 
		while(p < len)
		{
			for(int i = 0;i <= m-1 ;i ++)
			{
				printf("%c",str[p+i]);
			}
			p += m ;
			printf("\n");
		}

	}
	return 0 ;
}
