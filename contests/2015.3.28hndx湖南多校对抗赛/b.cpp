// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 13时26分39秒

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
int n , x, y , c1,c2;
int tsum;
double ans ;
double dis(double x1,double y1,double x2,double y2)
{
   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void fen(double low ,double high)
{
   double mid1 = low + (high - low) *1/3; 
   double mid2 = low + (high - low) *2/3;
   double ansmid1 =dis(0,0,tsum,mid1)*c2 + dis(tsum,mid1,x,y)*c1; 
   double ansmid2 =dis(0,0,tsum,mid2)*c2 + dis(tsum,mid2,x,y)*c1; 
   if(fabs(ansmid2-ansmid1) < 1e-6)
   {
       ans = ansmid2;
	   return;
   }
   if(ansmid1 < ansmid2)
     fen(low,mid2);
   else fen(mid1,high);
}
int main(){
   while(scanf("%d %d %d %d %d",&n,&x,&y,&c1,&c2) != EOF) 
   {
	   int tx, ty ;
	   tsum = 0 ; 
       for(int i = 1;i<= n ;i++)
	   {
	     scanf("%d %d",&tx,&ty);
         tsum += ty;
	   }
	   fen(0,y);
	   printf("%.2f\n",ans);
   }
return 0;
}
