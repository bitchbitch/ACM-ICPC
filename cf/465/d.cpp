// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年09月08日 星期一 00时41分15秒

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
int a[9][4];
vector<double> b[9];
double dis(int i,int j)
{
	return sqrt(1.0*(a[i][1] -a[j][1])*(a[i][1] -a[j][1]) +(a[i][2] -a[j][2])*(a[i][2] -a[j][2]) + (a[i][3] -a[j][3]) *(a[i][3] -a[j][3]));
}
int sq(double x, double y)
{
	if(fabs(x-y) < 1e-8)
		return 1;
	return 0 ; 
}
int solve()
{
	for(int i =1 ;i <= 8;i ++)
	{
		b[i].clear();
	}
	for(int i =1;i <= 8 ;i ++){
		for(int j = i+1;j <=8 ;j ++)
		{
			double temp = dis(i,j);
			b[i].push_back(temp);
			b[j].push_back(temp);
		}
	}
	for(int i = 1;i <= 8;i ++)
		sort(b[i].begin(),b[i].end());
    
	for(int i =2;i <= 8 ;i ++)
	{
		for(int j =0 ;j < 7 ;j ++)
		{
			if(!sq(b[i][j],b[1][j]) )
				return 0 ; 
		}
	}
	if(sq(b[1][0],b[1][1]) && sq(b[1][1],b[1][2]) && sq(sqrt(2.0)*b[1][2],b[1][3])&&sq(b[1][3],b[1][4])&&sq(b[1][4],b[1][5])&& sq(sqrt(3.0)*b[1][0],b[1][6]))
		return 1;
	return 0 ;
}
int ok =0 ;
void dfs(int i)
{
	if(ok)
		return;
	if(i == 9)
	{
		if(solve())
		{
			printf("YES\n");
			for(int i =1;i <= 8 ;i ++)
			{
				for(int j =1;j <= 3;j ++)
					printf("%d ",a[i][j]);
				printf("\n");
			}
			ok = 1;
		}
		return;
	}
	do{
		dfs(i+1);	
	}while(next_permutation(&a[i][1],&a[i][4]));
}
int main(){
	for(int i =1 ;i <= 8;i ++)
	{
		for(int j = 1;j <= 3;j ++)
			scanf("%d",&a[i][j]);
		sort(&a[i][1],&a[i][4]);
	}
	dfs(1);
	if(!ok)
		printf("NO\n");
return 0;
}
