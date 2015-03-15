// File Name: maze1.c
// Author: darkdream	
// Created Time: 2013年12月13日 星期五 10时59分06秒
/*
ID:dream.y1
PROG: maze1
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[500][500];
struct node{
	int x,y;
}men[10];
int mennum = 0 ;
int max = -1;
struct dian{
	int x, y,s;
}a[100000];
int visit[500][500];
int xadd[5] = {1,-1,0,0};
int yadd[5] = {0,0,1,-1};
void bfs(int x,int y)
{ 
	memset(visit,0,sizeof(visit));
	int low,high;
	low =high = 1;
	a[low].x = x;
	a[low].y = y ; 
	a[low].s = 0 ; 
	visit[x][y] = 1; 
	while(low <= high)
	{
		for(int i =1;i <= mennum;i ++)
		{
			if(a[low].x == men[i].x && a[low].y == men[i].y)
			{
				if(a[low].s > max)
				{
					max = a[low].s;
			//		printf("%d %d %d\n",x,y,a[low].s);
				}
				return;
			}
		}
		for(int i= 0 ;i <= 3;i ++)
		{
			int tx = a[low].x + xadd[i];
			int ty = a[low].y + yadd[i];
			if(map[tx][ty] && !visit[tx][ty])
			{
				high ++;
				visit[tx][ty] =1 ;
				a[high].x = tx;
				a[high].y = ty;
				a[high].s = a[low].s +1;
			}
		}
		low ++;
	}
}
int main(){
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	int n , m; 
	scanf("%d %d",&m,&n);
	while(getchar()!='\n');
	char str[500];
	memset(map,0,sizeof(map));
	for(int i = 0;i <= 2*n ; i ++)
	{
		gets(str);
		int len = strlen(str);
			for(int j = 0 ;j <= 2*m;j ++)
			{
				if((i == 0 || i == 2*n || j == 0 || j == 2*m) && (str[j] == ' ' || str[j] == '\n' ||str[j] == '\0'))
				{
					mennum ++;
					men[mennum].x = i;
					men[mennum].y = j;
				}
				if(str[j] == ' '|| str[j] == '\n' || str[j] == '\0')
					map[i][j] = 1; 
			}

	}
	for(int i=1;i <=2 * n;i += 2)
	{
	  for(int j = 1;j <= 2*m;j += 2 )
	  {
	     bfs(i,j);
	  }
	}
	printf("%d\n",(max+1)/2);
	return 0 ;
}
