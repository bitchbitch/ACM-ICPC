// File Name: 7.3.1.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 19时02分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
void  print_subset(int n , int *A , int cur)
{
   for(int i = 0 ;i < cur ;i ++ ) printf("%d ",A[i]);
   printf("\n");
   int s = cur?A[cur-1]+1:0;
   for(int i = s ;i < n;i ++)
   {
      A[cur] = i ; 
	  print_subset(n,A,cur+1);
   }
}
int a[100];
int main(){
  int n ;
  scanf("%d",&n);
  print_subset(n,a,0); 

return 0 ;
}
