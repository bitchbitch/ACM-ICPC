// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 12时22分58秒

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
int t;
LL L , R;
int main(){
     scanf("%d",&t);
	 for(int CA = 1; CA <= t;CA++)
	 {
	    scanf("%lld %lld",&L,&R); 
		LL ans1,ans2; 
		ans1 = ans2 = 0  ;
		LL i ; 
		for(i = 63 ;i >= 0 ;i --)
	    {
	       LL ta = (L >> i) &1;
		   LL tb = (R >> i) &1;
		   if(ta == tb)
		   {
		      ans1 += ta << i ; 
		      ans2 += ta << i ; 
		   }else
		   {
			   break;
		   }
		}
		for(LL j = i ;j >= 0;j --)
		{
	        ans1 += 1ll << j ; 	
		}
		printf("Case %d: %lld %lld\n",CA,ans1,ans2);
	 }
return 0;
}
