// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年10月07日 星期二 00时41分28秒

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
#define eps 1e-8
using namespace std;
struct node{
    double x,y,a,b;
};
node a[5][5];
node  change(node tp)
{
   node ans;
   ans.a = tp.a;
   ans.b = tp.b;
   ans.x = tp.a - (tp.y - tp.b);
   ans.y = tp.b + (tp.x - tp.a);
   return ans;
}
int ans[0];
double dis[5][5];
double thedis(double x1, double y1, double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) ;
}
int mi; 
bool ok()
{
   node tt[5];
   for(int i = 1;i <= 4;i ++)
   {
      tt[i] = a[i][ans[i]];
   }
   for(int i = 1;i <= 4;i ++)
   {
	   for(int j= 1;j <= 4 ; j ++)
	   {
	        dis[i][j] = thedis(tt[i].x,tt[i].y,tt[j].x,tt[j].y);
	   }
     sort(dis[i] + 1,dis[i] + 1 + 4);
   }
   for(int i = 2;i <= 4;i ++)
	   for(int j = 1;j <= 4; j ++)
	   {
	      if(fabs(dis[i][j] - dis[i-1][j]) > eps)
			  return 0 ; 
	   }
   if(fabs(dis[1][4]-0 ) <eps)
	   return 0 ; 
   if(fabs(dis[1][3] - dis[1][2]) > eps)
	   return 0 ;
   if(fabs(dis[1][3] * sqrt(2) - dis[1][4]) > eps)
	   return 0 ;
   if(fabs(dis[1][3] - 0 ) < eps)
	   return 0 ;
   if(fabs(dis[1][2] - 0 ) < eps)
	   return 0 ;
   /*for(int i = 1;i <= 4;i ++)
   {
       for(int j = 1;j <= 4; j ++)
		   printf("%lf ",dis[i][j]);
	   printf("\n");
   }
   for(int i = 1;i<= 4;i ++)
	   printf("%lf %lf\n",tt[i].x,tt[i].y);
   
	   */
   return 1;
}
void dfs(int k)
{
   if(k == 5)
   {
      if(ok())
	  {
	    if(ans[1] + ans[2] + ans[3] + ans[4]  - 4< mi)
	       mi = ans[1] + ans[2] + ans[3] + ans[4] -4;
		//printf("%d %d %d %d\n",ans[1],ans[2],ans[3],ans[4]);
	  }
	  return;
   }
   for(int i = 1;i <= 4;i ++)
   {
      ans[k] = i ;
	  dfs(k+1);
   }
}
int main(){
   int n; 
   scanf("%d",&n);
   while(n--)
   {
	   for(int i= 1;i <= 4;i ++)
          scanf("%lf %lf %lf %lf",&a[i][1].x,&a[i][1].y,&a[i][1].a,&a[i][1].b);
       for(int i = 1;i<= 4;i ++ ) 
	   {
	      for(int j = 2;j <= 4;j ++)
			  a[i][j] = change(a[i][j-1]);
	   }
      /* for(int i = 1;i<= 4;i ++ ) 
	   {
	      for(int j = 1;j <= 4;j ++)
			  printf("%lf %lf ** ",a[i][j].x,a[i][j].y);
		  printf("\n");
	   }*/
	  mi = 1000; 
      dfs(1);
	  if(mi == 1000)
		  printf("-1\n");
	  else printf("%d\n",mi);
   }
return 0;
}
