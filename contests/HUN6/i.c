// File Name: i.c
// Author: darkdream
// Created Time: 2013年07月20日 星期六 10时59分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int sum[100005];
struct Zeng
{
  int x,y,value;
}zeng[200005],fang[200005];
int cmp{ const void * a,const void * b}
{
   return (*(Zeng)*a).x - (*(Zeng *)b).x;
}
int cmp1{const voi}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n,m;
   while(scanf("%d %d",&n,&m) != EOF)
   {
	 memset(sum,0,sizeof(sum));
     for(int i = 2 ;i<=n;i ++)
	 {
		 scnaf("%d",sum[i]);
	     sum[i] = sum[i-1] + sum[i];
	 }
	 int tx, ty,tvalue;
	 int zen = 0 ;
	 int fan = 0 ;
	 for(int m = 1;m <= n;m ++)
	 {
	    scanf("%d %d %d",&tx,&ty,&tvalue);
		if(tx > ty)
		{
		  zen ++;
		  zeng[zen].x = tx;
		  zeng[zen].y = ty;
		  zeng[zen].value = tvalue;
		  
		}
		else
		{
		  fan ++;
		  fang[fan].x = tx;
		  fang[fan].y = ty;
		  fang[fan].value = tvalue;
		}
	 }
   }
return 0 ;
}
