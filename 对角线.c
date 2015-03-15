// File Name: 对角线.c
// Author: darkdream
// Created Time: 2013年12月03日 星期二 21时12分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int matrix[100][100];
int main(){
   int n; 
   scanf("%d",&n);
   for(int i = 1;i  <= n;i ++)
	   for(int j = 1 ;j <= n;j ++)
	   {
	     scanf("%d",&matrix[i][j]);
	   }
   int sum = 0 ;
   for(int i = 1;i <= n;i ++)
   {
     sum += matrix[i][i] + matrix[i][n-i+1];
   }
   printf("%d\n",sum);
return 0 ;
}
