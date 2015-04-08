// File Name: hdu3436.pb_ds.cpp
// Author: darkdream
// Created Time: 2015年04月07日 星期二 14时26分13秒


#include<stdio.h>
int ans[100];
int n ; 
int main()
{
	printf("Enter a number: ");
    scanf("%d",&n);
	int tt = 0 ; 
	while(n)
	{
	   tt ++ ; 
	   ans[tt] = n % 10 ;
	   n/= 10;
	}
	printf("The  encrypted  number  is  %d%d%d%d",(ans[2]+9)%10,(ans[1] +9)%10,(ans[4] + 9)%10,(ans[3]+9)%10);
	return 0 ;
}
