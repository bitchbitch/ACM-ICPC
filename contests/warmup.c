// File Name: warmup.c
// Author: darkdream
// Created Time: 2013年09月08日 星期日 12时28分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[300][300];
int main(){
     int k =  0;
	 int te = 0 ;
	 int td = 0 ;
     memset(a,0,sizeof(a));
	 for(int i = 3 ;i <= 10;i ++)
	 {
	   te  = td + 1; 
       td  = td + i;
	   for(int j = te ;j <= td; j ++)
	   {
	       k ++ ;
		   a[j][1] = k;
	   }
	   for(int j = td - 1; j >= te +1 ; j --)
	   {
		  k ++;
	      a[j][td -j +1] = k ; 
	   }
	   for(int j = te ;j <= td ; j++)
	   {
	     k ++ ;
		 a[j][i] = k ; 
	   }
	 
	 }
	 for(int i = 1;i <= 100;i ++)
	 {
	   int j = 30;
	   for(; j >= 0 ; j --)
		{
		  if(a[i][j] != 0 )
			  break;
		}
	   if(j == -1)
		   break;
	   for(int t = 1;t <= j ; t ++ )
	   {
	      if(a[i][t] == 0 )
              printf(" ");
		  else printf("%c",(a[i][t]-1)%26 + 'a');
	   
	   }
	   printf("\n");
	 }

return 0 ;
}
