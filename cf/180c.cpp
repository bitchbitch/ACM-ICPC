// File Name: 180c.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 08时40分08秒

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
int big;
int small;
char str[100500];
int main(){
    scanf("%s",str);
	int len = strlen(str);
	for(int i = 0 ;i < len; i ++)
	{
		if(str[i] <= 'Z')
		  big ++ ; 
		else 
	      small ++;
	}
	int mi = min(big,small) ;
	int tbig,tsmall;
	tbig = tsmall = 0;
	for(int i = 0 ;i < len;i ++)
	{
	    if(str[i] <= 'Z')
			tbig ++ ; 
		else tsmall ++ ; 
		mi = min(mi,tsmall+big - tbig);
	}
	printf("%d\n",mi);
return 0;
}
