// File Name: cowtour.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 14时55分43秒
/*
ID: dream.y1
PROG: cowtour
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
  double x, y ;
}p[200];
double map[200][200];
int is[200][200];
int n ; 
int p1num = 0 ; 
int p2num = 0;
int f[200];
double m[200];
int find(int x)
{
   return f[x] == x?x:f[x] = find(f[x]);
}
double fuck(double a ,double b)
{
  if(a > b)
	  return a; 
  else return b;
}
int main(){
  freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
   scanf("%d",&n);
   for(int i = 1;i <= n ;i ++)
    {
	  f[i] = i ; 
	}
   for(int i =1 ;i <= n ;i ++)
   {
     scanf("%lf %lf",&p[i].x,&p[i].y);
   }
   for(int i= 1;i <= n;i ++)
	   for(int j =1 ;j<= n ;j ++)
	   { 
		   if(i != j)
		   map[i][j]  = 1e50;
		   else map[i][j] = 0 ; 
	   }
   for(int i =1;i <= n; i ++)
    for(int j=1 ;j <= n;j ++)
    {
       scanf("%1d",&is[i][j]);
	   if(is[i][j])
	    map[i][j] = sqrt((p[i].x - p[j].x) * (p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y - p[j].y));
    }
for(int k = 1;k <= n; k ++)
   for(int i = 1;i <= n;i ++)
	   for(int j= 1;j <= n;j ++ )
		   {
		     if(map[i][j] > map[i][k] + map[k][j])
			 {
			   map[i][j] = map[i][k] + map[k][j];
			 }
		   }

   double max[200];
   for(int i = 1;i <= n;i ++)
	   max[i] = 0;
   for(int i= 1;i <= n;i ++)
	  for(int j= 1;j <= n; j ++)
	  {
	     if((map[i][j] > max[i] && map[i][j] < 1e40))
		 {
		   max[i] = map[i][j];
		 }
		 if(map[i][j] < 1e40)
		 {
		   int ta = find(i);
		   int tb = find(j);
		   if(ta != tb)
		   f[ta] = tb;
		 }
	  }
   for(int i = 1;i <= n;i ++)
	    m[i] =  0 ;
   for(int i = 1;i <= n;i ++)
	   for(int j= 1;j <= n;j ++)
	   {
		 if(find(i) == find(j))
		 {
	         if(map[i][j] > m[find(i)])	
				 m[find(1)] = map[i][j];
		 }
	   }
   double ans = 1e50; 
   for(int i = 1;i <= n;i ++)
	   for(int j= 1;j <= n;j ++)
	   {
		 if(find(i) != find(j))
		 {
	     double temp = max[i] + max[j] +  sqrt(1.0*(p[i].x - p[j].x) * (p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y - p[j].y));
	     temp = fuck(fuck(temp,m[find(i)]),m[find(j)]);
		 if(temp < ans)
			 ans = temp;
		 }
	   }
   printf("%.6lf\n",ans);
return 0 ;
}
