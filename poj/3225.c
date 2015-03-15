#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 140000
struct node
{
	int l ,r , m, c ,f;
}tree[maxn * 4];
int L(int c)
{
	return 2*c;
}
int R(int c)
{
	return 2*c+1;
}
int hs[maxn*2];
void build(int c, int p , int v )
{
	tree[c].l = p;
	tree[c].r = v;
	tree[c].m = (p+v)/2;
	tree[c].c = 0 ;
	if(p == v)
		return;
	build(L(c),p,tree[c].m);
	build(R(c),tree[c].m+1,v);
}
void Fxor(int c)
{
	if(tree[c].c != -1) tree[c].c ^= 1; 
	else tree[c].f ^= 1;
}
void Pushdown(int c)
{
	if(tree[c].c!= -1){
		tree[L(c)].c = tree[c].c;
		tree[R(c)].c = tree[c].c;
		tree[R(c)].f = tree[L(c)].f = 0 ;
		tree[c].c = -1; 
	}
	if(tree[c].f)
	{
		Fxor(L(c));
		Fxor(R(c));
		tree[c].f = 0 ; 
	}


}
void update(int c , int p , int v ,int value )
{
	if( p <= tree[c].l && v >= tree[c].m)
	{
		tree[c].c = value;
		tree[c].f = 0;
		return ;
	} 
	Pushdown(c);
	if(v <= tree[c].m) update(L(c),p,v,value);
	else if(p > tree[c].m) update(R(c),p,v,value);
	else {
		update(L(c),p,tree[c].m,value);
		update(R(c),tree[c].m + 1 ,v,value);
	}
}
void fan(int c ,int p , int v)
{
	if(p <= tree[c].l && v >= tree[c].m)
	{
		tree[c].f = tree[c].f^1;
		// sonme  Pushdown(c);
		return ;
	}
	Pushdown(c);
	if(v <= tree[c].m) fan(L(c),p,v);
	else if(p > tree[c].m) fan(R(c),p,v);
	else{
		fan(L(c),p,tree[c].m);
		fan(R(c),tree[c].m + 1 ,v);
	}
}

void geths(int c,int p ,int v )
{
	if(p <= tree[c].l && v >= tree[c].r)
	{
		if(tree[c].c == 1)
		{	for(int i = tree[c].l ;i <= tree[c].r ;i ++)
			{
				hs[i] = 1;
			}
			return;
		}
	
	}
	if(tree[c].l == tree[c].r)
		return;
	Pushdown(c);
	if(v <= tree[c].m)  geths(L(c),p,v);
	else if(p > tree[c].m) geths(R(c),p,v);
	else {
		geths(L(c),p,tree[c].m);
		geths(R(c),tree[c].m+1,v);
	}
}
int main()
{
	build(1,0,maxn);
	memset(hs,0,sizeof(hs));
	char op,l,r;
	int a,b;
	while(scanf("%c %c%d,%d%c",&op,&l,&a,&b,&r) != EOF)
	{
		a *= 2; 
		b *= 2;
		if(l == '(')
			a++;
		if(r == ')')
			b--;
		getchar();
		if(op == 'U'){
			update(1,a,b,1);
		}else if(op == 'I'){
			update(1,0,a-1,0);
			update(1,b+1,maxn,0);
		}else if(op == 'D'){
			update(1,a,b,0);
		}else if(op == 'C'){
			fan(1,a,b);
			update(1,0,a-1,0);
			update(1,b+1,maxn,0);
		}else{
			fan(1,a,b);
		} 
		geths(1,0,maxn);
		for(int i = 0;i <= 20 ; i++)
			printf("%d ",hs[i]);
		printf("\n");
		memset(hs,0,sizeof(hs));   
	}
	return 0 ;
}

