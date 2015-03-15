// File Name: 7.3.3.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 19时28分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);

void print_subset(int  n , int s)
{
 for(int i =  0 ;i < n;i ++)
	 if(s&(1<<i)) printf("%d ",i);
 printf("\n");
}
int main(){
 int n ; 
 scanf("%d",&n);
 for(int i = 1;i < (1 << n) ;i ++)
	 print_subset(n,i);

return 0 ;
}
