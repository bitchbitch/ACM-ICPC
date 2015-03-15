// File Name: fracdec.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 12时18分27秒
/*
ID: dream.y1
PROG: fracdec
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[1000005];
int p[1000000];
int main(){
 freopen("fracdec.in","r",stdin);
  freopen("fracdec.out","w",stdout);
  int n ,m;
  memset(hs,-1,sizeof(hs));
  scanf("%d %d",&n,&m);
  int t = 0 ; 
  int  k =  printf("%d",n/m);
  //hs[n%m] = 0;
  n = (n % m) *10 ;
 // printf("\n%d\n",n);
  //printf("%d %d\n",n,hs[n]);
  while(hs[n] == -1 && n != 0)
  {
     t ++ ;
	 p[t] = n/m;
	 hs[n] = t; 
	 n = (n % m )* 10 ;
   	// printf("%d %d\n",n,hs[n]);
  }



  if(t == 0 )
	 printf(".0\n");
  else {
   printf(".");
   if(n == 0 ){
     for(int i =1 ;i <= t;i ++)
	 {	
		 printf("%d",p[i]);
		 if((k + i + 1) % 76 == 0 )
			 printf("\n");
     }
	if((t+k+1) % 76 !=0)
	printf("\n");
   }
   else{
     for(int j= 1;j <= hs[n]-1; j ++)
	 {	 printf("%d",p[j]);
	     if((k+j+1) % 76 == 0)
			 printf("\n");
	 }
	 printf("(");
	 if((hs[n] + k + 1) % 76 == 0)
		 printf("\n");
	 for(int j = hs[n] == 0?1:hs[n];j <= t ;j ++ )
	 {
		 printf("%d",p[j]);
	     if((k+j+2) % 76 == 0)
			 printf("\n"); 
	 }
	 if((t+2+k) % 76 != 0 )
	 printf(")\n");
   } 
  }
return 0 ;
}
