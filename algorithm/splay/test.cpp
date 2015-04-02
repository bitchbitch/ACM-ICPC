// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年11月04日 星期二 21时47分25秒

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
  FILE *p = fopen("out","r");
  FILE *p1 = fopen("out1","r");
  char str[1000000];
  char str1[1000000];
  while(fgets(str,1000000,p))
  {
       fgets(str1,1000000,p1);
       if(strcmp(str,str1) != 0 )
       {
        printf("***\n");
       }else{
		 //  puts(str);
		 //  puts(str1);
	   }
  }
return 0;
}
