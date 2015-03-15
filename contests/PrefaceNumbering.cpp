// File Name: PrefaceNumbering.cpp
// Author: darkdream
// Created Time: 2013年11月25日 星期一 22时17分34秒
/*
ID: dream.y1
PROG: preface
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

int a[10] = {1000,500,100,50,10,5,1};
char b[10] = {'M','D','C','L','X','V','I'};
int ans[3506][10];
int main(){
  freopen("preface.in","r",stdin);
  freopen("preface.out","w",stdout);
  for(int i = 1;i <= 3500;i++)
  {
	  int temp = i; 
      for(int j =0;j <= 6;j ++)
	  {

         if(temp/a[j] != 0  )
		 {
			if(temp/a[j] <= 3)
				ans[i][j] += temp/a[j];
			else 
			{
			     ans[i][j] += 1;
				 ans[i][j-1]+= 1;
			}
			temp = temp % a[j];
		 }
	  
	  }
	  for(int j = 1; j <= 6; j +=2 )
	  {
	    if(ans[i][j] >= 2 )
		{
		  ans[i][j] -= 2; 
		  ans[i][j-1] += 1; 
		}
	  }
	  

  }
  for(int i = 2;i <= 3500;i ++ )
  {
    for(int j= 0 ;j <= 6; j ++)
	{
	  ans[i][j] += ans[i-1][j];
	}
  }
  int n;
  scanf("%d",&n);
  for(int i = 6;i >= 0 ;i --)
  {
    if(ans[n][i])
		printf("%c %d\n",b[i],ans[n][i]);
  }


return 0;
}
