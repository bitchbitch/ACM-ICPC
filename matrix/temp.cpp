// File Name: temp.cpp
// Author: darkdream
// Created Time: 2014年09月17日 星期三 11时35分45秒

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
#define m 10007
using namespace std;
LL  n,x,y ,k ; 
struct Matrix
{
   LL   mat[4][4];
   void clear()
   {
      memset(mat,0,sizeof(mat));
   }
   void output()
   {
     for(int i = 0  ;i < n ;i ++)
	 {
	   for(int j = 0 ;j < n ;j ++)
		   printf("%lld ",mat[i][j]);
	 printf("\n");
	 }
   }
   void init()
   {
	  clear();
	  mat[0][0] = (x*x ) %m ; 
	  mat[0][1] =  y * y  %m ;
	  mat[0][2] =  2*x* y%m;
	  mat[1][0] = 1;
	  mat[2][0] = x;
	  mat[2][2] = y;
	  mat[3][0] = 1;
	  mat[3][3] = 1;
	  n = 4 ;
   }
   Matrix operator *(const Matrix &b) const
   {
       Matrix ret;
       ret.clear();
	   for(int i = 0 ;i < n ;i ++)
		   for(int j = 0;j < n;j ++)
		   {
			   for(int s = 0 ;s < n ;s ++)
			   {
		         ret.mat[i][j] =(ret.mat[i][j] + mat[i][s] * b.mat[s][j] %m ) %m  ; // 第I 行  第J  列	    
			   }
		   }
	   return ret;
   }
};
Matrix Pow( Matrix a ,LL t )
{
  Matrix ret;
  ret.clear();
  for(int i = 0 ;i < n ;i ++)
	   ret.mat[i][i] = 1;
  Matrix tmp = a; 
  while(t)
  {
      if(t&1) ret = ret * tmp;
      tmp = tmp * tmp;
	  t >>=1;
  }
  return ret;
}
int main(){

	while(scanf("%lld %lld %lld",&k,&x,&y) != EOF)
	{
	   x %= m; 
	   y %= m;
       Matrix a;
	   a.init();
       //a.output();
	   a = Pow(a,k);
	   //a.output();
	   LL ans = (a.mat[3][0]  + a.mat[3][1]  + a.mat[3][2] + a.mat[3][3] ) %m  ; 
	   printf("%lld\n",ans);
	}
	return 0;
}
