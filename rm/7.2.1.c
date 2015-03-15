// File Name: 7.2.1.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 00时40分13秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
void print_permutation(int n, int *A,int cur)
{
	int i, j ;
	if(cur == n)
	{
		//for( i = 0 ;i < n;i ++) printf("%d",A[i]);
		//printf("\n");
	}else
		for(i = 1 ; i <= n;i++)
		{
			int ok = 1;
			for(j = 0 ;j < cur ; j ++)
				if(A[j] == i) 
				{ok = 0 ;
					break;
				}
			if(ok)
			{
				A[cur] = i ; 
				print_permutation(n,A,cur+1);
			}
		}
}
int a[1000];
int main(){
    int n =11;
	print_permutation(n,a,0);

	return 0 ;
}
