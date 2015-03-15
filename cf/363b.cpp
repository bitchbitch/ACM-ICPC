// File Name: 363b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 09时58分59秒

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
int sum[200000];
int main(){
    int n , m; 
	scanf("%d %d",&n,&m);
	memset(sum,0,sizeof(sum));
	int min = 1e9;
	int ans = 0 ; 
	for(int i =1 ;i<= n;i ++)
	{
        int temp ; 
		scanf("%d",&temp);
		sum[i] = sum[i-1]+temp;
        if(i >= m )
			if(sum[i] - sum[i-m] < min)
			{
				min = sum[i] - sum[i-m];  
			    ans = i-m+1;
			}
	}
	printf("%d\n",ans);
return 0;
}
