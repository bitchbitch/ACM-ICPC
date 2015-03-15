// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月17日 星期日 16时35分29秒

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
#define pi  3.141592653
double dis(double x1,double y1 ,double x2,double y2)
{
   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double x, y ,d;
double fen(x,y)
{
   double l = 0 , r = d; 
   while(fabs(l-d) > 1e-9)
   {
      double m = (l+r)/2; 
      
   }
}
int main(){
    double x, y ,d;
	while(scanf("%lf %lf %lf",&x,&y,&d) != EOF)
	{
	   if(fabs(dis(x,y,0,0)-d) < 1e-10)
	   {
	       printf("Single staircase\n");
	   }else if(dis(x,y,0,0) > d) 
	   {
	     printf("Impossible\n");
	   }else{
          solve()	   
	   }
	}
return 0;
}
