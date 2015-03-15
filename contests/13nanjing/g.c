// File Name: g.c
// Author: darkdream
// Created Time: 2014年05月14日 星期三 21时02分57秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
	int lx,ly,rx,ry,min,max,midx,midy;
}tree[10000000];
int map[1000][1000];
int L(int x)
{
	return 2 * x; 
}
int R(int x)
{
	return 2*x + 1;
}
int Max(int x, int y )
{
	if(x > y )
		return x; 
	return y ; 
}
int Min(int x,int y )
{
	if(x < y )
		return x; 
	return y ;
}
void pushup(int c)
{
	tree[c].max = Max(tree[L(c)].max,tree[R(c)].max);
	tree[c].min = Min(tree[L(c)].min,tree[R(c)].min);
}
void build(int c, int lx,int ly,int rx ,int ry)
{
	tree[c].lx = lx ;
	tree[c].ly = ly;
	tree[c].rx = rx; 
	tree[c].ry = ry;
	tree[c].min = 0 ; 
	tree[c].max = 0 ;
	tree[c].midx = (tree[c].rx + tree[c].lx)/2;
	tree[c].midy = (tree[c].ry + tree[c].ly)/2;
	if(tree[c].lx == tree[c].rx && tree[c].ly == tree[c].ry)
	{
		tree[c].min = map[tree[c].lx][tree[c].ly];
		tree[c].max = map[tree[c].lx][tree[c].ly];
		return ; 
	}
	if(tree[c].rx != tree[c].lx)
	{
		build(L(c),lx,ly,tree[c].midx,ry);
		build(R(c),tree[c].midx +1,ly,rx,ry);
	}else{
		build(L(c),lx,ly,rx,tree[c].midy);
		build(R(c),lx,tree[c].midy+1,rx,ry);
	}
	pushup(c);
}
int max ,min,color;
void find(int c, int lx,int ly ,int rx, int ry){ 
	if(lx <= tree[c].lx && ly <= tree[c].ly && rx >= tree[c].rx && ry >= tree[c].ry)
	{
		max = Max(max,tree[c].max);
		min = Min(min,tree[c].min);
		return ; 
	}
	if(tree[c].rx != tree[c].lx)
	{
		if(rx  <= tree[L(c)].rx)
			find(L(c),lx,ly,rx,ry);
		else if(lx >= tree[R(c)].lx)
			find(R(c),lx,ly,rx,ry);
		else {
			find(L(c),lx,ly,tree[L(c)].rx,ry);
			find(R(c),tree[R(c)].lx,ly,rx,ry);
		}
	}else{
		if(ry <= tree[L(c)].ry){
			find(L(c),lx,ly,rx,ry);
		}
		else if(ly >= tree[R(c)].ly){
			find(R(c),lx,ly,rx,ry);
		}else {
			find(L(c),lx,ly,tree[L(c)].rx,tree[L(c)].ry);
			find(R(c),tree[R(c)].lx,tree[R(c)].ly,rx,ry);
		}
	}
}
void update(int c, int lx,int ly ,int rx, int ry){ 
	if(lx <= tree[c].lx && ly <= tree[c].ly && rx >= tree[c].rx && ry >= tree[c].ry)
	{
		tree[c].max = color;
		tree[c].min = color;
		return ; 
	}
	if(tree[c].rx != tree[c].lx)
	{
		if(rx  <= tree[L(c)].rx)
			update(L(c),lx,ly,rx,ry);
		else if(lx >= tree[R(c)].lx)
			update(R(c),lx,ly,rx,ry);
		else {
			update(L(c),lx,ly,tree[L(c)].rx,ry);
			update(R(c),tree[R(c)].lx,ly,rx,ry);
		}
	}else{
		if(ry <= tree[L(c)].ry){
			update(L(c),lx,ly,rx,ry);
		}
		else if(ly >= tree[R(c)].ly){
			update(R(c),lx,ly,rx,ry);
		}else {
			update(L(c),lx,ly,tree[L(c)].rx,tree[L(c)].ry);
			update(R(c),tree[R(c)].lx,tree[R(c)].ly,rx,ry);
		}
	}
	pushup(c);
}
int main(){
	int t ;
	scanf("%d",&t);
	for(int ca = 1;ca <= t ; ca ++)
	{
		int n ;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n ;j ++)
				scanf("%d",&map[i][j]);
		build(1,1,1,n,n);
		printf("Case #%d:\n",ca);
		int q ;
		scanf("%d\n",&q);
		while(q --)
		{
			int x,y,z ;
			scanf("%d %d %d",&x,&y,&z);
			int t = z/2;
			int lx = Max(x-t,1);
			int ly = Max(y-t,1);
			int rx = Min(x+t,n);
			int ry = Min(y+t,n);
			min = 1e9 + 1;
			max = -1;
			find(1,lx,ly,rx,ry);
			color = (min+max)/2;
			printf("%d\n",color);
			update(1,x,y,x,y);
		}
	}
	return 0 ;
}
