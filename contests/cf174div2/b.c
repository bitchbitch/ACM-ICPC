// File Name: b.c
// Author: darkdream
// Created Time: 2013年03月18日 星期一 00时18分32秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char a[200005];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; 
   scanf("%d",&n);
   getchar();
   int A ,F ,I, sum = 0;
   gets(a);
   A = F = I = 0;
   for(int i =0 ;i <  n; i++)
     {
	   if(a[i] == 'F')
		   F++;
	   if(a[i] == 'A' )
		   A++;
	   if(a[i] == 'I')
		   I++;
	 }
	   if(I == 0 && F != 0)
		   sum += A;
	   if(I != 0 )
		   sum += I;
   printf("%d",sum);
return 0 ;
}
