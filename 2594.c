// File Name: 2594.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 22时18分29秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
int map[1000][1000];
int visit[1000][1000];
char str[1000][1000];
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int xadd[] = {0,0,1,-1,0,0,1,-1};
int yadd[] = {1,-1,0,0,1,-1,0,0};
int n, m;
struct node{
	int  x , y ,k,last;
}list[1000*1000];
struct node1
{
	int x, y ;
}step[1000*1000];
int is(int x,int y)
{
	if(str[x][y] == '+')
		return 1; 
	return 0 ;
}
int main(){
	int t ;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d\n",&n,&m);
		n = n*2-1;
		m = m*2-1;
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		memset(step,0,sizeof(step));
		memset(list,0,sizeof(list));
		memset(str,0,sizeof(str));
		for(int i =1;i<= n;i ++)
		{
			gets(&str[i][1]);
			for(int j = 1;j <= m;j ++)
			{
				if(str[i][j] == '+' || str[i][j] == '|' || str[i][j] == '-')
					map[i][j] = 1; 
			}
		}
		list[1].x = n; 
		list[1].y = 1;
		list[1].last = 0 ; 
		list[1].k = 0 ; 
		int low = 1,high = 1 ;
		/*for(int i =1;i <= n;i ++)
		  {
		  for(int j = 1; j<=m;j++)
		  printf("%d ",map[i][j]);
		  printf("\n");
		  }*/
		while(low <= high)
		{
			if(list[low].x == 1 && list[low].y == m)
			{
				break;
			}
				for(int i = list[low].k ;i <= list[low].k+3; i++)
				{
					int tx = list[low].x + xadd[i];
					int ty = list[low].y + yadd[i];
					if(map[tx][ty] && !visit[tx][ty])
					{
						visit[tx][ty] = 1; 
						high ++;
						list[high].x = tx;
						list[high].y = ty;
						list[high].last = low;
						list[high].k = i % 4;  
					}
				}
			low++;
		}
		int k = 0;
		while(list[low].last)
		{
			k++;
			step[k].x = list[low].x;
			step[k].y = list[low].y;
			low = list[low].last;
		}
		/*	for(int i = k ;i >= 1; i --)
			{
			printf("%d %d\n",step[i].x,step[i].y);
			} */
		int ld,d;
		if(step[k].x == n-1)
		{
			printf("N\n");
			ld = 1; 
		}else{
			printf("E\n");
			ld = 2;
		}
		for(int i = k-1 ;i >= 1;i --){
			if(ld == 1)
			{
				if(step[i].x - step[i+1].x == -1)
				{
					d = 1;
					if(is(step[i+1].x,step[i+1].y))
						printf("F");
				}else if(step[i].y - step[i+1].y == 1){
						printf("R");
					d = 2; 
				}else {
						printf("L");
					d = 4;
				}
			}
			else if(ld == 2){
				if(step[i].y - step[i+1].y == 1)
				{
					d = 2;
					if(is(step[i+1].x,step[i+1].y))
						printf("F");
				}else if(step[i].x - step[i+1].x == 1){
						printf("R");
					d = 3; 
				}else {
						printf("L");
					d = 1;
				}

			}else if(ld == 3){
				if(step[i].x - step[i+1].x == 1)
				{
					d = 3;
					if(is(step[i+1].x,step[i+1].y))
						printf("F");
				}else if(step[i].y - step[i+1].y == 1){
						printf("L");
					d = 2; 
				}else {
						printf("R");
					d = 4;
				}


			}else {
				if(step[i].y - step[i+1].y == -1)
				{
					d = 4;
					if(is(step[i+1].x,step[i+1].y))
						printf("F");
				}else if(step[i].x - step[i+1].x == 1){
						printf("L");
					d = 3; 
				}else {
						printf("R");
					d = 1;
				}


			}
			ld = d;	
		}
		printf("\n");
		if(t != 0 )
			printf("\n");
	}
	return 0 ;
}
