// File Name: uva10562.c
// Author: darkdream
// Created Time: 2013年05月22日 星期三 12时35分22秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[300][300];
int deap;
void find (int u , int p , int k )
{
	printf("(");
	if(k > deap)
		return;
	for(int i = u; i <= p && i < strlen(str[k]); i ++)
	{
		if(str[k][i] != ' ')
		{  
			printf("%c",str[k][i]);
			if(str[k+1][i] == '|')
			{
				int l = i , r = i ;
				for(; l >= 0 ;l--)
				{
					if(str[k+2][l] != '-')
						break;
				}
				for(; r <strlen(str[k+2]) ;r++)
				{
					if(str[k+2][r] != '-')
						break;
				}
				find(l+1,r-1,k+3);
			}
			else printf("()");
		}

	}
	printf(")");

}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{ 
		int i ;
		deap = 0;
		memset(str,0,sizeof(str));
		for( i = 1;; i ++)
		{
			gets(str[i]);
			if(strlen(str[i]) == 1 && str[i][0] == '#')
			{
				i = i -1;
				break;
			}
		}
		deap = i ;
		if(i == 0)
			printf("()\n");
		else
	    {
			find(0,strlen(str[1])-1, 1);
			printf("\n");
		}

	}
	return 0 ;
}
