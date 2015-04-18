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
    double x,y,z;
};
node a[5];
double dis[5][5];
double thedis(double x1, double y1,double z1, double x2,double y2,double z2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2) *(z1-z2)) ;
}
bool ok()
{
   for(int i = 1;i <= 4;i ++)
   {
       for(int j= 1;j <= 4 ; j ++)
       {
            dis[i][j] = thedis(a[i].x,a[i].y,a[i].z,a[j].x,a[j].y,a[j].z);
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
   return 1;
}
int main(){
   int n; 
   //freopen("A.in","r",stdin);
   //freopen("A.out","w",stdout);
   scanf("%d",&n);
   for(int ca = 1 ; ca <= n ; ca ++)
   {
       for(int i= 1;i <= 4;i ++)
          scanf("%lf %lf %lf",&a[i].x,&a[i].y,&a[i].z);
	   printf("Case #%d: ",ca);
       if(ok())
	   {
	     printf("Yes\n");
	   }else {
	     printf("No\n");
	   }
   }
return 0;
}
