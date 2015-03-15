// File Name: 1006.cpp
// Author: darkdream
// Created Time: 2014年09月14日 星期日 15时54分04秒

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
int ans = 0 ; 
int bit[7] ={0,1,10,100,1000,10000,100000};
int change1(int k )
{
   int t = 0 ;
   t += (k/bit[6]%10) *bit[4];
   t += (k/bit[5]%10) *bit[3];
   t += (k/bit[4]%10) *bit[5];
   t += (k/bit[3]%10) *bit[6];
   t += (k/bit[2]%10) *bit[2];
   t += (k/bit[1]%10) *bit[1];
   return t;
}
int change2(int k )
{
   int t = 0 ; 
   t += (k/bit[6]%10) *bit[3];
   t += (k/bit[5]%10) *bit[4];
   t += (k/bit[4]%10) *bit[6];
   t += (k/bit[3]%10) *bit[5];
   t += (k/bit[2]%10) *bit[2];
   t += (k/bit[1]%10) *bit[1];

   return t;
}
int change3(int k)
{
   int t = 0;
   t += (k/bit[6]%10) *bit[2];
   t += (k/bit[5]%10) *bit[1];
   t += (k/bit[2]%10) *bit[5];
   t += (k/bit[1]%10) *bit[6];
   t += (k/bit[3]%10) *bit[3];
   t += (k/bit[4]%10) *bit[4];
  return t;
}
int change4(int k)
{
  int t = 0 ;
  t += (k/bit[2]%10) *bit[6];
  t += (k/bit[1]%10) *bit[5];
  t += (k/bit[5]%10) *bit[2];
  t += (k/bit[6]%10) *bit[1];
  t += (k/bit[3]%10) *bit[3];
  t += (k/bit[4]%10) *bit[4];
  return t;
}
struct node{
  int x;
  int step;
  int last;
}st[666666];
int visit[666666];
void bfs(int now)
{
   int l = 1; 
   int r = 1; 
   int temp ; 
   st[1].x = now;
   st[1].step = 0 ;
   int ok = 0 ; 
   while(l <= r)
   {
	   printf("%d %d %d\n",st[l].x,l,st[l].last);
       if(st[l].x == ans)
	   {
	     printf("%d\n",st[l].step);
		 ok = 1 ; 
		 break;
	   }
	   temp = change1(st[l].x);
	   if(!visit[temp])
	   {
	     visit[temp] = 1; 
		 r ++ ;
		 st[r].x = temp;
		 st[r].step = st[l].step + 1;
		 st[r].last = l;
	   }
	   temp = change2(st[l].x);
	   if(!visit[temp])
	   {
	     visit[temp] = 1; 
		 r ++ ;
		 st[r].x = temp;
		 st[r].step = st[l].step + 1;
		 st[r].last = l;
	   }
	   

	   temp = change3(st[l].x);
	   if(!visit[temp])
	   {
	     visit[temp] = 1; 
		 r ++ ;
		 st[r].x = temp;
		 st[r].step = st[l].step + 1;
		 st[r].last = l;
	   }
	   temp = change4(st[l].x);
	   if(!visit[temp]){
	     visit[temp] = 1; 
		 r ++ ;
		 st[r].x = temp;
		 st[r].step = st[l].step + 1;
	   }
	   {
	     visit[temp] = 1; 
		 r ++ ;
		 st[r].x = temp;
		 st[r].step = st[l].step + 1;
		 st[r].last = l;
	   }
	   l ++ ; 
   }
   if(!ok)
	   printf("-1\n");
}
int now  = 0 ; 
int main(){
	int temp ;
    while(scanf("%d",&now) != EOF)
	{
	  for(int i = 1;i <= 5;i ++)
	  {
	     scanf("%d",&temp);
         now = now* 10 + temp ; 		  
	  }
	  ans = 0 ; 
	  for(int i = 1;i <= 6;i ++)
	  {
	     scanf("%d",&temp);
		 ans = ans * 10 + temp;
	  }
	  if(now == ans )
	  {
	     printf("0\n");
		 continue;
	  }
	  memset(visit,0,sizeof(visit));
	  visit[now] = 1; 
	  bfs(now);
	}
return 0;
}
