// File Name: c.c
// Author: darkdream
// Created Time: 2013年05月19日 星期日 22时33分36秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[100004][101];

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int n; 
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	max = -1;
    j = 0;
	for(int i =1 ;i <= n;i ++)
    {
	   int temp;
        scanf("%d",&temp);
		if(temp > max)
		{
		   
		}
    }
	

	int k ,sum =0;
	for( k =100 ;k >= 0 ;k-- )
	{
	  if(a[k] != 0)
		  break;
	}

	for(; k >= 0 ;k--)
		if(a[k] == 0)
		{
		  sum++;
		}

	printf("%d\n",sum);
return 0 ;
}
