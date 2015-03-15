// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年04月27日 星期六 18时13分53秒

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
char a[100004][200];
int comp(const void *a,const void *b)
{
  return strcmp((char*)a,(char *)b);
}

int main(){

  int n , m ;
  while(scanf("%d %d",&n,&m) !=EOF)
  {
	  getchar();
	  memset(a,0,sizeof(a));
	for(int i = 0 ;i < n;i ++)
	{
	   gets(a[i]);
	}
	qsort(a,n,sizeof(char)*200,comp);
	char str[100];
	for(int i = 1;i <= m ;i ++ )
	{
		int ok = 0 ;
		gets(str);
		int high = n-1 ,low = 0, mid = (high+low)/2;
		while(low <= high)
		{
			mid = (high+low)/2;
			if(strcmp(a[mid],str) == 0)
			{
			  ok = 1;
			  break;
			}
			if(strcmp(a[mid],str) > 0)
				high = mid;
			else
				low = mid+1;
		     
		}
		if(ok != 1)
			printf("YES\n");
		else
			printf("NO\n");

	 
	}
  }
return 0;
}
