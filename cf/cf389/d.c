// File Name: d.c
// Author: darkdream
// Created Time: 2014年02月04日 星期二 00时40分31秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[22];
int n ; 
int hs[23];
int map[1002][1002];
int sum = 3;
void solve(int d)
{
   int temp1[30];
   int temp2[30];
   int tn1 = 0;
   temp1[0] = 1;
   for(int i = 1;i <= d;i ++)
   {
         for(int j =0 ;j <= 19 ;j ++)
		 {
		    temp2[j] = sum +j;
		 }
		 sum += 20;
		 for(int j = 0 ; j <= tn1 ;j ++)
		  for(int s = 0 ;s <= 19 ; s ++)
		  {
		     map[temp1[j]][temp2[s]] = 1;
			 map[temp2[s]][temp1[j]] = 1; 
		  }
		 for(int j = 0 ;j <= 19 ;j ++)
		 { 
		   temp1[j] = temp2[j];
		 }
		 tn1 = 19 ;
   }

   for(int i = d+1; i <= 7 ;i ++)
   {
	  for(int j = 0 ;j <= tn1; j ++)
	  {
	     map[temp1[j]][sum] = 1; 
		 map[sum][temp1[j]] = 1;
	  }
	 tn1 = 0;
	 temp1[0] = sum; 
	 sum ++;
   }

   for(int i = 0 ;i <= tn1;i ++)
   {
      map[temp1[i]][2] = 1; 
	  map[2][temp1[i]] =1 ;
   }


}
int main(){
 
 memset(map,0,sizeof(map));
  a[1] = 1; 
 for(int i =2 ;i <= 7 ;i ++)
	 a[i] = a[i-1] * 20;
 scanf("%d",&n);
 for(int i = 7 ;i >= 1 ;)
 {
    if(n >= a[i])
	{
	 n = n - a[i];
	 solve(i-1);
	}else i --; 
 }
 sum --;
 printf("%d\n",sum);
 for(int i = 1;i <= sum ;i ++)
 {
   for(int j = 1;j <= sum ; j ++)
   {
     if(map[i][j])
		 printf("Y");
	 else printf("N");
   }
   printf("\n");
 }
 printf("%d\n",sum);
return 0 ;
}
