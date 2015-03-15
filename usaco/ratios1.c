// File Name: ratios1.c
// Author: darkdream
// Created Time: 2014年03月18日 星期二 08时33分08秒
/*
ID: dream.y1
PROG: ratios
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int ans[5];
int a[4][4];
int stand[4];
int sum = INT_MAX;
int gcd(int a, int b )
{
  if(a == 0 && b == 0 )
	  return 1;
  return  b == 0 ? a:gcd(b,a%b);
}
int main(){

   freopen("ratios.in","r",stdin);
   freopen("ratios.out","w",stdout);
    for(int i =1 ;i <= 3; i++)
		scanf("%d",&stand[i]);
	for(int i = 1;i <= 3;i ++)
		 for(int j = 1;j <= 3;j ++)
		 {
		     scanf("%d",&a[i][j]);
		 }
    int bok = 0 ;
	for(int i = 0;i <= 100;i ++)
		for(int j = 0;j <= 100; j ++)
			for(int ij = 0;ij <= 100 ;ij ++)
			{
				if(!(i || j || ij))
					continue;
			   int temp[4];
			   temp[1] = i * a[1][1] + j * a[2][1] + ij * a[3][1];
			   temp[2] = i * a[1][2] + j * a[2][2] + ij * a[3][2];
			   temp[3] = i * a[1][3] + j * a[2][3] + ij * a[3][3];
			   int  ok = 0 ; 
			   int pp;  
				for(int ji =1;ji <= 3;ji ++)
					 if(stand[ji] != 0 && temp[ji] / stand[ji] != 0)
			             pp = temp[ji]/ stand[ji];
				for(int  ji = 1;ji <= 3;ji ++)
					if(stand[ji] *pp != temp[ji])
					{
					   ok = 1; 
					   break;
					}
			//  if(i == 2 && j == 0  && ij == 1)
			//	   printf("%d %d %d\n",temp[1],temp[2],temp[3]);
			   if(!ok)
			   {
				 bok = 1; 
			     int tsum  = i + j + ij;
				 if(tsum < sum )
				 {
				   sum = tsum; 
				   ans[1] = i ; 
				   ans[2] = j ; 
				   ans[3] = ij;
				   ans[4] = pp;
				  }
			   }

			}
	if(bok)
	{
	for(int i = 1;i <= 4;i ++)
		printf(i == 1?"%d":" %d",ans[i]);
	  printf("\n");
	}
	else printf("NONE\n");
return 0 ;
}
