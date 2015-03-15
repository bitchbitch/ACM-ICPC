// File Name: TheCastle.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 16时35分02秒
/*
ID: dream.y1
PROG: castle
LANG: C++
*/
#include<vector>
#include<list>
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
int n ,m; 
int a[200][200];
void dosomething(int i ,int j ,int k)
{
	if(k >= 8 ){
	   a[i+1][j] = a[i+1][j+1] = a[i+1][j-1] = -1;
	   k -= 8;
	}if(k >= 4){
	   a[i][j+1] = a[i-1][j+1] = a[i+1][j+1] = -1;
       k -= 4;
	}if(k >= 2){
	   a[i-1][j] = a[i-1][j+1] = a[i-1][j-1] = -1;
	   k -= 2; 
	}if(k >= 1){
	   a[i][j-1] = a[i-1][j-1] = a[i+1][j-1] = -1;
	}
}
int visit[200][200];
int sum = 0 ;
int xadd[5] = {1,0,-1,0};
int yadd[5] = {0,1,0,-1};
void dfs(int x, int y )
{
  if(x % 2 == 1 && y % 2 == 1)
     sum ++;
  for(int i = 0 ;i <= 3;i ++)
  {
     int tx = x + xadd[i];
	 int ty = y + yadd[i];
	 if(a[tx][ty] != -1 && !visit[tx][ty])
	 {
	     visit[tx][ty] = 1; 
		 dfs(tx,ty);
	 }
  }
}
int visit1[200][200];
void dfs1(int x, int y , int v)
{
  for(int i = 0 ;i <= 3;i ++)
  {
     int tx = x + xadd[i];
	 int ty = y + yadd[i];
	 if(a[tx][ty] == 0  && !visit1[tx][ty])
	 {
	     visit1[tx][ty] = 1; 
		 a[tx][ty] = v;
		 dfs1(tx,ty,v);
	 }
  }

}
int ans[100000];
int p = 0 ; 
int main(){
freopen("castle.in","r",stdin);
freopen("castle.out","w",stdout);
   scanf("%d %d",&m,&n);
   int temp; 
   memset(a,0,sizeof(a));
   memset(visit,0,sizeof(visit));
   memset(visit1,0,sizeof(visit1));
   for(int i= 1;i <= 2*n;i +=2)
	   for(int j = 1; j<= 2*m ;j +=2)
	   {
	     scanf("%d",&temp);
	     dosomething(i,j,temp);
	   }

/*  for(int i =0 ;i <=2*n;i ++)
  {  for(int j = 0;j <= 2*m; j ++)
	  {
	    if(a[i][j])
			printf("#");
		else printf(" ");
	  }
	  printf("\n");
  }*/


  int room = 0 ;
  int maxroom = 0;

  for(int i =1;i <=2*n;i +=2)
  {  for(int j = 1;j <= 2*m; j += 2)
	  {
	    if(!visit[i][j])
		{
		    visit[i][j] = 1;
		    sum = 0 ; 
	    	dfs(i,j);
			p ++ ;
			ans[p] = sum;
			if(sum > maxroom)
			{ 
		      maxroom = sum;
			}
			a[i][j] = p;
			dfs1(i,j,p);
		    room++;
		}
	  }
  }
  int tx, ty,tmax = 0 ;
  char  dnxb;
  int xx ;
  for(int j =1 ;j <=2*m;j ++)
  {  
	  for(int i = 2*n;i >= 1; i --)
	  {
	       if(a[i][j] == -1 && ((i% 2 == 1) ^(j % 2 == 1)))
		   {
			  int ttmax = 0 ; 
		      if(j % 2 == 1){
			      if(a[i-1][j] != a[i+1][j]){
					  ttmax += ans[a[i+1][j]] + ans[a[i-1][j]];
					  if(ttmax > tmax)
					  {
						  tmax = ttmax;
						  tx = (i+2)/2;
						  ty = (j+1) /2;
						  dnxb =  'N';
					  }
				  }else continue;
			  }else{
			      if(a[i][j-1] != a[i][j+1]){
					  ttmax += ans[a[i][j-1]] + ans[a[i][j+1]];
					  if(ttmax > tmax)
					  {
						  tmax = ttmax;
						  tx = (i+1)/2;
						  ty = j/2;
						  dnxb =  'E';
					  }
				  }else continue;
			  }
		   
		   }
	  }
	
  }
  printf("%d\n%d\n%d\n%d %d %c\n",room,maxroom,tmax,tx,ty,dnxb);
  
return 0;
}
