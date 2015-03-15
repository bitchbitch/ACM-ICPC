// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月12日 星期六 21时33分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   for(int p =1 ; p <= t; p ++)
   {
	 int map[10][10];
	 int map1[10][10];
     int n , m; 
	 int hs[20];
	 memset(hs,0,sizeof(hs));
	 scanf("%d",&n);
	 for(int i = 1; i <= 4;i ++)
		 for(int j = 1; j <= 4; j ++)
		 {
		   scanf("%d",&map[i][j]);
		 }
	 scanf("%d",&m);
	 for(int i = 1;i <= 4;i ++)
		 for(int j = 1;j <= 4; j ++)
		 {
		    scanf("%d",&map1[i][j]);
		 }
	 for(int i = 1;i <= 4;i ++)
	 {
	    hs[map[n][i]] ++ ; 
		hs[map1[m][i]] ++ ; 
	 }
	 int time = 0 ; 
	 int ans = 0 ; 
	 for(int i = 1;i <= 16 ;i ++)
        if(hs[i] == 2)
		{ time ++ ; 
		  ans = i ; 
		}
     printf("Case #%d: ",p);
	 if(time == 1)
		 printf("%d\n",ans);
	 else if(time == 0 )
	     printf("Volunteer cheated!\n");
	 else printf("Bad magician!\n");
   }
return 0 ;
}
