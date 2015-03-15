// File Name: b.c
// Author: darkdream
// Created Time: 2014年02月11日 星期二 23时43分36秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
__int64 a[100005];
__int64 b[100005];
int main(){
 __int64 n ; 
 
 scanf("%I64d",&n);
 for(__int64 i = 1;i <=n; i ++)
 {
   scanf("%I64d",&a[i]);
 }
 for(__int64 i =1 ;i <= n;i ++ )
	 scanf("%I64d",&b[i]);
 __int64 joy = 0 ; 
 for(__int64 i = 1 ;i <= n; i++)
 {
     if(a[i] * 2 < b[i] || b[i] == 1)
		 joy -- ;
	 else{

		   joy += (b[i]/2 * (b[i] - b[i]/2));
	 }
 }
 printf("%I64d\n",joy);

return 0 ;
}
