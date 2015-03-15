// File Name: e.c
// Author: darkdream
// Created Time: 2013年07月17日 星期三 09时41分24秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[10000];
int visit[10000];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n, a , b; 
	while(scanf("%d %d %d",&n,&a,&b) != EOF)
	{
		memset(str,0,sizeof(str));
		scanf("%s",str);
		int suma = 0 ;
		int sumb = 0 ;
		int sum = 0 ;
		int i,j;
		for(i = 0 ;i < n;i ++)
		{
			if(str[i] == '0')
			{
				if(suma != a )
					suma ++;
				else 
					break;
			}


		}
		for(j =0 ;j < n;j ++)
		{
			if(str[j] == '1')
			{
				if(sumb != b)
					sumb ++;
				else break;

			}

		}
		for(; i < n;i ++)
		{
			if(str[i] == '0')
			{
				if(sumb == b)
				{	str[i] = '2';
				    sum ++;
				}
				else
				{	
					sum++;
					str[i] = '1';
					sumb ++;
				}
			}
		}
		for(; j < n; j++)
		{
			if(str[j] == '1')
			{
				if(suma == a)
				{
				  sum ++;
				 str[j] = '2';
				}
				else
				{
					sum ++;
					str[j] = '0';
					suma ++;
				}
			}
		}
		for(i = 0 ;i < n;i ++)
		{
			if(str[i] == '2')
			{ 
			  if(sumb < b)
				{
					sum ++;
					str[i] = '1';
					sumb ++;
					continue;
				}

				if(suma < a)
				{
					sum ++;
					str[i] = '0';
					suma ++;
					continue;
				}
			}
		}

		if(a + b  > n )
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",sum);
			printf("%s\n",str);
		}
	}
	return 0 ;
}
