#pragma comment(linker, "/STACK:1024000000,1024000000")
// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月14日 星期二 18时35分42秒

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
#include<queue>
#define LL long long
#define maxn 500005
using namespace std;
struct node{
   LL v;
   int num ;
   node(){}
   node(LL _v , int _num){
		v = _v ;
		num = _num;
   }
   bool operator < (const node &b )const {
	 return v > b.v; 
   } 
};
priority_queue<node> qu ; 

int n ; 
int ch[maxn*4][2];
int que[maxn*4];
int deep[maxn*4];
LL a[maxn];
int tot;
int main(){
    freopen("huffman.in","r",stdin);
	freopen("huffman.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
       scanf("%I64d",&a[i]);		
	   qu.push(node(a[i],i));
	}
	tot = n; 
	while(qu.size()!= 1){
		node ta,tb;
		ta = qu.top();
		qu.pop();
		tb = qu.top();
		qu.pop();
		//printf("%I64d %d %I64d %d\n",ta.v,ta.num,tb.v,tb.num);
		tot ++ ; 
		ch[tot][0] = ta.num; 
		ch[tot][1] = tb.num; 
		qu.push(node(ta.v+tb.v,tot));
	}
	LL ans = 0 ;
	int head = 0 ; 
	int tail = 0 ; 
	deep[tot] = 0 ; 
    for(que[tail++] = tot ; head < tail ;head ++)
	{
		//printf("%d %d %d\n",que[head],ch[que[head]][0],ch[que[head]][1]);
		//:printf("%d\n",deep[que[head]]);
		if(ch[que[head]][0]){
			que[tail] = ch[que[head]][0];
		    deep[ch[que[head]][0]] = deep[que[head]]  + 1;
			tail ++ ; 
		}
		if(ch[que[head]][1]){
			que[tail] = ch[que[head]][1];
		    deep[ch[que[head]][1]] = deep[que[head]]  + 1;
			tail ++ ; 
		}
	}
	for(int i = 1;i <= n;i ++)
		ans += 1ll * deep[i] * a[i];
	printf("%I64d\n",ans);
return 0;
}
