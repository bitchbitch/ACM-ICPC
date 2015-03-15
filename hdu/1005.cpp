// File Name: 1005.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 17时33分54秒

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
#include<climits>
#include<queue>

using namespace std;
int f[100];
int hs[100];
int main(){
	int a ,b , n ;
	while(scanf("%d %d %d",&a,&b,&n) != EOF,n){
		f[0] =1; 
		f[1] =1;
		memset(hs,0,sizeof(hs));
		hs[11] = 1;
		int be,en;
		int p = 1; 
		for(int i = 2;i <= 99;i ++){
			f[i] = (a * f[i-1] + b * f[i-2])%7;
			int t = f[i-1]*10 + f[i];
			if(!hs[t])
			{
			  hs[t] = i ;
			}
			else {
	        	be = hs[t]-1;
				en = i-2;
				break;
			}
		}
		n = n -1;
		if(n <= be)
			printf("%d\n",f[n]);
		else printf("%d\n",f[(n-be)%(en-be+1) +be]);
	}
	return 0;
}
