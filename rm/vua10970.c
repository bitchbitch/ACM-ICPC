// File Name: vua10970.c
// Author: darkdream
// Created Time: 2013年02月19日 星期二 23时06分16秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

     int n , m ; 
	 while(scanf("%d %d",&n, &m )!=EOF)
	 {
	   printf("%d\n",n*(m-1)+n-1);
	 }
return 0 ;
}
