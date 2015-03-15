// File Name: ratios.c
// Author: darkdream
// Created Time: 2014年02月27日 星期四 21时27分19秒
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
int a[4]; 
int map[5][5];
int ans[5][5];
struct node{
  int a,b ; 
}rans[10];
int gcd(int a, int b)
{
   if(a == 0 && b == 0 )
	   return 1; 
   return  b == 0 ? a : gcd(b,a%b);
}
int main(){
   // freopen("ratios.in","r",stdin);
//	freopen("ratios.out","w",stdout);
	scanf("%d %d %d",&a[1],&a[2],&a[3]);
	for(int i =1 ;i<= 3;i ++)
		for(int j = 1;j <= 3;j ++)
		{
		  scanf("%d",&map[i][j]);
		}
	int t = 0 ;
	for(int i = 1;i <= 3;i ++)
		for(int j = i + 1;j <= 3;j ++ )
		{
			    t++;
		     for(int s = 1;s <= 3; s ++)
			 {
				ans[s][t] = map[s][i] * a[j] - map[s][j]* a[i];
			 }
		}
	for(int i = 1;i <= 3;i ++)
	{
	  for(int j = 1;j < i;j ++)
	  {
	    int temp = ans[i][j];
		ans[i][j] = ans[j][i];
		ans[j][i] = temp;
	  }
	}
	for(int i = 1;i <= 3;i ++)
	{
	  for(int j = 1;j<= 3;j ++)
		  printf("%d ",ans[i][j]);
	  printf("\n");
	}
	memset(rans,0,sizeof(rans));
    for(int i = 1;i <= 3;i ++)
	 for (int j = i +1 ;j <= 3; j ++)
	 {
	     
         for(int ii = 1; ii <= 3;ii ++)
			 for(int jj = i+1; jj <= 3;jj ++)
			 {
				int tempp = 6 - ii - jj;
	            int tempa = ans[i][ii] * ans[j][tempp] - ans[j][ii] * ans[i][tempp];
	            int tempb = ans[i][jj] * ans[j][tempp] - ans[j][jj] * ans[i][tempp];  
                if(tempa == 0 &&  tempb == 0 )
					continue;
				if(4-tempp == 3 )
					printf("%d %d\n",tempa,tempb);
				tempa = abs(tempa);
				tempb = abs(tempb);
				int tempgcd = gcd(tempa,tempb);
			    tempa = tempa / tempgcd;
				tempb = tempb / tempgcd;
				rans[4 - tempp].a = tempb;
				rans[4 - tempp].b = tempa;
			 }
	 }
	for(int i = 1;i <=3 ;i ++)
	  {
	      printf("%d %d\n",rans[i].a,rans[i].b);
	  }
	
	int ta,tb,tgcd;
	tgcd =rans[1].a * rans[2].a /gcd(rans[1].a,rans[2].a);
	ta = tgcd/rans[1].a;
	tb = tgcd/rans[2].a;
	int x , y , z ,time;
	x = rans[1].a * ta; 
	y = rans[1].b * ta; 
	z = rans[2].b * tb;
	time = ( x * map[1][1] + y * map[2][1] + z * map[3][1])/a[1];
	printf("%d %d %d %d",x,y,z,time);
	
return 0 ;
}
