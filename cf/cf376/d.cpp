// File Name: d.cpp
// Author: darkdream
// Created Time: 2013年12月24日 星期二 23时07分43秒

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

using namespace std;
#define MAXN 5005
int hehe[5001][5001] = {0};
int hs[5005];
void radixsort(int *a, int n)
{
	int i, b[MAXN], m = a[0], exp = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}

	while (m / exp > 0)
	{
		int bucket[10] ={ 0 };
		for (i = 0; i < n; i++)
			bucket[(a[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(a[i] / exp) % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
int cmp(const void * a,const void *b)
{
   return *(int *)a - *(int *)b;
}
int main(){
//	clock_t start,end;
	//start = clock();
  //  freopen("input.txt","r",stdin);
	int n ,m ;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<= n;i ++)
		for(int j = 1; j <= m;j ++)
		{
			scanf("%1d",&hehe[i][j]);
			if(hehe[i][j])
			hehe[i][j] += hehe[i][j-1];
		}
    int mx = 0 ;
	for(int i =1 ;i <= m;i ++)
	{
		int t = -1; 
		for(int j = 1;j <= n;j ++)
		{
			t++;
			if(hehe[j][i])
			hs[t] = hehe[j][i];
		}
	    qsort(hs,t+1,sizeof(int),cmp);
	/*	for(int i = 0 ;i <= t; i ++)
			printf("%d ",hs[i]);
		printf("\n");*/
		for(int j = 0 ;j <= t; j ++)
		{
		  int temp = hs[j]*(t-j+1);
		  if(temp > mx)
			  mx = temp;
		}
	}
//	end = clock();
	printf("%d\n",mx);
//	printf("%d\n",end-start);
	return 0;
}
