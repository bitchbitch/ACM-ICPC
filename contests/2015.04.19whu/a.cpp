#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<iomanip>

#define rep(i,n) for(int i=0;i<n;++i)
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define fba(i,b,a) for(int i=b;i>=a;--i)
#define PB push_back
#define INF 0x3f3f3f3f
#define MP make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define sf scanf
#define pf printf
#define LL long long
const int N = 2000005;
using namespace std;
typedef pair<int,int>PII;
int wa[N],wb[N],wv[N],wd[N];
int sa[N],rank[N],height[N];
int cmp(int *r, int a, int b, int l){  
	return r[a] == r[b] && r[a+l] == r[b+l];  
}  
//r数组的长度n从[0,n)
//求出的sa为从[1,n]
//调用时候r[n-1]=0
void da(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围  
	int i, j, p, *x = wa, *y = wb, *t;  
	for(i = 0; i < m; i ++) wd[i] = 0;  
	for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;  
	for(i = 1; i < m; i ++) wd[i] += wd[i-1];  
	for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;  
	for(j = 1, p = 1; p < n; j *= 2, m = p){  
		for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;  
		for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;  
		for(i = 0; i < n; i ++) wv[i] = x[y[i]];  
		for(i = 0; i < m; i ++) wd[i] = 0;  
		for(i = 0; i < n; i ++) wd[wv[i]] ++;  
		for(i = 1; i < m; i ++) wd[i] += wd[i-1];  
		for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];  
		for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){  
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;  
		}  
	} 

}  
// 求出的 height [1,n] 对应sa中的[1,n]
// 求出的 rank [0,n-1] 对应sa中的[1,n]
// 调用时候最后添加的0不用加进去
/*
//为了统一，所有的下标从0开始,左闭右开！
void fix(int n){
rep(i,n)sa[i]=sa[i+1],rank[i]--,height[i]=height[i+1];
}*/
int a[N];
struct node{ 
	int x,y; 
}tmp[N/2];
int cmp1(node a ,node b)
{
	return a.x < b.x;  
}
int  main(){
	int n,k;
	while(sf("%d %d",&n,&k)!= EOF)
	{
		int ok = 1; 
		rep(i,n)
		{sf("%1d",&a[i]);
			a[i+n] = a[i];
			if(i!= 0)
				if(a[i] != a[i-1])
					ok =0 ; 
		}
		if(ok == 1)
		{
			printf("1\n");
			continue; 
		}
		a[2*n]=0;
		da(a,2*n+1,10);
		for(int i = 1,p =0 ;i <=2*n;i ++)
		{
			if(sa[i] < n )
				p ++ ; 
			if(p == k )
			{
				if(sa[i] == 0 )
					printf("%d\n",n);
				else 
				printf("%d\n",sa[i]);
				break;
			}
			//printf("%d ",wa[i]);
		}
		//printf("\n");
		/*
		sort(tmp,tmp+n,cmp1);
		if(tmp[k-1].y != 0)
			printf("%d\n",tmp[k-1].y);
		else printf("%d\n",n);*/
	}//calHeight(a,n);
	return 0 ; 
}
