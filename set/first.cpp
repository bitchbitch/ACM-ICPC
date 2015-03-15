// File Name: first.cpp
// Author: darkdream
// Created Time: 2014年07月15日 星期二 19时41分13秒

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

int main(){

	long long n ; 
	while(scanf("%lld",&n) != EOF)
	{
	  long long x; 
	  set<long long>a;
	  set<long long>::iterator l,en,be;
      set<long long>::iterator r;
	  long long sum = 0 ;
	  scanf("%lld",&x);
	  sum += x;
	  a.insert(x);
	  for(int i = 2;i <= n;i ++)
	  {
	      scanf("%lld",&x);
		  if(a.find(x) != a.end()) continue;
		  
		  a.insert(x);
		  en = a.end();
		  --en;
		  if(a.find(x) == en)
		  {
		     l = a.find(x);
			  --l ; 
		//	 printf("**%lld\n",*l);
			 sum += x - *l;
		  }else if(a.find(x) == a.begin()){
			  l = a.find(x);
			  ++l  ; 
			  sum += *l -x;
		//	  printf("**%lld\n",*l);
		  }else {
		      l = a.find(x);
			  r = a.find(x);
			  r = ++r;
			  l = --l;
		//	  printf("**%lld %lld\n",*l,*r);
			  sum += min(x-*l,*r-x);
		  }

	  }
	  printf("%lld\n",sum);
	}
	
	return 0;
}
