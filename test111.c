// File Name: test111.c
// Author: darkdream
// Created Time: 2014年04月29日 星期二 19时05分56秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(){

	long long  sum = 0 ; 
	clock_t be ,en;
	be = clock();
	
	en = clock();
	printf("%ld\n",en-be);
	printf("%lld\n",sum);
return 0 ;
}
