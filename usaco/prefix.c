// File Name: prefix.c
// Author: darkdream
// Created Time: 2013年12月11日 星期三 10时47分15秒
/*
ID: dream.y1
PROG: prefix
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long long hs[100000];
char s[200005];
int cmp(const void * a ,const void *b)
{
  return *(long long*)a - *(long long *)b;
}
int main(){
  //freopen("prefix.in","r",stdin);
  //freopen("prefix.out","w",stdout);
  char str[20];
  int  high = 0; 
  while(scanf("%s",str) != EOF)
  {
    int len = strlen(str);
	if(len == 1 && str[0] == '.')
		break;
	for(int i = 0 ;i < len ;i ++)
	{
	   long long temp = 0;
	   for(int j  = i  ;j < len ;j ++)
	   {
	      temp*= 26;
		  temp += str[i] - 'A';
		  high ++;
		  hs[high] = temp;
	   }
	}
  }
 qsort(hs+1,high,sizeof(long long int),cmp);
 for(int i =1;i <= high ;i ++)
	 printf("%lld\n",hs[i]);
  scanf("%s",s);
  int len = strlen(s);
  
return 0 ;
}
