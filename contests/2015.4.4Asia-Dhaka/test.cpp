// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 17时05分35秒

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

int main(){
  FILE *p = fopen("output1","r");
  FILE *p1 = fopen("output","r");
  freopen("tt","w",stdout);
  char str[1000];
  char str1[1000];
  int tt = 0;
  while(fgets(str,1000,p))
  {
       fgets(str1,1000,p1);
	   tt ++ ; 
       if(strcmp(str,str1) != 0 )
       {
        printf("***%d \n",tt);
		puts(str);
		puts(str1);
       }
  }
return 0;
}
