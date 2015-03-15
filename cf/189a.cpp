// File Name: 189a.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 08时11分26秒

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
int ans[4][4005];
int main(){
    int n , a[4] ;
	memset(ans,0,sizeof(ans));
	scanf("%d %d %d %d",&n,&a[1],&a[2],&a[3]);
	ans[0][0] = 1; 
	for(int i =1;i <= 3;i ++)
	{
	   for(int j = 0;j<= 4000;j++)
	   {
	      if(j < a[i] || ans[i][j-a[i]] == 0)
			  ans[i][j] = ans[i-1][j];
		  else {
		      ans[i][j] = max(ans[i][j-a[i]]+1,ans[i-1][j]);
		  }
	   }

	}
/*	for(int i =1;i <= 3; i ++)
	{
	     for(int j =1;j <= 7;j ++)
			 printf("%d ",ans[i][j]);
		 printf("\n");
	}*/
	printf("%d\n",ans[3][n]-1);
	
	
	return 0;
}
