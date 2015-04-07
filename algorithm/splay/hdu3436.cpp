// File Name: hdu3436.cpp
// Author: darkdream
// Created Time: 2015年04月07日 星期二 08时55分57秒

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
set<int> opnum; 
set<int> num;
set<int>::iterator tt ;
int t, n , q; 
char str[100];
int tmp ;
int main(){
	scanf("%d",&t);
	for(int CA = 1; CA <= T;CA++)
	{
		printf("Case %d:\n");
		scanf("%d %d",&n,&q);
		for(int i = 1;i <= q;i ++)
		{
			scanf("%s %d",str,&tmp);
			if(str[0] == 'T'){
				num.insert(tmp);
			}else if(str[0] == 'R'){
		        tt = upper_bound(tmp);
				if(tt == num.end())
				{
				   printf("%d\n",tt);
				}else{
			         	
				}
			}
		}
	}

return 0;
}
