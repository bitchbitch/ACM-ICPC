/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-27 16:00
 * Filename : e.cpp
 * Description :
 * *********************************************************/
// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 01时21分34秒

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
#define LL long long

using namespace std;
int n ,m ;
LL s ; 
LL a[100];
LL b[100];
map<int,map<LL,LL> > mpa;
map<int,map<LL,LL> > mpb;
map<LL,LL>::iterator tt;
int li;
void dfs(int p ,int k,LL v,map<int,map<LL,LL> > &tmp)
{
	//printf("%d %d %I64d\n",p,k,v);
	if(k > m)
		return;
	if(p == li + 1)
	{
	  tmp[k][v] += 1 ;
	  return;
	}
	if(v + a[p] <= s)
		dfs(p+1,k,v+a[p],tmp);
	if(a[p] <= 18 && v + b[p] <= s)
		dfs(p+1,k+1,v+b[p],tmp);
	dfs(p+1,k,v,tmp);
}
int main(){
    scanf("%d %d %I64d",&n,&m,&s);
	for(int i = 1;i <= n;i ++)
    {
	   scanf("%I64d",&a[i]);
	}
    sort(a+1,a+1+n);
	for(int i = 1;i <= n;i ++)
	{
	   if(a[i] <= 18)
	   {
	     b[i] = 1; 
		 for(int j = 1;j <= a[i]; j ++)
		 {
		   b[i] *= j;
		 }
	   }
	}
	 li = n/2; 
	dfs(1,0,0,mpa);
	li = n; 
	//puts("***");
	dfs(n/2+1,0,0,mpb);
	LL sum = 0 ; 
	for(int i = 0 ;i <= m;i ++)
	{
	    for(int j = 0 ;j + i <= m;j ++)
		{
		   for(tt = mpa[i].begin(); tt != mpa[i].end();tt++)
		   {
              sum += (mpb[j][s - tt->first]) * (tt->second);
	//	      printf("***%d %I64d %I64d %I64d\n",j,s-tt->first,mpb[j][s-tt->first],tt->second);
		   }
		}
	}
	printf("%I64d\n",sum);
	return 0;
}
