// File Name: 1011.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 14时58分05秒

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
int a[24];
int judge(int x, int y , int x1, int y1)
{
    if(a[x] != a[y])
		return 0 ; 
	if(a[y] != a[x1])
		return 0 ; 
	if(a[x1] != a[y1])
		return 0 ; 
     return 1; 
}
int L()
{
   int tmp;
   tmp = a[5];
   a[5] = a[16];
   a[16] = a[14];
   a[14] = a[3];
   a[3] = tmp;
   tmp = a[11];
   a[11] = a[17];
   a[17] = a[8];
   a[8] = a[2];
   a[2] = tmp ; 
   tmp = a[6];
   a[6] = a[12];
   a[12] = a[13];
   a[13] = a[7];
   a[7] = tmp;
}
int R()
{
   int tmp;
   tmp = a[5];
   a[5] = a[3];
   a[3] = a[14];
   a[14] = a[16];
   a[16] = tmp;
   tmp  = a[11];
   a[11] = a[2];
   a[2] = a[8];
   a[8] = a[17];
   a[17] = tmp;
   tmp = a[6];
   a[6] = a[7];
   a[7] = a[13];
   a[13] = a[12];
   a[12] = tmp ;
}
int S()
{
   int tmp = a[1];
   a[1] = a[7];
   a[7] = a[17];
   a[17] = a[21];
   a[21] = tmp;
   tmp = a[3];
   a[3] = a[13];
   a[13] = a[19];
   a[19] = a[23];
   a[23] = tmp;
   tmp = a[8] ;
   a[8] = a[14];
   a[14] = a[15];
   a[15] = a[9];
   a[9] = tmp;
}
int X()
{
	int tmp;
	tmp = a[1];
	a[1] = a[21];
	a[21] = a[17];
	a[17] = a[7];
	a[7] = tmp ;
    tmp = a[3];
	a[3] = a[23];
	a[23] = a[19];
	a[19] = a[13];
	a[13] = tmp;
	tmp = a[8];
	a[8] = a[9];
	a[9] = a[15];
	a[15] = a[14];
	a[14] = tmp;
}
int CS()
{
   int tmp ; 
   tmp = a[13];
   a[13] = a[5];
   a[5] = a[20];
   a[20] = a[15];
   a[15] = tmp;
   tmp = a[12];
   a[12] = a[11];
   a[11] = a[21];
   a[21] = a[14];
   a[14]  = tmp ;
   tmp = a[16];
   a[16] = a[18];
   a[18] = a[19];
   a[19] = a[17];
   a[17] = tmp;
}
int CX(){
  int tmp ; 
  tmp = a[13];
  a[13] = a[15];
  a[15] = a[20];
  a[20] = a[5];
  a[5] = tmp;
  tmp = a[12];
  a[12] = a[14];
  a[14] = a[21];
  a[21] = a[11];
  a[11] = tmp ;
  tmp = a[16];
  a[16] = a[17];
  a[17] = a[19];
  a[19] = a[18];
  a[18] = tmp ; 
}
int n ;
int mx = 0 ; 
void dfs(int k)
{
    int sum = 0 ; 
	sum += judge(6,7,12,13);
    sum += judge(8,9,14,15);
    sum += judge(0,1,2,3);
    sum += judge(16,17,18,19);
    sum += judge(23,22,21,20);
    sum += judge(4,5,10,11);
	if(sum > mx)
		mx = sum;
    if(k == n)
		return;
	L();
	dfs(k+1);
	R();
	
	R();
	dfs(k+1);
	L();
	
	S();
	dfs(k+1);
	X();
	
	X();
	dfs(k+1);
	S();
	
	CS();
	dfs(k+1);
	CX();
	
	CX();
	dfs(k+1);
	CS();
}
int main(){
   while(scanf("%d",&n) != EOF)
   {
	 mx =0 ; 
     for(int i = 0 ;i <= 23 ;i ++)
	 {
	    scanf("%d",&a[i]);
	 }
     dfs(0);
	 printf("%d\n",mx);
   }
return 0;
}
