// File Name: 10098.c
// Author: darkdream
// Created Time: 2013年07月11日 星期四 13时34分28秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int  cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}
int len;
char str[100] = {0};
int   dosomething(){

	int ok =0 ;
	int siti = 0 ;
	int sitj = 0 ; 
	for(int j = len -1; j >= 0 ;j --)
	{
		for(int i = len-1; i >= j ;i -- )
		{

			if(str[j] < str[i])
			{
				sitj = i ;
				siti = j ;
				ok = 1;
				break;
			}
		}
		if(ok)
			break;
	}
	if(ok == 0 )
	{
		return ok;
	}
	char temp = str[sitj];
	str[sitj] = str[siti];
	str[siti] = temp;
	qsort(str+siti+1,len-1-siti,sizeof(char),cmp);
	printf("%s\n",str);
	return ok; 
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--)
	{  
		memset(str,0,sizeof(str));
		scanf("%s",str);
		len = strlen(str);
		qsort(str,len,sizeof(char),cmp);
		printf("%s\n",str);
		while(dosomething());
		printf("\n");
	}
	return 0 ;
}
// 12343
//
