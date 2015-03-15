// File Name: camelot.cpp
// Author: darkdream
// Created Time: 2014年04月07日 星期一 12时17分06秒
/*
ID: dream.y1
PROG: camelot
LANG: C++
*/
#include<vector>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<queue>

using namespace std;
int map[30][40];  //终点遍历标记

int mvalue[30][40];  //终点遍历值
int visit[30][40];  
int mvisit[30][40]; //knight 标记
int kans[30][40]; // 离 国王远近 
int n , m , num  = 1,px,py; 
struct node{
	int x;
	int y;
	node(){};
	node(int i ,int j )
	{
		x = i ; 
		y = j ; 
	}
	friend bool operator < (  node a,node b)
	{
		return kans[a.x][a.y] > kans[b.x][b.y];
	}
}a[10000],mnext[30][40];
typedef struct node1{
	int x,y,step;
}n1;
n1 list[10000] = {0};
int xadd[] = {2,2,-2,-2,1,1,-1,-1};
int yadd[] = {1,-1,1,-1,2,-2,2,-2};
int tans = 0 ; 
void bfs(int x,int y )
{
	memset(list,0,sizeof(list));
	map[x][y] = 1; 
	mvalue[x][y] = 0 ; 	
	int l = 1; 
	int r = 1; 

	list[l].x = x;
	list[l].y = y;
	list[l].step = 0 ; 

	while(l <= r )
	{
		priority_queue<node> q; // 优先队列，离国王进的为判定条件。
		int tempx ,tempy;
		for(int i = 0;i <= 7 ;i++)
		{
			tempx = list[l].x + xadd[i];
			tempy = list[l].y + yadd[i];
			if(tempx >= 1 && tempx <= n && tempy >= 1 && tempy <= m && !map[tempx][tempy])
			{
				q.push(node(tempx,tempy));
			}
		}

		while(!q.empty())
		{ 
			tempx = q.top().x;
			tempy = q.top().y;

			q.pop();	

			map[tempx][tempy] = 1; 
			r ++ ; 

			list[r].x = tempx ; 
			list[r].y = tempy;
			list[r].step = list[l].step +1;

			mvalue[tempx][tempy] =  list[r].step;
			mnext[tempx][tempy].x = list[l].x;
			mnext[tempx][tempy].y = list[l].y;
		}
		l ++; 
	}
}
int kxadd[] = {1,1,1,0,0,-1,-1,-1};
int kyadd[] = {-1,0,1,-1,1,-1,0,1};
void bans(int s)
{
	memset(list,0,sizeof(list));
	memset(visit,0,sizeof(visit));
	visit[a[s].x][a[s].y] = 1; 
	int l = 1; 
	int r = 1;

	list[l].x = a[s].x;
	list[l].y = a[s].y;
	list[l].step = 0 ; 
	while(l <= r )
	{
		for(int i = 0;i <= 7 ;i++)
		{

			int tempx = list[l].x + xadd[i];
			int tempy = list[l].y + yadd[i];
			if(tempx >= 1 && tempx <= n && tempy >= 1 && tempy <= m && !visit[tempx][tempy])
			{
				visit[tempx][tempy] = 1; 
				r ++ ; 
				list[r].x = tempx ; 
				list[r].y = tempy;
				list[r].step = list[l].step +1 ;
				kans[tempx][tempy] = list[r].step;
			}
		}
		l ++; 
	}
}

void bfsking(int s)
{
	memset(list,0,sizeof(list));
	memset(visit,0,sizeof(visit));
	visit[a[s].x][a[s].y] = 1; 
	int l = 1; 
	int r = 1;

	list[l].x = a[s].x;
	list[l].y = a[s].y;
	list[l].step = 0 ; 
	while(l <= r )
	{
		if(mvisit[list[l].x][list[l].y] || (list[l].x == px && list[l].y == py)  )
		{
			break;
		}
		for(int i = 0;i <= 7 ;i++)
		{

			int tempx = list[l].x + kxadd[i];
			int tempy = list[l].y + kyadd[i];
			if(tempx >= 1 && tempx <= n && tempy >= 1 && tempy <= m && !visit[tempx][tempy])
			{
				visit[tempx][tempy] = 1; 
				r ++ ; 
				list[r].x = tempx ; 
				list[r].y = tempy;
				list[r].step = list[l].step +1 ; 
			}
		}
		l ++; 
	}
	//	printf("%d %d %d\n",list[l].step,list[l].x,list[l].y);
	tans += list[l].step; 
}

void find(int x, int y)
{
	//printf(""x,y);
	if((x == px && y == py)  || mvisit[x][y])
		return ;
	mvisit[x][y] = 1;
	int tempx,tempy;
	tempx = mnext[x][y].x;
	tempy = mnext[x][y].y;
	find(tempx,tempy);
}
int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	scanf("%d %d",&m,&n);
	getchar();

	char c;
	scanf("%c %d",&c,&a[1].y);
	getchar();
	a[1].x = c -'A' + 1; 
	num = 2; 
	while(scanf("%c %d",&c,&a[num].y) != EOF)
	{
		getchar();
		a[num].x = c -'A' + 1; 
		num ++ ; 
	}
	num = num -1 ;


	bans(1);
	//printf("%d\n",num);
	int min = INT_MAX;
	for(px =1 ;px <= n;px ++)
	{
		py = 1; 
		for(py =1; py <= m ;py ++ )
		{  
			memset(mvalue,0,sizeof(mvalue));
			memset(map,0,sizeof(map));
			memset(mvisit,0,sizeof(mvisit));
			memset(mnext,0,sizeof(mnext));

			tans = 0;
			bfs(px,py);
			int isok = 1 ;
			mvisit[px][py] = 1;
			for(int i= 2;i <= num ;i ++)
			{
				if(!map[a[i].x][a[i].y])
				{
					isok = 0 ;
				}else {tans += mvalue[a[i].x][a[i].y];
					find(a[i].x,a[i].y);
				}
			}

			if(!isok)
				continue;
			bfsking(1);

			if(tans < min)
			{	
				min = tans ;
			}
		}

	}
	printf("%d\n",min);
	return 0 ;
}
