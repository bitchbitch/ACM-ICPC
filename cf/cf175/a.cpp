// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年11月01日 星期六 08时30分05秒

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
char str[1000];
int len ;
int mx = -1 ;
int solve(int l , int r)
{
 if(l != r && str[l] == '0')
	 return -1;
  if(r-l+1 > 7 || r < l)
	  return -1;
  int temp = 0 ; 

  for(int i = l; i <= r ;i ++)
  {
    temp*= 10 ; 
	temp += str[i] - '0';
  }
  if(temp > 1000000)
	  return -1;
  return temp;
}
int main(){
     scanf("%s",str);
	 len = strlen(str);
	 for(int i = 0;i < len ;i ++)
	 {
	    for(int j = i;j <= i + 6;j ++)
		{
		 if(solve(0,i-1) != -1 &&solve(i,j) != -1 && solve(j+1,len-1) != -1)
		 { 
			 int tt = solve(0,i-1) + solve(i,j) + solve(j+1,len-1);
		     if( tt > mx)
			 {
				 mx = tt;
	//		    printf("%d %d",i,j);
			 }
		 }
		}
	 }
	 printf("%d\n",mx);
return 0;
}
