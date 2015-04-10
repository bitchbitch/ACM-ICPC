// File Name: hysbz1208.set.cpp
// Author: darkdream
// Created Time: 2015年04月09日 星期四 19时20分33秒

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
multiset<int > a[2];
multiset<int >::iterator tt; 
int main(){
	int n;
	int st,v;
	LL sum = 0 ; 
	scanf("%d",&n);
	while(n --)
	{
		scanf("%d %d",&st,&v);
		if(a[!st].size() != 0 )
		{
			tt = a[!st].lower_bound(v);
			if(tt == a[!st].end())
			{
				tt-- ;
				sum += abs(*tt-v);
				a[!st].erase(tt);
			}else{
				if(tt == a[!st].begin()){
					sum += abs(*tt-v);
				    a[!st].erase(tt);
				}else{
					int mi = 1e9;
					mi = abs(*tt-v);
					tt--;
					if(abs(*tt-v) <= mi){
						sum += (abs(*tt-v))	;
						a[!st].erase(tt);
					}else{
						tt++ ;
						sum += (abs(*tt-v))	;
						a[!st].erase(tt);
					}
				}
			}
		}else
			a[st].insert(v);
		sum = sum % 1000000;
	}
   
	printf("%lld\n",sum);
return 0;
}
