// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 19时12分04秒

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
int num[100005];
vector<int>yz[100005] ;  
void sai()
{
   for(int i = 2;i <= 100000 ;i ++)
   {
        int k = i ;
		while(k <= 100000)
		{
		   yz[k].push_back(i);
		   k += i ; 
		}
   }
}
int hs[100005];
int main(){
	sai();
    int t; 
	scanf("%d",&t);
	for(int ca = 1; ca <= t; ca ++){
		memset(hs,0,sizeof(hs));
		hs[1] = 2; 
		int n ; 
		scanf("%d",&n);
		for(int i =1 ;i <= n;i ++)
		{
			scanf("%d",&num[i]);
			for(int j =0 ;j < yz[num[i]].size(); j ++){
				hs[yz[num[i]][j]] ++ ; 
			}
		}
		printf("Case #%d: ",ca);
		for(int i = 100000; i >= 1 ;i --){
			if(hs[i] >= 2 )
			{
				printf("%d\n",i);
				break;
			}

		}
		 
	}
return 0;
}
