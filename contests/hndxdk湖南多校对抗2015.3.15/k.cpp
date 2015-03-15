// File Name: k.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 22时06分25秒

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
int x;
char str[100000];
int main(){
    int n , m; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
        for(int i= 1;i <= n;i ++)
		{
		   scanf("%d %s",&x,str);
		}
		if(n == 1)
	    {
		  printf("YES\n");
		  continue;
		}
	    int tx = (n-1)/3;
		int ty = tx;
		if((n-1) % 3 == 1)
		{
		   tx ++ ; 
		}else if((n-1)%3 == 2){
            tx++;
			ty ++;
		}
		if(m> ty && m <= n-tx)
			printf("YES\n");
		else printf("NO\n");
	}
return 0;
}
