// Author: darkdream
// Created Time: 2014年11月06日 星期四 00时24分10秒

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
int main(){
	int n ;
	LL l , r;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		LL ans = 0 ; 
		scanf("%I64d %I64d",&l,&r);
		for(int i = 62 ;i >= 0 ;i --)
		{
			if((r&(1ll << i)) != 0 )
			{
				if((l & (1ll << i)) != 0 )
				{
					ans += (1ll << i);
					r &=  (~(1ll << i));
					l &=  (~(1ll << i));
				}else{
					if((1ll << (i+1))-1 <= r)
					{
						ans +=  (1ll << (i+1)) -1;
					}
					else ans += (1ll << i ) - 1; 
					break;
				}
			}

		}
		printf("%I64d\n",ans);
	}
	return 0;
}
