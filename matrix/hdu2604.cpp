// File Name: hdu2604.cpp
// Author: darkdream
// Created Time: 2014年09月17日 星期三 15时51分23秒

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
struct Matrix{
   int mat[2][2];

}a,b;
int main(){
  int l , m ; 
  while(scanf("%d %d",&l,&m) != EOF)
  {
	   if(l < 3 )
         printf("0\n");
       a.mat[1][1] = a.mat[1][2] = a.mat[2][1] = a.mat[2][2] = 1;
	   for(int i = 3;i <= l ;i ++  )
	   {
	      b.mat[1][1] = a.mat[1][2];
		  b.mat[1][2] = a.mat[2][2];
		  b.mat[2][1] = (a.mat[1][1] + a.mat[1][2])% m;
		  b.mat[2][2] = (a.mat[2][1] + a.mat[2][2])% m;  
	      a = b; 
	   }
	   /*for(int i = 1;i <= 2;i ++)
	   {
	     for(int j = 1;j <= 2;j ++)
			 printf("%d ",a.mat[i][j]);
		 printf("\n");
	   }*/
	   int ans = a.mat[1][1] + a.mat[1][2] + a.mat[2][1] + a.mat[2][2];
	   ans = ans % m ; 
	   printf("%d\n",ans);
  }
return 0;
}
