// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年07月23日 星期三 20时15分28秒

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

int main(){
    freopen("in.txt","w",stdout);
	printf("100\n");
	srand(time(NULL));
	for(int j = 1;j <= 100;j ++)
	{
		int n = rand()% 100000 ;
		printf("%d\n",n);
		for(int i =1;i <= n;i ++)
		{
			int t = rand()% 2;
			if(t == 0 )
			{
				printf("r %d\n",rand()%1000-500);
			}else {
				printf("a %d\n",rand()%1000-500);
			}
		}
	}
	return 0;
}
