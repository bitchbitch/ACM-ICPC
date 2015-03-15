// File Name: uva10054.c
// Author: darkdream
// Created Time: 2013年06月16日 星期日 11时18分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[100];
int dmap[100][100];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t;
   scanf("%d",&t);
   for(int CASE = 1;CASE <= t; CASE ++)
   {
	 memest(map,0,sizeof(map));
     int n ,a,b  ;
	 scanf("%d",&n);

	 int ok = 1;
	 while(n--)
	 {
	   scanf("%d %d",&a,&b);
	   map[a]++;
	   map[b]++;
	 }
	 for(int i = 0 ;i <= 50 ;i ++)
	 {
	   if(map[i] % 2 == 1)
		   ok = 0;
	 }
	 if(ok!)
   }
return 0 ;
}
