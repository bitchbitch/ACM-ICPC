// File Name: rand.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 20时21分15秒

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
	freopen("input","w",stdout);
	srand(time(NULL));
	for(int i = 1;i <= 1 ;i ++)
	{
		int t = rand()%100 + 1 ;
		printf("%d\n",t);
		while(t--)
		{
			if(rand()%2 == 1)
			{
				printf("1 %d\n",rand()%10+1);
			}else{
				printf("2\n");
			}
		}
	}
	return 0;
}
