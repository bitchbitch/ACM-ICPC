// File Name: 最大整数.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 20时02分32秒

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

char num[10][6];
int strcp(int a, int b)
{
	for(int i = 0 ;i <= 5;i ++)
	{
	  if(num[a][i] == '\0' && num[b][i] != '\0' )
	  {
	    if(num[b][i] > num[a][0])
			return 0;
		else return 1;
	  }
	  if(num[b][i] == '\0' && num[a][i] != '\0' )
	  {
	    if(num[a][i] > num[b][0])
			return 1;
		else return 0;
	  }
	  if(num[a][i] > num[b][i])
		  return 1;
	  if(num[b][i] > num[a][i])
		  return 0;
	}
}
int main(){
  int t; 
  scanf("%d",&t);
  while(t--)
  {
    int n;
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i = 1;i <= n;i ++)
	{
	  scanf("%s",num[i]);
	}

	for(int i =1;i <= n;i ++)
	{
	  for(int j= i + 1; j <= n;j ++)
	  {
	    if(!strcp(i,j))
		{
		  char temp[6];
		  memcpy(temp,num[j],sizeof(char)*6);
		  memcpy(num[j],num[i],sizeof(char)*6);
		  memcpy(num[i],temp,sizeof(char)*6);
		}
	  }
	
	}
	for(int i =1 ;i <= n;i ++)
		printf("%s",num[i]);
	printf("\n");
  }
return 0;
}
