// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年07月13日 星期日 20时47分12秒

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
#include<climits>
#include<queue>

using namespace std;
struct node{
  char c ; 
  int v; 
}p[1005];
char str[1005];
int a[30];
bool cmp(struct node a ,struct node b)
{
  return a.v < b.v;
}
int main(){
    scanf("%s",str);
	int len = strlen(str);
	for(int i =0 ;i < len ;i ++)
	{
	  p[i].c = str[i];
	}
	int k ; 
	scanf("%d",&k);
	int max = 0 ; 
	for(int i =0;i < 26 ;i++)
	{	scanf("%d",&a[i]);
	   if(a[i] > max)
		   max = a[i];
	}
	long long  sum = 0 ; 
	for(int i = 0 ;i < len ;i ++)
	{
	  sum += a[p[i].c -'a']*(i+1);
	}
	for(int i = len +1; i <= len +k ;i++)
	{
	  sum += max * i ;
	}
	printf("%I64d\n",sum);
return 0;
}
