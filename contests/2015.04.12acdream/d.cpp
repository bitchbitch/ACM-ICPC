// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 19时40分52秒

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
int n ; 
int t; 
char str[300000];
int len ; 
int next[300000];
void get_next()
{
	next[0] = -1; 
    int k = -1; 
	int j =0 ; 
	while(j < len )
	{
	  if(k == -1 || str[j] == str[k])
	  {
	     ++ k ; 
		 ++ j ;
		 next[j] = k ; 
	  }else{
	     k = next[k];
	  }
	}
}
int find(int x)
{
   if(x == 0)
	   return 0; 
   return 1+find(next[x]);
}
int main(){
	scanf("%d",&t);
    while(t--)
	{
      scanf("%s",str);
	  len = strlen(str);
	  scanf("%s",&str[len]);
	  len = strlen(str);
	  get_next();
	  printf("%d\n",find(len));
	}
return 0;
}
