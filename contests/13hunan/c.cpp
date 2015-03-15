// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 09时35分22秒

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
char str[7][60];
int main(){
   int n ;
   scanf("%d",&n);
   for(int i = 1;i <= 5;i ++)
   {
      scanf("%s",&str[i][1]);
   }
   
   for(int i = 0;i < 4*n-3 ;i += 4)
   {
      if(str[4][i+2] == '*') 
	  {
	    printf("1");
	  }else if(str[4][i+1] == '*')
		  printf("2");
	  else printf("3");
   }
return 0;
}
