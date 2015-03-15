// File Name: zerosum.cpp
// Author: darkdream
// Created Time: 2013年12月11日 星期三 11时58分46秒
/*
ID: dream.y1
PROG: zerosum
LANG: C++
*/
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
int fh[10] ={0};
int n;
void dfs(int k, int value)
{
    if(k == n+1)
	{
	  if(value == 0  )
	  {
		printf("1");
	    for(int i = 2;i <= n;i ++)
         {
		   if(fh[i-1] == 1)
			 printf("+");
		   else if(fh[i-1] == 2)printf("-");
		   else printf(" ");
		   printf("%d",i);
		 }
		printf("\n");
	  }
	  return ;
	}
	if(k >= 2)
	{
	  if(fh[k-2] == 1)
	  {
	      fh[k-1] = 0 ;
		  dfs(k+1,value -(k-1)+ (k-1)*10 + k);
	     
	  }else if(fh[k-2] == 2)
	  {
		  
	      fh[k-1] = 0 ;
		  dfs(k+1,value + (k-1) - (k-1)*10 - k);
	  }
	}
	fh[k-1] = 1;
	dfs(k+1,value + k);
	fh[k-1] = 2 ;
	dfs(k+1,value - k);

}
int main(){
 freopen("zerosum.in","r",stdin);
 freopen("zerosum.out","w",stdout);
   fh[0] = 1;
	scanf("%d",&n);
   dfs(2,1);
return 0;
}
