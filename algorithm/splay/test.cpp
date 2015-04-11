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
  FILE *p = fopen("output","r");
  FILE *p1 = fopen("output1","r");
  char str[1000000];
  char str1[1000000];
  int num = 0 ; 
  int sum =0 ; 
  while(fgets(str,1000000,p))
  {
       fgets(str1,1000000,p1);
		num ++ ; 
       if(strcmp(str,str1) != 0 )
       {
        printf("***%d\n",num);
		sum ++ ; 
       }else{
	   }
  }
  printf("%d\n",sum);
return 0;
}
