// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 11时06分10秒

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
#include<queue>
#include<limits.h>
#define LL long long

using namespace std;
struct node{
  int v;
  int st;
}num[100001];
struct node1{
  int p;
  int v,st;
  node1(int z,int x, int y)
  {
	 p = z; 
     v = x; 
	 st = y ; 
  }
  bool operator <(const node1 b) const {
      if(b.v == v)
		  return st > b.st;
	  return v > b.v;
  } 
};
int change[4][12];
int n , m ,mx; 
void spfa()
{
  node1 temp = node1(n,0,0);
  priority_queue <node1> Q;
  Q.push(temp);
  while(!Q.empty())
  {
     temp = Q.top();
	 //printf("%d %d %d",temp.p,temp.v,temp.st);
	 Q.pop();
	 if(num[temp.p].v != temp.v || num[temp.p].st != temp.st)
	          continue;
		//	  printf("****");
	 int t ;
	 for(int i = 0;i <= 9 ;i ++)
	 {
       t = temp.p *10 + i ;
	   if(t > mx )
		   continue;
	   if(num[t].v > temp.v + change[1][i] ||(num[t].v == temp.v + change[1][i] && num[t].st > temp.st + 1))
	   {
		num[t].v = temp.v + change[1][i];
		num[t].st = temp.st + 1; 
	    Q.push(node1(t,temp.v+change[1][i],temp.st + 1));
	   }
	 }
	 for(int i = 0;i <= 9 ;i ++)
	 {
       t = temp.p + i ;
	   if(t > mx)
		   continue;
	   if(num[t].v > temp.v + change[2][i] ||(num[t].v == temp.v + change[2][i] && num[t].st > temp.st + 1))
	   {
		num[t].v = temp.v + change[2][i];
		num[t].st = temp.st + 1; 
	    Q.push(node1(t,temp.v+change[2][i],temp.st + 1));
	   }
	 }
	 for(int i = 0;i <= 9 ;i ++)
	 {
       t = temp.p*i ;
	   if(t > mx)
		   continue;
	   if(num[t].v > temp.v + change[3][i] ||(num[t].v == temp.v + change[3][i] && num[t].st > temp.st + 1))
	   {
		num[t].v = temp.v + change[3][i];
		num[t].st = temp.st + 1; 
	    Q.push(node1(t,temp.v+change[3][i],temp.st + 1));
	   }
	 }
  }
}
int main(){
  int ca =0 ; 
  while(scanf("%d %d",&n,&m) != EOF)
  {
      ca ++ ;
	  mx = max(n,m);
	  for(int i = 0;i <= mx;i ++)
	  {
	    num[i].v = INT_MAX ; 
		num[i].st = INT_MAX;
	  }
      for(int i = 1;i<= 3;i ++)
		 for(int j= 0;j <= 9 ;j ++)
		 {
		    scanf("%d",&change[i][j]);  
		 }
	   change[2][0] = 0 ; 
	   num[n].v = 0 ; 
	   num[n].st = 0; 
	   spfa();
	   printf("Case %d: %d %d\n",ca,num[m].v,num[m].st);
  }
return 0;
}
