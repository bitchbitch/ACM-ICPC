/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-07 09:55
 * Filename : 476b.cpp
 * Description :
 * *********************************************************/
// File Name: 476b.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 09时28分59秒

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
double dp[14][40];
char str1[20];
char str2[20];
int main(){
    scanf("%s",&str1[1]);
	scanf("%s",&str2[1]);
	int len = strlen(&str1[1]);
	dp[1][15] = 1;
	double x ,y;
	int site = 15 ; 
	for(int i = 1;i <= len ;i++)
	{
	  if(str1[i] == '+')
		  site ++ ; 
	  else site --;
	}
	for(int i = 1 ;i <= len;i ++)
	{
		  if(str2[i] == '+')
		  {
		      x = 1; 
			  y = 0;
		  }else if(str2[i] == '-'){
		      x = 0 ; 
			  y = 1 ; 
		  }else{
		      x = 0.5 ; 
			  y = 0.5 ; 
		  }
	    for(int j = 1;j <= 30;j ++)
		{
		  dp[i+1][j+1] += dp[i][j]*x;
		  dp[i+1][j-1] += dp[i][j]*y;
		}
		
	}
	printf("%.9lf\n",dp[len+1][site]);
return 0;
}
