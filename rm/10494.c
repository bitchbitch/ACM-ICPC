// File Name: 10494.c
// Author: darkdream
// Created Time: 2013年01月28日 星期一 19时07分49秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[1000];
long long int n ;
void change(char a[],int b[])
{ int i ;
	for (i = 0 ;i < strlen(a) ; i++ )
		b[i] = a[i] - '0';

}
void op1(int b[], int t , long long int n  )
{
	int k = strlen(a);
	long long int temp = b[0];

	int  i  , j = 0  ,  s[1000], p = 0;
	for (i = 0 ;i < k ; i ++ )
	{   
		if (i >= 1)
			temp = temp *10 + b[i];

		if (temp >= n || p)
		{	if (temp < n)
			s[j++] = 0 ;
			else 
			{
				s[j++] = temp / n;
				temp = temp % n ;
				p = 1;
			}
		}


	}
	if (t == 1)
	{
		if (j == 0)
			printf("0");
		else 
			for (i = 0; i < j  ; i++)
				printf("%d",s[i]);

	}else
		printf("%lld",temp);
	printf("\n");





}

int main(){
	while (scanf("%s",a) != EOF)
	{
		char temp[10];
		int  b[1000];
		change(a,b);
		long long int ans;
		scanf("%s",temp);
		scanf("%lld",&n);
		if (strchr(temp,'/'))
			op1(b,1,n);
		else 
			op1(b,2,n);



	}

	return 0 ;
}
