// File Name: rand.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 16时26分21秒

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
	printf("100\n");
	for(int i = 1;i <= 100 ;i ++)
	{
	int p = rand() % 100000 + 1; 
	printf("%d\n",p);
   for(int i = 1;i <= p;i ++ )
	   printf("%d %d ",rand()%100000+1,rand()%100000 + 1);
   printf("\n");	
	}
return 0;
}
