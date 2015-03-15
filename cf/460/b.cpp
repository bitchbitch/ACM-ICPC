// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年08月20日 星期三 23时44分55秒

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
LL a ,b,c;
LL ans[200]; 
LL P(int x, int y )
{
	LL temp = 1; 
	for(int i =1 ;i <= y ;i ++)
		temp *= x;
	return temp ;
}
int is(LL t , int k)
{
	int sum = 0 ; 
	while(t)
	{
		sum += t % 10 ; 
		t /= 10;
	}
	if(sum == k )
		return 1;
	return 0 ;
}
int main(){
	int num = 0 ; 
	for(a = -100;a <= 100 ;a ++ )
		for(b = -100;b <= 100 ;b++)
		   for(c= -100; c <= 100 ; c ++)
			{
				num = 0 ;
				for(int i = 1;i <= 81;i ++)
				{
					LL temp = b*P(i,a) + c; 
					if(is(temp,i)&& temp < 1e9)
					{
						num ++ ; 
						ans[num] = temp;
						if(temp <= 0)
							printf("****");
					}
				}
			}
	return 0;
}
