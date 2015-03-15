// File Name: 12910.cpp
// Author: darkdream
// Created Time: 2014年08月17日 星期日 12时06分36秒

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
LL  n , p , k , d; 
int main(){
    while(scanf("%lld %lld %lld %lld",&n,&p,&k,&d) != EOF)
	{
	   LL t = (d-1)*d/2;
	   if(p < t )
	   {
		    printf("Wrong information\n");
	       continue;
	   }
	   if(d == 1 )
	   {
	     if(p % k == 0 )
		 {
			for(int i = 1;i <= k ;i ++)
				printf("%lld\n",p/k);
			for(int i = 1;i <= (n-k);i ++)
				printf("0\n");
		 }else{
		    printf("Wrong information\n");
		 }
		 continue;
	   }else{
	      LL t = (0 + d-2)*(d-1)/2 ;
	   }
	}
return 0;
}
