// File Name: test2.c
// Author: darkdream
// Created Time: 2014年04月26日 星期六 22时28分20秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(){
    int a ;
	a = ~0U>>1;
	printf("%d\n",a);
	a = 1 << 31;
	printf("%d\n",a);
	a = 1 << 31;
	printf("%d\n",a);
    	
	return 0 ;
}
