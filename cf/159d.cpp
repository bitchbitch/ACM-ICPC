// File Name: 159d.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 16时37分50秒

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
#define LL long long 
char str[2005];
LL sum[2004];
int is(int a,int b)
{
	 int k = (a+b)/2;
     for(int i = a ;i <= k ;i ++ )
	 {
	     if(str[i] != str[b-i+a])
			 return 0 ;
	 }
	 return 1;
}
int main(){
    scanf("%s",&str[1]);
	LL ans = 0 ; 
	int len =  strlen(&str[1]);
	sum[0] = 0 ;
	for(int i = 1 ;i <=len ;i ++)
	{
	     for(int j = 1;j <= i ;j ++)
		 {
		    if(is(j,i))
			{
			   ans += sum[j-1];
			   sum[i] ++ ;
			}
		 }
		 sum[i] += sum[i-1];
	}
	printf("%I64d\n",ans);
	return 0;
}
