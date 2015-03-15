// File Name: game1.c
// Author: dartdream
// Created Time: 2014年04月07日 星期一 19时03分05秒
/*
ID: dream.y1
PROG: game1
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int a[400];
int main(){

	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	int n ; 
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	int ansa = 0 ; 
	int ansb = 0 ; 
	int t = n;
	if(n % 2 == 0 )
	{
		while(t != 0)
		{
			int suma = 0 ; 
			int sumb = 0 ; 
			for(int j = 1;j <= t  ;j ++)
			{
				if(j % 2== 0 )
					suma += a[j];
				else sumb += a[j];
			}
		//	printf("%d\n",t);
			if(suma > sumb)
			{

				ansa += a[t];
				a[t] = 0;
				if(a[1] > a[t-1])
				{
					ansb += a[1];
					a[1] = 0 ; 
				}else{
					ansb += a[t-1];
					a[t-1] = 0 ; 
				}
			}else {
				ansa += a[1];
				a[1] = 0;
				if(a[2] > a[t])
				{
					ansb += a[2];
					a[2] = 0 ; 
				}else{
					ansb += a[t];
					a[t] = 0 ; 
				}
			}

			t = 0 ; 
			for(int i = 1;i <= n;i ++)
			{
				if(a[i] != 0 )
				{
					a[++t] = a[i]; 
					if(i != t)
						a[i] = 0 ;
				}
			}
		}
		
	}else {
	    if(a[1] > a[t])	
			{
			  ansa += a[1];
			  a[1] = 0 ;
			}
		else {
		   ansa += a[t];
		   a[t] = 0 ;
		}
	
        t = 0 ; 
		for(int i = 1;i <= n;i ++)
			{
				if(a[i] != 0 )
					a[++t] = a[i]; 
				if(i != t)
						a[i] = 0 ;
			}

		while(t != 0)
		{
			int suma = 0 ; 
			int sumb = 0 ; 
			for(int j = 1;j <= t  ;j ++)
			{
				if(j % 2 == 0 )
					suma += a[j];
				else sumb += a[j];
			}
			if(suma > sumb)
			{

				ansb += a[t];
				a[t] = 0;
				if(a[1] > a[t-1])
				{
					ansa += a[1];
					a[1] = 0 ; 
				}else{
					ansa += a[t-1];
					a[t-1] = 0 ; 
				}
			}else {
				ansb += a[1];
				a[1] = 0;
				if(a[2] > a[t])
				{
					ansa += a[2];
					a[2] = 0 ; 
				}else{
					ansa += a[t];
					a[t] = 0 ; 
				}
			}

			t = 0 ; 
			for(int i = 1;i <= n;i ++)
			{
				if(a[i] != 0 )
					a[++t] = a[i]; 
				if(i != t)
						a[i] = 0 ;
			}
		}
	}
	
	printf("%d %d\n",ansa,ansb);
	return 0 ;
}
