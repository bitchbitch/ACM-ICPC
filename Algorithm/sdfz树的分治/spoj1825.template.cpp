/*
 * Author:  vawait
 * Created Time:  2014年05月08日 星期四 23时27分25秒
 * File Name: 1.cpp
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
typedef long long lint;
const int mm = 1 << 18;
lint qq = 200010LL * 10000 , ans = 0;
int n , m , k ;

struct zkw
{
	lint t[(1<<19)+20];
	void cha(int x,lint y) {
		x += mm + 1; 
		if ( y < t[x] ) return; else t[x] = y;
		for ( x >>= 1 ; x ; x >>= 1 ) t[x] = t[x<<1] > t[x+x+1] ? t[x<<1] : t[x+x+1];
	}
	lint ask(int r) {
		if ( r < 0 ) return 0;
		lint ans = 0;
		int l = mm; r += mm + 2;
		for ( ; l ^ r ^ 1; l >>= 1 , r >>= 1 ) {
			if ( ~ l & 1 ) if ( t[l^1] > ans ) ans = t[l^1];
			if ( r & 1 ) if ( t[r^1] > ans ) ans = t[r^1];
		}
		return ans;
	}
} T;

struct nodd
{
	#define maxn 200010
	lint ss , f[maxn];
	int t , sum , mx[maxn] , a[maxn] , s[maxn];
	bool v[maxn] , d[maxn];
	struct node {
		int y , d , n;
	} b[maxn<<1];
	void add(int x,int y,int d) {
		b[++t].y = y; b[t].d = d;
		b[t].n = a[x]; a[x] = t;
	}
	void fdfs(int t,int fa) {
		s[t] = 1; mx[t] = 0;
		for( int p = a[t]; p; p = b[p].n ) if ( b[p].y != fa && v[b[p].y] ) {
			fdfs( b[p].y , t );
			s[t] += s[b[p].y];
			mx[t] = max( mx[t] , s[b[p].y] );
		}
	}
	void froot(int t,int m,int &root) {
		mx[t] = max( mx[t] , m - s[t] );
		for ( int p = a[t]; p; p = b[p].n ) if ( v[b[p].y] && s[t] > s[b[p].y] ) froot( b[p].y , m , root );
		if ( mx[t] < mx[root] ) root = t;
	}
	void dfs(int t,int fa) {
		sum += d[t];
		if ( k ) {
			lint y = T.ask( m - sum ) - qq + ss;
			if ( y > ans ) ans = y;
		} else T.cha( sum , ss + qq );
		for ( int p = a[t]; p; p = b[p].n ) if ( v[b[p].y] && b[p].y != fa ) {
			ss += b[p].d;
			dfs( b[p].y , t );
			ss -= b[p].d;
		}
		sum -= d[t];
	}
	void init() {
		int x , y , dd;
		t = 1;
		rep(i,1,n) v[i] = 1 , a[i] = 0 , d[i] = 0;
		rep(i,1,k) scanf("%d",&x) , d[x] = 1;
		rep(i,2,n) {
			scanf("%d%d%d",&x,&y,&dd);
			add( x , y , dd );
			add( y , x , dd );
		}
	}
	void ask() {
		rep(i,1,n) while ( v[i] ) {
			fdfs( i , 0 );
			if ( s[i] == 1 ) break;
			int x = i;
			froot( i , s[i] , x );
			v[x] = 0;
			qq += 20000000000LL;
			T.cha( d[x] , qq );
			for ( int p = a[x]; p; p = b[p].n ) if ( v[b[p].y] ) {
				sum = 0; k = 1; ss = b[p].d;
				dfs( b[p].y , x );
				sum = d[x]; k = 0; ss = b[p].d;
				dfs( b[p].y , x );
			}
		}
	}
} Tree;

void init()
{
	scanf("%d%d%d",&n,&m,&k);
	Tree.init();
}

void work()
{
	Tree.ask();
	cout << ans << endl;
}

int main()
{
	//freopen("out","r",stdin);
	//freopen("output1.txt","w",stdin);

	while(scanf("%d%d%d",&n,&m,&k)!= EOF)
	{
		ans = 0 ;
	   Tree.init();
     	work();
	
	}return 0;
}
