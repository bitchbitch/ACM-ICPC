// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月14日 星期日 11时20分20秒

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
char str[100000];
char temp[][10] = {"Apple","iPhone","iPod","iPad","Sony"};
int len[6] = {5,6,4,4,4};
int num[6];
int main(){
     while(scanf("%s",str) != EOF)
	 {
	    char *p = str;
		while(1)
		{
		 memset(num,-1,sizeof(num));
		 for(int i = 0 ;i <= 4;i ++)
		 {
		   if(strstr(p,str))
		   {
		     num[i] = strstr(p,str); 
		   }
		 }
		}
	 }
return 0;
}
