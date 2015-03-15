// File Name: e.c
// Author: darkdream
// Created Time: 2013年07月16日 星期二 16时34分57秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int visit[1000000];
int map[1000000];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n; 
	scanf("%d",&n);  
	memset(map,0,sizeof(map));
	memset(visit,0,sizeof(visit));
	map[1] = 0 ; 
	map[2] = 1;
	map[n+1] = 0 ; 
	map[n] = n/2;
	visit[1] = 1; 
	visit[0] = 1;
	visit[n/2] = 1;
	int ok = 1; 
	for(int i = n; i >2; i --)
	{
	  if(visit[(map[i] + n)/2] == 0)
		{
			visit[(map[i]+n)/2] = 1;
			if(map[i-1] != 0 )
			{
				ok = 0 ;
				break;
			}
			map[i-1] = (map[i]+n)/2;
		}
		else if(visit[map[i]/2] == 0 )
		{
			visit[map[i]/2] = 1;
			if(map[i-1] != 0 )
			{
				ok = 0 ;
				break;
			}
			map[i-1] = (map[i])/2;
		}
		else if (i == 3){
			int k = map[i]/2;
			int p = (map[i]+n)/2;
			if(map[2]  != k && map[2] != p )
			{ 
			  ok = 0 ;
			  break;
			}
		}
	  else {
	     ok = 0 ;
		 break;
	  
	  }
	}
	if(ok)
	{
		for(int i =1 ;i <= n+1; i++)
			printf("%d ",map[i]);
	}
	else printf("-1");
	printf("\n");

	return 0 ;
}
