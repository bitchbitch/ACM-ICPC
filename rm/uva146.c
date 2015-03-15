// File Name: uva146.c
// Author: darkdream
// Created Time: 2013年07月11日 星期四 10时48分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a , const void *b)
{
	return *(char *)a -*(char *)b;
}
char str[100];

int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	while(scanf("%s",str) != EOF)
	{
		if(strlen(str) == 1 && str[0] == '#')
			break;
		int ok =0 ;
		int len = strlen(str);
		int siti = 0 ;
		int sitj = 0 ; 
		for(int j = len -1; j >= 0 ;j --)
		{
			for(int i = j; i >= 0 ;i -- )
			{
				if(str[i] < str[j])
				{
					sitj = j ;
					siti = i ;
					ok = 1;
					break;
				}
			}
			if(ok)
				break;
		}
		if(ok == 0 )
		{
			printf("No Successor\n");
			continue;
		}
		char temp = str[sitj];
		str[sitj] = str[siti];
		str[siti] = temp;
		qsort(str+siti+1,len-1-siti,sizeof(char),cmp);
		printf("%s\n",str);

	}

	return 0 ;
}
