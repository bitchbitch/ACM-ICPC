// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 16时47分54秒

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
double  mp[200][200];
struct node{
  double x, y; 
}dapao[200],be,en ;
int n;
double dis(double x1,double x2,double y1,double y2)
{
   return sqrt((x1-y1)*(x1-y1) + (x2-y2)*(x2-y2));
}
double  mi ;
int main(){
   scanf("%lf %lf",&be.x,&be.y);
   scanf("%lf %lf",&en.x,&en.y);

   mi = dis(be.x,be.y,en.x,en.y)/5;
   scanf("%d",&n);
   
   dapao[n+1].x = en.x ; 
   dapao[n+1].y = en.y ;
   for(int i = 1;i <= n;i ++)
   {
      scanf("%lf %lf",&dapao[i].x,&dapao[i].y) ;
   }
   for(int i= 1;i <= n;i ++)
   {
      for(int j = 1;j <= n+1 ; j ++)
	  {
		 double  tmp;
	     mp[i][j] = dis(dapao[i].x,dapao[i].y,dapao[j].x,dapao[j].y);
		 tmp = 2 + fabs(50.0 - mp[i][j])/5 ;
		 mp[i][j] = min(mp[i][j]/5,tmp);
	  }
   }
   for(int k= 1;k <= n;k ++)
   {
     for(int i = 1;i <= n;i ++)
	 {
	   for(int j =1 ;j <= n + 1;j ++)
	     mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
	 }
   }
   for(int i = 1;i <= n;i ++)
   {
        mi = min(mi,dis(be.x,be.y,dapao[i].x,dapao[i].y)/5+mp[i][n+1]);    
   }
   printf("%f\n",mi);
return 0;
}
