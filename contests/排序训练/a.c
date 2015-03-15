// File Name: a.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 18时58分07秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[200];
int main(){
	int t ; 
	scanf("%d",&t);
	while(t--)
	{
		int n ;
		scanf("%d",&n);
		memset(hs,0,sizeof(hs));
		for(int i =1 ;i <= n;i++)
		{
			int temp ; 
			scanf("%d",&temp);
			hs[temp] ++; 
		}
		int ok = 0 ;
		for(int i = 0 ;i <= 100 ; i ++)
		{  while(hs[i])
			{
				if(ok)
				{
					ok++;
					printf("%d\n",i);
					break;
				}else ok = 1;
				hs[i]--;
			}
			if(ok == 2)
				break;
		}
	}
	return 0 ;
}
