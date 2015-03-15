// File Name: f.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 14时28分49秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#define maxn 200005
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);

int a[maxn];
int main(){
   int t; 
   scanf("%d",&t);
   while(t--)
   {
     int n;
     int sum = 0 ;
	 scanf("%d",&n);
	 while(n--)
	 {
	   int temp ;
	   scanf("%d",&temp);
	   sum += temp; 
	 }
	if(sum > 0 )
		printf("%d\n",sum);
	else printf("0\n");
   }

return 0 ;
}
