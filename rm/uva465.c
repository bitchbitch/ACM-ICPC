// File Name: uva465.c
// Author: darkdream
// Created Time: 2013年01月25日 星期五 20时41分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char stand[] = "2147483647";
char a[1000],b[1000];
void mu(int c[],int d[],int e[])
{
	int i ,j, k ,t ; 
	for (i =0 ;i < strlen(a) ;i ++)
	{
		int s = 0 ;
		for (j = 0 ; j < strlen(b) ;j++)
		{
			t = c[i]*d[j] +s +e[i+j] ;
			s = t / 10 ;
			e[i+j] = t % 10 ;
		}
		for (j = i+j  ; j< 550 ; j++)
		{
			t = e[j] + s;
			s = t /10 ;
			e[j] = t %10 ;
		}

	}


}
void add(int a[] , int b[])
{
	int i ;
	int s = 0 ;
	for (i = 0 ; i < 500 ;i ++)
	{
		int t  =  a[i] + b[i] +s;
		s =  t / 10 ;

		a[i] = t %10 ;

	}

}
int strle(char a[])
{
	int i ;
  for (i = 0 ;i < strlen(a) ;i ++)
	  if (a[i] != '0')
		  break;
  return  strlen(a) - i ;
  
}
int  than(char a[])
{
	if (strle(a) > strlen(stand))
		return 1 ;
	if (strle(a) == strlen(stand))
		if( strcmp(a,stand) >0)
			return 1;
		else
			return 0;
	if (strle(a) < strlen(stand))
	   return 0; 
}
void change(char a[], int b[])
{

	int i ;
	for (i = 0 ; i <strlen(a); i++)
		b[strlen(a) - i -1] = a[i] - '0';
}
void rechange(int a[], char b[])
{
	int i ; 
	for (i = 500 ; i >= 0 ; i-- )
		if (a[i] != 0)
			break;
	int j ;
	if (i == -1)
		b[0] = '0';
	else 
	for (j = 0 ; j <= i ; j++)
		b[j] = a[i-j] + '0';


}

int main(){
	int i ;
	int  c[1000],d[1000];
	int  e[1000]; 
	while(scanf("%s",a) != EOF)
	{
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		char temp[10];
		change(a,c);
		scanf("%s",temp);
		scanf("%s",b);
	   printf("%s %s %s\n",a,temp,b);
	  
		if (than(a))
			printf("first number too big\n");
	   if (than(b))
			printf("second number too big\n");
		change(b,d);
		if(strchr(temp,'+'))
		{
			add (c,d);
			memset(a,0,sizeof(a));
			rechange(c,a);
			if(than(a))
				printf("result too big\n");


		}

		if(strchr(temp,'*'))
		{
			mu(c,d,e);
			memset(a,0,sizeof(a));
			rechange(e,a);
			if (than(a))
				printf("result too big\n");
		}	 
	}
	return 0 ;
}
