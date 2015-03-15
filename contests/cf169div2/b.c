// File Name: b.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 23时44分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[10000];
int main(){
    int c[200] = {0};
	gets(a);
    for(int i = 0 ;i <  strlen(a); i++)
		c[a[i]] ++;
	int sum = 0;
	for(int i = 'a' ; i<= 'z' ;i++ )
		if(c[i]%2 == 1)
			sum++;
	if(sum %2 == 1)
		printf("First");
	else
		printf("Second");

return 0 ;
}
