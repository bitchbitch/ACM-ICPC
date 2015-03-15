// File Name: lanqiao.c
// Author: darkdream
// Created Time: 2014年03月11日 星期二 20时30分11秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int temp;
int hs[2000];
char str[1000000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n ;
  memset(hs,0,sizeof(hs));
  scanf("%d",&n);
  getchar();
  int max = -1, min = 1e8;
  int a, b ; 
  for(int i =1 ;i <= n;i ++)
  {
    gets(str);
	char *p = str;
	while(sscanf(p,"%d",&temp) != EOF)
	{
     
	char str1[100];
	 sscanf(p,"%s",str1);
	 int len = strlen(str1);
	 p = strstr(p,str1)+ len ;
	// puts(p);
//	printf("%d\n",temp);
	if(temp < min )
		min = temp;
	if(temp > max )
		max = temp;

	if(hs[temp])
		b = temp;
    hs[temp] ++; 
	   
	}
  }
  for(int i = min;i <= max; i ++)
	  if(!hs[i])
		  a = i ; 
  printf("%d %d\n",a,b);
return 0 ;
}
