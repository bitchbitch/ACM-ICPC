// File Name: d.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 14时26分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000][1000];
int visit[1000][1000];
int xdd[]= {0,0,1,-1};
int ydd[] = {1,-1,0,0};
struct node
{
	int x, y ;
}list[1000005];

int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n; 
	while(scanf("%d",&n)!= EOF)
	{
		memset(a,0,sizeof(a));
		memset(list,0,sizeof(list));
		memset(visit,-1,sizeof(visit));
		a[500][500] = n;

		int low = 1 ; int high = 2;
		list[1].x = 500;
		list[1].y = 500;
		visit[500][500] = n;
		while(low !=  high)
		{ int temp;
			if(a[list[low].x][list[low].y] >= 4)
			{
		    	temp = (a[list[low].x][list[low].y] - a[list[low].x][list[low].y]%4)/4;
				a[list[low].x][list[low].y] = a[list[low].x][list[low].y]%4;
				visit[list[low].x][list[low].y] = -1;
			}
			else
			{
				low = (low+1) % 1000000;
				continue;
			}
			for(int i = 0;i < 4; i++)
			{
				int tx = list[low].x + xdd[i];
				int ty = list[low].y + ydd[i];
				a[tx][ty] += temp;
				if(a[tx][ty] >= 4)
				{   
					if(visit[tx][ty] == -1)
				    {
					list[high].x = tx;
					list[high].y = ty ;
					visit[tx][ty] = high;
					high = (high+1) % 1000000;
				
				    }
				}
			}
			low = (low+1)%1000000;
		}
	  int t ,k,b  ;
	  scanf("%d",&t);
      while(t--)
	  {
	    scanf("%d %d", &k, &b);
	    if(abs(k) > 500  || abs(b) > 500)
			printf("0\n");
		else
		{
		  printf("%d\n",a[500+k][500+b]);
		}
	  }
	}
	return 0 ;
}
