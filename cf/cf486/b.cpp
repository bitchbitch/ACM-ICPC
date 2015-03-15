// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 23时03分52秒

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
int M[200][200];
int A[200][200];
int n , m ;
int dfsr(int k )
{
  for(int i = 1;i <= n;i ++)
	  if(M[i][k] == 0 )
		  return 0 ;
  return 1;
}
int dfsc(int k )
{
  //printf("%d\n",k);
  for(int i = 1;i <= m;i ++)
  {
//	  printf("***%d %d\n",k,i);
	  if(M[k][i] == 0 )
		  return 0 ;
  }
  return 1;
}
int main(){
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= n;i ++)
	   for(int j = 1;j <= m;j ++)
	   {
	      scanf("%d",&M[i][j]);
	      A[i][j] = 1; 
	   }
   for(int i = 1;i <= n;i ++)
    for(int j = 1;j <= m;j ++)
	{
	  if(M[i][j] == 0)
	  {
		//printf("***\n");
	    for(int s = 1;s <= m ;s ++)
		{
			A[i][s] = 0 ; 
		}
	    for(int s = 1;s <= n ;s ++)
		{
			A[s][j] = 0 ; 
		}	
	  }
	}
   for(int i = 1;i <= n;i ++)
   {
       for(int j = 1;j <= m;j ++)
	   {
	       int tmp = 0 ; 
		   for(int s = 1 ; s <= m ;s ++ )
			   tmp |= A[i][s];
		   for(int s = 1 ; s <= n ;s ++ )
			   tmp |= A[s][j];
		   if(tmp != M[i][j])
		   {
		      puts("NO");
			  return 0 ; 
		   }
	   }
   }
   printf("YES\n");
   for(int i = 1;i <= n;i ++)
   {
      for(int j = 1;j <= m ;j ++)
			printf("%d ",A[i][j]);
	  printf("\n");
   }
return 0;
}
