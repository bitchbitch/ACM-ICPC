// File Name: radixsort.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 09时00分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#define maxn 10000
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int arr[maxn];
char str[maxn];
/*void radixsort(int *a,int n )
{
	int m = a[0],b[maxn],exp =1;
	for(int i = 1;i <= n;i ++){
		if(m < a[i])
			m = a[i]; 
	}
	while (m/exp > 0 )
	{
		int bucket[maxn] = {0};
		for(int i = 0 ; i < n ; i ++)
			bucket[(arr[i]/exp)%10] ++; 
		for(int i = 1; i < 10;i ++)
			bucket[i] += bucket[i-1];
		for(int i = n - 1; i >= 0 ; i --)
			b[--bucket[(arr[i]/exp)%10]] = arr[i];
		for(int i = 0 ;i < n;i ++)
			arr[i] = b[i];
		exp *= 10 ;  
	}


}*/
int cmp(const void * a ,const void * b)
{
  return *(int *)a -*(int *)b;
}
int main(){
	int n; 
	while(scanf("%s",str) != EOF)
	{
	   int n = -1 ,len = strlen(str); 
	   int temp = 0 ;
	   int flag = 0 ;
	   for(int i = 0 ;i <= len; i ++){
		  if(str[i] != '5'&& str[i]!= '\0'){
			 temp*= 10;
		     temp += (str[i] - '0');
			 flag = 1; 
		  }
		  else if(flag == 1){
			 arr[++n] = temp;
             temp = 0 ; 
			 flag = 0 ;
		  }
	   }
	
	   qsort(arr,n+1,sizeof(int),cmp);	
	   for(int i = 0; i <= n; i ++)
			printf(i == 0 ?"%d":" %d",arr[i]);
		printf("\n");
	    
	}
	return 0 ;
}
