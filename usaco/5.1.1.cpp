// File Name: 5.1.1.cpp
// Author: darkdream
// Created Time: 2013年01月23日 星期三 17时36分11秒

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

using namespace std;

struct point{
  double x,y;
};

double dis(struct point a, struct point b)
{
   return sqrt((a.x-b.x)*(a.x-b.x)+(a.y- b.y)*(a.y-b.y));
}


int main(){

	 int n ;
     struct point a[11000], s, x, z, y;
	 double sy ,zx , xy ,yx ; 
	 sy = -1000000;
	 zx = 1000000;
	 xy = 1000000;
     yx = -1000000;
	 scanf("%d",&n);
     int i ; 
	 for(i = 0;i < n ; i++)
	 {	
		 scanf("%lf %lf",&a[i].x,&a[i].y);
	     if (a[i].y > sy)
		 { s = a[i];
		   sy = a[i].y; 
		 }
		 if (a[i].y < xy)
		 {	 x  = a[i];
		     xy = a[i].y;
		 }
		 if (a[i].x > yx)
		 { y = a[i];
		   yx = a[i].x;
		 }if (a[i].x < zx)
		 { z = a[i];
		   zx = a[i].x;
		 }
   

	 }
    printf("%lf %lf \n %lf %lf \n    %lf %lf \n    %lf %lf \n",s.x,s.y,z.x,z.y,x.x,x.y,y.x,y.y); 
	 double sum = dis(s,z)+dis(z,x)+dis(x,y)+dis(y,s);
	 printf("%.2lf",sum);
	 
	 
	return 0;
}
