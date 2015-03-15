// File Name: 减法.c
// Author: darkdream
// Created Time: 2013年01月28日 星期一 11时20分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int cmp(char a[], char b[])
{
    if(strlen(a) > strlen(b))
		return 1;
	if(strlen(a) == strlen(b))
	{	if (strcmp(a,b) > 0 )
			return 1;
         else if (strcmp(a,b) == 0)
			 return 0;
		 else  return -1;
	} 
	return -1;
}
void sub(char a[], char b[],int t )
{
	int i ;
	int len = (strlen(a) > strlen(b))?strlen(a):strlen(b);  
    int *s;
	s = (int*)malloc(sizeof(int)*(len+1));
	for(i = 0 ; i < strlen(a)/2; i++)
	{
        char temp;
		temp = a[strlen(a) -i -1];
		a[strlen(a)-i-1] = a[i];
		a[i] = temp;
	}

	for(i = 0 ; i < strlen(b)/2; i++)
	{
        char temp;
		temp = b[strlen(b) -i -1];
		b[strlen(b)-i-1] = b[i];
		b[i] = temp;
	}
	for (i = 0 ;i <= len; i++)
	{
	  if (a[i] =='\0')
		  a[i] = '0';
	  if (b[i] == '\0')
		  b[i] = '0';
	}
	memset(s,0,sizeof(s));
	for (i = 0 ; i < len-1 ; i++)
	{
	   s[i] = s[i] + a[i] - b[i];
	   if (s[i] < 0 )
	   {
	      s[i] += 10 ;
          s[i+1]--;
	   }

	}
	s[i] = s[i]+ a[i] - b[i];
	if (!t)
		printf("-");

	
	while (len > 1 && s[len-1] ==0 )
		len = len -1;
	for (i = len - 1 ;i >=0; i--)
		printf("%d",s[i]);
}

int main(){
    char a[100];
	char b[100];
	gets(a);
	gets(b);
	if (cmp(a,b) == 0)
		printf("0\n");
	else if (cmp(a,b) > 0)
		sub(a,b,1);
	else sub(b,a,0);
return 0 ;
}
