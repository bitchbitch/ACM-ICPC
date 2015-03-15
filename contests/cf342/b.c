// File Name: b.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 17时16分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int is(int i , int j )
{
	if(i == j )
		return 1;
	else return 0 ;
}
struct node {
  int st,l,r;
}hehe[1000000];
int main(){
	int n ,m ,s ,f ; 
	scanf("%d %d %d %d",&n,&m,&s,&f);
	int ts = 0 ; 
	int l , r, st;

	if(f > s )
	{
		int laststep = f - s ;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&hehe[i].st,&hehe[i].l,&hehe[i].r);
		}
		for(int i =1 ;i <= m;i ++)
		{
			st = hehe[i].st ;
			l = hehe[i].l;
			r = hehe[i].r;
			for(int i = ts ; i <= st - 2 ; i ++)
			{
				printf("R");
					laststep -- ;
				s ++;
				if(is(s,f))
					return 0;
			}
			if((s <= r && s >= l) || (s+1 >= l && s +1 <= r ))
			{
				printf("X"); 
			}
			else
			{    
				laststep --;
				s ++;
				printf("R");
				if(is(s,f))
					return 0;
			}
			ts = st;
		}
		while(laststep--)
		{
		   printf("R");
		}
	}else {
		int laststep = s - f ;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&hehe[i].st,&hehe[i].l,&hehe[i].r);
		}
		for(int i =1 ;i <= m;i ++)
		{
			st = hehe[i].st ;
			l = hehe[i].l;
			r = hehe[i].r;
			for(int i = ts ; i <= st - 2 ; i ++)
			{
				printf("L");
					laststep -- ;
				s --;
				if(is(s,f))
					return 0;
			}
			if((s <= r && s >= l) || (s-1 >= l && s -1 <= r ))
			{
				printf("X"); 
			}
			else
			{    
				laststep --;
				s --;
				printf("L");
				if(is(s,f))
					return 0;
			}
			ts = st;
		}
		while(laststep--)
		{
		   printf("L");
		}


	}
	return 0 ;
}
