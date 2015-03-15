#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100005
char str[maxn];
struct node{
	int l, r, m ;
	int sum , c , f; 
}tree[maxn*4];
int L(int c){
	return c*2;
}
int R(int c){
	return c*2+1;
}
void fxor(int c){
	if(tree[c].c != 0 ){
		tree[c].c  =  -tree[c].c;
		tree[c].sum = tree[c].c*(tree[c].r - tree[c].l + 1);
	}
	else {        
		tree[c].f ^= 1;
	}

}
void Pushup(int c){
	tree[c].sum = tree[L(c)].sum + tree[R(c)].sum;
	if(tree[L(c)].c == tree[R(c)].c && tree[L(c)].c != 0)
		tree[c].c = tree[L(c)].c;
	else tree[c].c = 0;
}
void Pushdown(int c){
	if(tree[c].c != 0 ){
		tree[L(c)].c = tree[R(c)].c = tree[c].c;
		tree[L(c)].sum = tree[c].c *(tree[L(c)].r - tree[L(c)].l +1);
		tree[R(c)].sum = tree[c].c *(tree[R(c)].r - tree[R(c)].l +1);
		tree[R(c)].f = tree[L(c)].f  = 0 ;
	}
	if(tree[c].f){
		fxor(L(c));
		fxor(R(c));
		tree[c].f = 0 ;
	}
}
void build(int c, int p , int v)
{
	tree[c].l = p ; 
	tree[c].r = v ;
	tree[c].m = (p+v)/2;
	tree[c].sum = 0 ; 
	tree[c].c = 0;
	tree[c].f = 0 ;
	if(p == v ){
		if(str[p] == '('){
			tree[c].c = 1; 
			tree[c].sum = 1; 
		}
		else {
			tree[c].c = -1;
			tree[c].sum = -1;
		}
		return ;
	}
	build(L(c),p,tree[c].m);
	build(R(c),tree[c].m+1,v);
	Pushup(c);
}
void update(int c , int p , int  v, int value){
	if(p <= tree[c].l  && v >= tree[c].r) {
		tree[c].c = value;
		tree[c].f = 0 ;
		tree[c].sum  = tree[c].c * (tree[c].r - tree[c].l +1);
		return ;
	}
	Pushdown(c);
	if(v <= tree[c].m ) update(L(c),p,v,value);
	else if(p > tree[c].m) update(R(c),p,v,value);
	else {
		update(L(c),p,tree[c].m,value);
		update(R(c),tree[c].m+1,v,value);
	}
	Pushup(c);
}
void fan(int c, int p , int v){
	if(p <= tree[c].l && v >= tree[c].r)  {
		fxor(c);
		return ;
	}
	Pushdown(c);
	if(v <= tree[c].m ) fan(L(c),p,v);
	else if(p > tree[c].m) fan(R(c),p,v);
	else {
		fan(L(c),p,tree[c].m);
		fan(R(c),tree[c].m+1,v);
	}
	Pushup(c);

}
int tsum =0 ;
int ok = 1;

void getsum(int c, int p, int v ){
	if(ok == 0 )
		return;
	if(p <= tree[c].l && v >= tree[c].r){
		if(tree[c].c != 0){
			tsum += tree[c].sum ;
			if(tsum < 0 )
				ok = 0 ;
			return; 
		}else {
			Pushdown(c);
			getsum(L(c),p,tree[c].m);
			getsum(R(c),tree[c].m+1,v);
			return;
		}
	}
	Pushdown(c);
	if(v <= tree[c].m) getsum(L(c),p,v);
	else if(p > tree[c].m) getsum(R(c),p,v);
	else {
		getsum(L(c),p,tree[c].m);
		getsum(R(c),tree[c].m+1,v);
	}
}
int main()
{
	int t; 
	//   	freopen("/home/plac/problem/input.txt","r",stdin);
	scanf("%d",&t);
	//  freopen("/home/plac/problem/output.txt","w",stdout);
	for(int CASE = 1; CASE <= t; CASE ++){
		int n ;
		scanf("%d",&n);
		scanf("%s",str);
		build(1,0,n-1);
		int q; 
		scanf("%d",&q);
		printf("Case %d:\n",CASE);
		while(q--)
		{
			int a, b ;
			char t1[10],t2[2];
			scanf("%s %d %d",t1,&a,&b);
			if(t1[0] == 'r'){
				fan(1,a,b);
			}else if(t1[0] == 'q'){
				tsum = 0 ; 
				ok  = 1;
				getsum(1,a,b);
				if(ok == 1 && tsum == 0 && (b-a+1)%2 == 0)
					printf("YES\n");
				else 
					printf("NO\n");

			}else{
				scanf("%s",t2);
				if(t2[0] == '(')
					update(1,a,b,1);
				else 
					update(1,a,b,-1);
			}

		}
		printf("\n");
	}
	return 0 ; 
}
