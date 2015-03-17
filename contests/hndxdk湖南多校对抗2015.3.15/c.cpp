#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-6;

struct point
{
	double x,y;
}p[600];
int visit[600];
int judge(double b,double c,point p1)
{
	double temp = p1.x+p1.y*b+c;
	if(abs(temp-0) < 1e-8) return 2;
	if(temp > 0) return 1;
	return 0;
}
double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double b = (p[n-1].x-p[0].x) / (p[0].y-p[n-1].y);
		double c = (p[0].x+p[n-1].x+(p[0].y+p[n-1].y)*b) / 2.0;
		memset(visit,0,sizeof(visit));
		point now = p[0];
		double tot = 0;
		for(int i = 0;i < n;++i)
		{
			if(judge(b,c,p[i]) == 1)
			
				tot += dis(now,p[i]);
				visit[i] = 1;
				now = p[i];
			}
		}
		visit[0] = 0;
		for(int i = n-1;i >= 0;--i)
			if(visit[i] == 0)
			{
				tot += dis(p[i],now);
				now = p[i];
			}
		printf("%f\n",tot);
	}
	return 0;
} 
