// File Name: 7.2.2.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 08时19分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
void print_permutation(int n,int *P,int *A,int cur)
{
	int i , j; 
	if(cur == n)
	{
		for(int i = 0 ;i < n ;i ++) printf("%d ",A[i]);
		printf("\n");
	}else	
		for(i = 0;i < n;i ++)
		if(!i || P[i] != P[i-1])
		{
			int c1 = 0 ,c2 = 0;
			for(j = 0 ;  j < cur ; j ++) if(A[j] == P[i]) c1 ++ ;
			for(j = 0 ;j < n ; j ++) if(P[j] == P[i]) c2++;
			if(c1 < c2)
			{
				A[cur] = P[i];
				print_permutation(n,P,A,cur+1);
			}

		}

}
int a[100];
int b[100];
int main(){
	int n; 
	scanf("%d",&n);
	for(int i = 0  ;i <  n;i ++)
	{
		scanf("%d",&b[i]);
	}
	print_permutation(n,b,a,0);
	return 0 ;
}
