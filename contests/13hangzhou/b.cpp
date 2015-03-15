// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年05月06日 星期二 19时03分57秒

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

using namespace std;
int n , m;
struct node{
  int x, y ,s;
}LIST[10005];
int visit[104][104];
int MAP[104][104];
struct node1{
  int x, y ; 
}a[10];
int xadd[] = {0,0,1,-1};
int yadd[] = {1,-1,0,0};
int ok = 1;
int bfs(int bx, int by ,int ex,int ey)
{
	//printf("%d %d %d %d\n",bx,by,ex,ey);
    LIST[1].x = bx ; 
	LIST[1].y = by ; 
    LIST[1].s = 0 ; 
	int l = 1, r= 1; 
    int tempok = 0 ;
	memset(visit,0,sizeof(visit));
	visit[bx][by] = 1; 
	while(l <= r )
	{
      //  printf("%d %d\n",LIST[l].x,LIST[l].y);
	    if(LIST[l].x == ex && LIST[l].y == ey)
		{
		  tempok = 1; 
		  break;
		}
		for(int i = 0 ; i <= 3;i ++)
		{
		  int tempx = LIST[l].x + xadd[i];
		  int tempy = LIST[l].y + yadd[i];
	      if(!visit[tempx][tempy] && MAP[tempx][tempy])
		  {
		     visit[tempx][tempy] = 1;
			 r ++ ;
			 LIST[r].x = tempx; 
			 LIST[r].y = tempy; 
			 LIST[r].s = LIST[l].s +1 ; 
		  }
		}
	   l ++;
	}
	if(tempok == 0)
		ok = 0;
	else return LIST[l].s;

}
int main(){


	  while(scanf("%d %d",&n,&m) != EOF)
	  {
		if(n == 0  && m == 0)
			break;
		memset(MAP,0,sizeof(MAP));
	    memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i ++)
		{
		  char str[104];
		  scanf("%s",&str[1]);
		  for(int j = 1;j <= m;j ++)
		  {
		     if(str[j] == '#')
			 {
			 }
			 else 
			 {
				 MAP[i][j] = 1;
				 if(str[j] == '@')
			     {
			     a[0].x = i ; 
				 a[0].y = j; 
			     }
			 }
		  }
		}
		int  k ; 
		scanf("%d",&k);
		for(int i = 1;i <= k;i ++)
		    scanf("%d %d",&a[i].x,&a[i].y);
		int temp[6];
		for(int i =0 ;i < k;i ++)
		  temp[i] = i + 1; 
		ok = 1; 
        int min = 1000000;
		do{
           int last = 0;
		   int sum = 0 ; 
		   for(int i = 0 ;i < k ;i ++)
		   {
		     sum +=  bfs(a[last].x,a[last].y,a[temp[i]].x,a[temp[i]].y); 
		     last = temp[i];
		   }
		   if (sum <= min)
			   min = sum;
		
		  //  printf("%d\n",sum);
		}while(next_permutation(temp,temp+k));	
	    if(ok == 0 )
			printf("-1\n");
		else 
		printf("%d\n",min);
	  }
	  
return 0 ;
}

