// File Name: c.c
// Author: darkdream
// Created Time: 2013年03月14日 星期四 00时54分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[1000005];
char b[1000005];
int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	gets(a);
	gets(b);
	if(strlen(a) == strlen(b)  && strlen(a) > 1)
	{
		int l = strlen(a);
		int t = 0 ,k = 0 ,h = 0;
		for(int i = 0 ;i < l ; i ++)
		{
			t = 0;
			
			if(a[i] != b[i])
			{
				k++;
				if(i >= 1)
				{
					if(a[i] !=a[i-1]) 
					{
						if(b[i] == b[i-1] && b[i] == '1')
							t = 1;
					}
					else
					{
						if(a[i] == '1')
						{
							if(b[i] != b[i-1])
								t = 1;
						}
						else
						{
							if(b[i] == b[i-1] && b[i] == '0')
								t = 1;
						}
					}
				}
				if (i < l-1)
				{


					if(a[i] !=a[i+1]) 
					{
						if(b[i] == b[i+1] && b[i] == '1')
							t = 1;
					}
					else
					{
						if(a[i] == '1')
						{
							if(b[i] != b[i+1])
								t = 1;
						}
						else
						{
							if(b[i] == b[i+1] && b[i] == '0')
								t = 1;
						}
					}


				}
				if(t == 0)
					h = 1;
			}
		}
		if(k == 0)
			printf("YES");
		else
		{
			if(!h)
				printf("YES");
			else
				printf("NO");
		}



	}
	else
	{
		printf("NO");

	}


	return 0 ;
}
