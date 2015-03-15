// File Name: i.c
// Author: darkdream
// Created Time: 2014年05月14日 星期三 19时21分35秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char str[1000005];
int num[1000005];
int hs[30];
int ok()
{
	for(int i = 0 ;i <= 26; i ++)
		if(hs[i] >= 2)
			return -1;
	return 0 ; 
}
int main(){
	int m , l ; 

	while(scanf("%d %d",&m,&l)!= EOF)
	{
		memset(str,0,sizeof(str));
		scanf("%s",&str[1]);
		str[0] = '1';
		int len = strlen(str) - 1;
		memset(hs,0,sizeof(hs));
		memset(num,-1,sizeof(num));
		for(int i= 1;i <= l;i ++)
		{
			hs[str[i] -'a'] ++;
		}
		num[1] = ok();
		for(int i = l + 1;i <= len ; i ++)
		{
			hs[str[i] -'a'] ++ ; 
			hs[str[i-l] - 'a'] --;
			num[i-l+1] = ok();
		}
		/*for(int i = 1;i <= len ;i ++)
			printf("%d ",num[i]);
		printf("\n");*/
		int sum = 0; 
		for(int i = 1;i <= l; i ++)
		{
			int k = i ; 
			int tsum = 0 ; 
			while( k <= len)
			{
				if(num[k] != 0 )
				{	if(tsum >= m)
						sum += (tsum - m + 1);
					tsum = 0 ;
				}else tsum ++ ; 
				k += l; 
			}
			if(tsum >= m)
				sum += (tsum - m + 1);
		}
		printf("%d\n",sum);
	}
	return 0 ;
}
