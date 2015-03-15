// File Name: uva575.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 16时24分11秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  char a[1000];
  while(gets(a))
  {
    int t = 0;
    if(a[0] == '0')
		break;
    for(int i = strlen(a)-1; i >=0 ;i --)
		t += (int)(a[i] -'0')*(pow(2.0,strlen(a) - i) -1);
    printf("%d\n",t);	
  }
return 0 ;
}
