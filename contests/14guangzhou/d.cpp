// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年09月20日 星期六 13时39分38秒

#include<vector>
#include<list>
#include<map>
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
#define LL long long

using namespace std;
int n , m ;
int visit[120][120];
char str[150];
struct node{
	int x, y;
	int step;
}lis[10050],fc[10050],fc1[10050];
int mp[120][120];
int xadd[] = {0,0,1,-1};
int yadd[] = {1,-1,0,0};
int ans = 0 ;
int tmpsnake;
void find(int next,int limits)
{
	int l = 1 ; 
	int r = 1 ; 
	lis[l].x = 110 ; 
	lis[l].y = 110 ;
	lis[l].step = fc[0].step-1;
	memset(visit,0,sizeof(visit));
	int tt = 0 ; 
	int ttc = 0;
	/*for(int i = 0 ;i <= limits;i ++)
	{
	  printf("%d %d  %d *** ",fc[i].x,fc[i].y,fc[i].step);
	}
	printf("********%d\n",next);*/
	while(l <= r )
	{
      //  printf("%d\n",l);
		if(ttc <= limits)
		{
			while(fc[ttc].step == lis[l].step +1)
			{
					r ++ ;
					lis[r] = fc[ttc];
					visit[lis[r].x][lis[r].y] = 1;
					ttc ++;
			        if(ttc > limits)
				       break;
			}
		}//  fc

		if(mp[lis[l].x][lis[l].y] ==  next)
		{ 
			node temp;
			temp.x = lis[l].x ; 
			temp.y = lis[l].y ;
			temp.step = lis[l].step;
			fc1[tt] = temp;
		    tt ++ ;
		}
		for(int i = 0 ;i <= 3;i ++)
		{
			int tx = lis[l].x + xadd[i];
			int ty = lis[l].y + yadd[i];
			if(!visit[tx][ty] && mp[tx][ty] != -1)
			{
				visit[tx][ty] = 1;
				r ++ ;
				lis[r].x = tx;
				lis[r].y = ty ;
				lis[r].step = lis[l].step + 1;
			}
		}
		l ++ ;
	}
	//printf("&&&&&&&& %d\n",tt-1);
	if(next == m+1)
	{
		for(int i = 0 ;i <= tt - 1;i ++)
		{
		   ans = min(fc1[i].step + tmpsnake,ans);
		 // printf("%d\n",fc1[i].step);
		}
//		printf("\n\n\n");
        return ; 	
	}else {
	   if(tt == 0 )
		   return;
       memcpy(fc,fc1,sizeof(fc1));
	   find(next+1,tt-1);
	}
}
int main(){
     //freopen("out","w",stdout);
	while(scanf("%d %d",&n,&m) != EOF)
	{
		if(n == 0 && m == 0 )
			break;
		int bex ,bey ; 
		
		memset(mp,-1,sizeof(mp));
		ans = 1e9;
	    int numsnake = 0;
		node snake[10];
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",&str[1]);
			for(int j = 1;j <= n;j ++)
			{
				if(str[j] == 'S')
				{
				   numsnake ++ ;
				   snake[numsnake].x = i ; 
				   snake[numsnake].y = j; 
				}else if(str[j] == '.')
				{
					mp[i][j] = 0 ; 
				}else if(str[j] == '#')
				{
					mp[i][j] = -1;
				}else if(str[j] == 'K')
				{
					mp[i][j] = 0 ; 
					bex = i ; 
					bey = j ;
				}else if(str[j] == 'T')
				{
					mp[i][j] = m+1;
				}else{
					mp[i][j] =  str[j] - '0';    

				}
			}
		}
		int status = (1 << numsnake) - 1;
		for(int i = 0 ;i <= status ;i ++)
		{
		  tmpsnake = 0 ;
		  int tt = 1;
          int kk = i ;
		  while(kk)
		  {
		      if(kk & 1)
			  {
			      tmpsnake ++ ;
				  mp[snake[tt].x][snake[tt].y] =0;
			  }else{
				  mp[snake[tt].x][snake[tt].y] = -1;
			  }
			  kk >>= 1 ;
			  tt ++ ;
		  }
		  node temp;
		  temp.x = bex;
		  temp.y = bey ;
	      temp.step = 0;
		  fc[0] = temp;
		  find(1,0);
		}
		if(ans == 1e9)
			printf("impossible\n");
		else 
		printf("%d\n",ans);
	}
	return 0;
}
