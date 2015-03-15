// File Name: b.c
// Author: darkdream
// Created Time: 2013年04月12日 星期五 19时41分39秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[1005];
int b[1005];
int n ;
void op1(int b[], long long int n  ) 
{
	int k = strlen(a);
	long long int temp = b[0];

	int  i  , j = 0  ,  s[1000], p = 0;
	for (i = 0 ;i < k ; i ++ )
	{   
		if (i >= 1)
			temp = temp *10
				+ b[i];

		if (temp >= n || p)
		{    if (temp < n)
			  s[j++] = 0 ;
			else 
			{
				s[j++] = temp / n;
				temp = temp % n ;
				p = 1;
			}
		}

    
	}
     
	/*if (j == 0)
		printf("0");
	else 
		for (i = 0; i < j  ; i++)
			printf("%d",s[i]);
   printf("\n");*/
	if(temp == 0 )
		printf("YES\n");
	else
		printf("%lld\n",temp);
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	while(scanf("%s %d",a,&n) != EOF)
	{
	  memset(b,0,sizeof(b));
		int k = strlen(a);
	   for(int i = 0 ;i < k ;i ++)
	   {
	     b[i] = a[i] - '0';
	   }
	 /*for(int i =  0 ;i < k ; i ++)
		 printf("%d",a[i]);
	 printf("\n");*/
     op1(b,n);
     memset(a,0,sizeof(a));
	}
	return 0 ;
}
