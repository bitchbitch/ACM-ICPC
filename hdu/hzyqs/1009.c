// File Name: 1009.c
// Author: darkdream
// Created Time: 2013年08月10日 星期六 13时00分27秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int n  ,m; 
char str[50];
struct nodeH
{
	int x, y ; 
}H[2000],C[2000];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	while(scanf("%d %d",&n,&m) != EOF)
	{

	    if(n == 0 && m == 0 )
		 break;
		int kh1 = 0 ,kc1 = 0 ;
		for(int i = 1; i <= n;i ++)
		{
			scanf("%s",&str[1]);
			for(int j = 1; j<= m;j ++)
			{
				if(str[j] == 'H')
				{
					kh1 ++ ;
					H[kh1].x = i ; 
					H[kh1].y = j; 
				}
				else if(str[j] == 'C')
				{
					kc1 ++ ;
					C[kc1].x = i ; 
					C[kc1].y = j; 
				}


			}
		}
		int max = 5000;
		int anshi,anshj,ansci,anscj;
		for(int i =1 ;i <= kh1;i ++)
		{
			for(int j = 1; j<= kc1 ; j ++)
			{
				int temp = abs(H[i].x-C[j].x) + abs(H[i].y - C[j].y) ;
				if(temp < max)
				{
					max = temp ; 
					anshi = H[i].x;
					anshj = H[i].y;
					ansci = C[j].x;
					anscj = C[j].y;
				}
			}
		}

      printf("%d %d %d %d\n",anshi-1,anshj-1,ansci-1,anscj-1);
	}
	return 0 ;
}
