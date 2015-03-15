#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#define max(a , b) (a)>(b)?(a):(b)
#define min(a , b) (a)<(b)?(a):(b)
#define LL long long
using namespace std;

int v[500000];
int u[500000];
double w[500000];
int p[100];
int r[500000];
struct point
{
   int   x , y;
}points[60];
double dis(int i , int j )
{
	return  sqrt(pow(points[i].x-points[j].x,2) + pow(points[i].y-points[j].y,2));
}
int find(int x) 
{
   return  p[x] == x? x: p[x] = find(p[x]);
}
double cmp(const int i , const int j)
{
	return w[i] < w[j];
}
int main()
{
     int n;
    //freopen("/home/plac/problem/input.txt","r",stdin);

	 while(scanf("%d",&n) != EOF)
     {
		 memset(p,0,sizeof(p));
		 memset(r,0,sizeof(r));	
	     memset(v,0,sizeof(v));
	     memset(w,0,sizeof(w));
	     memset(u,0,sizeof(u));
	     memset(points,0,sizeof(points));
	     if(n == 0 )
		    break;
		 int a, b ; 
		 scanf("%d %d",&a,&b);
		 for(int i = 1;i <= n;i ++)		
		 {
		     scanf("%d %d",&points[i].x,&points[i].y);		
		 }
		 int k = 0;
		 for(int i  = 1;i <= n;i ++)
		  for(int j  = i+1;j <= n; j++)
		 {
		     v[k] = i ;
		     u[k] = j ;
		     w[k] = dis(i,j);
		    // printf("%lf\n",w[k]);
			 k ++;  
		 }
		 for(int i = 1;i <=  n;i ++) p[i] = i ; 
		 for(int i = 0;i <= k ; i++) r[i]  = i ;
		 sort(r,r+k,cmp);
		 p[b] = a;
		 double ans = dis(a,b);
		 
		 for(int i = 0 ;i < k ;i ++)
		 {
			 int e = r[i];
		     int x  = find(v[e]);
			 int y = find(u[e]);
			 if(x != y)
			 {
			    ans += w[e];
				p[x] = y;
			 }
		 }		  
		 printf("%.2f\n",ans);
	 }
	return 0 ;
}
