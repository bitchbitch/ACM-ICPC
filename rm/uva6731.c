// File Name: uva6731.c
// Author: darkdream
// Created Time: 2013年05月15日 星期三 20时24分53秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[1000];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int a[1000];
	int b[1000];
	int t ;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 0 ;i < strlen(str); i++)
		{
			if(str[i] == '(') 
				b[i] = 1;
			else if(str[i] == ')')
				b[i] = -1;
			else if(str[i] == '[')
				b[i] = 2;
			else if(str[i] == ']')
				b[i] = -2;	
		}
		int j = 0 ;
		for(int i = 0; i < strlen(str);i++)
		{
			if(b[i] != 0)
			{
				if(b[i] + a[j] == 0 && b[i] < 0)
				{	  
					a[j] = 0;
						j--;

				}
				else
				{
					j++;
					a[j] = b[i];

				}
			}
		}
		if(a[1] == 0)
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0 ;
}
