// File Name: 1823.cpp
// Author: darkdream
// Created Time: 2014年07月10日 星期四 09时38分05秒

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
#include<climits>
#include<queue>

using namespace std;
struct ynode{
	int ly,ry; 
	int v;
};
int L(int x)
{
	return x << 1 ;
}
int R(int x)
{
	return x * 2  + 1;
}
struct xnode{
	int lx, rx;
	struct ynode tt[1014<<2];
}tree[112<<2];

void build2(int x,int y,int ly ,int ry)
{
	//   printf("%d %d %d\n",y,ly,ry);
	tree[x].tt[y].ly = ly;
	tree[x].tt[y].ry = ry;
	tree[x].tt[y].v = -1;
	if(ly == ry)
		return ;
	int m = (ly + ry )/2; 
	build2(x,L(y),ly,m);
	build2(x,R(y),m+1,ry);
}
void build(int x,int lx,int rx)
{
	build2(x,1,1,1005);
	tree[x].lx = lx; 
	tree[x].rx = rx; 
	if(lx == rx)
		return ; 
	int m = (lx + rx)/2; 
	build(L(x),lx,m);
	build(R(x),m+1,rx);
}
void update2(int x, int y ,int fy,int v)
{
	//	printf("%d %d %d\n",x,y,tree[x].tt[y].v);
	int ly = tree[x].tt[y].ly;
	int ry = tree[x].tt[y].ry;
	if(ly == ry && ly == fy )
	{
		tree[x].tt[y].v = max(tree[x].tt[y].v,v);
		return ;
	}
	if(ly == ry)
		return ; 
	int m = (ly + ry)/2; 
	if(fy <= m )
		update2(x,L(y),fy,v);
	else update2(x,R(y),fy,v);
	tree[x].tt[y].v = max(tree[x].tt[L(y)].v,tree[x].tt[R(y)].v);
	//	printf("%d %d %d\n",x,y,tree[x].tt[y].v);
}
void update(int x,int fx ,int fy ,int v){
	update2(x,1,fy,v);
	if(tree[x].lx == tree[x].rx )
	{
		return ; 
	}
	int m = (tree[x].lx + tree[x].rx) /2; 
	if(fx <= m )
		update(L(x),fx,fy,v);
	else update(R(x),fx,fy,v);
}
int ans = -1 ; 
void find2(int x, int y ,int ly,int ry){
	if(ly <= tree[x].tt[y].ly && ry >= tree[x].tt[y].ry)
	{
//		printf("%d\n",tree[x].tt[y].v);
		ans = max(ans,tree[x].tt[y].v);
		return ;
	}
	int m = (tree[x].tt[y].ly + tree[x].tt[y].ry)/2;
	if(ly <= m)
		find2(x,L(y),ly,ry);
	if(ry > m)
		find2(x,R(y),ly,ry);
}
void find(int x,int lx,int rx ,int ly ,int ry){
	if(lx <= tree[x].lx && rx >= tree[x].rx)
	{
		find2(x,1,ly,ry);
		return; 
	}
	int m = (tree[x].lx + tree[x].rx)/2;
	if(lx <= m)
		find(L(x),lx,rx,ly,ry);
	if(rx > m )
		find(R(x),lx,rx,ly,ry);
}
int main(){
	int m ,tx,ty;
	double ta,tb;
	while(scanf("%d",&m) != EOF,m){
		build(1,1,105);
		char str[10];
		for(int i = 1;i <= m; i++)
		{
			scanf("%s",str);
			if(str[0] == 'I')
			{
				scanf("%d %lf %lf",&tx,&ta,&tb);
				tx = tx - 99 ;
				update(1,tx,int((ta + 1e-8)*10+1),int((tb + 1e-8)*10+1));
			}else {
				ans = -1;
				double fx,fy;
				scanf("%lf %lf %lf %lf",&fx,&fy,&ta,&tb);
				tx = (((fx + 1e-8)*10)+9)/10.0 - 99;
				ty = (fy +1e-8) - 99;
				if(tx > ty)
				{
				  int temp =tx;
				  tx = ty; 
				  ty = temp;
				}
				if(ta > tb)
				{
				  double temp =ta;
				  ta = tb; 
				  tb = temp;
				}
				find(1,tx,ty,int((ta+1e-8)*10+1),int((tb+1e-8)*10+1));
				if(ans == -1)
					printf("-1\n");
				else printf("%.1lf\n",(ans-1)/10.0+1e-8);
			}
		}
	}
	return 0;
}
