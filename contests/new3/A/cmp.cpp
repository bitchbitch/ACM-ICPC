// File Name: cmp.cpp
// Author: darkdream
// Created Time: 2014年12月08日 星期一 19时23分23秒

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
  FILE *p = fopen("A.out","r");
  //FILE *p1 = fopen("output.txt","r");
  char str[1000];
  char str1[1000];
  int sum = 0; 
  while(fgets(str,1000,p))
  {
	  //fgets(str1,1000,p1);
      /* if(strcmp(str,str1) != 0 )
       {
        printf("***\n");
       }*/
	  if(str[0] == 'Y')
		  sum ++ ; 
  }
  printf("%d\n",sum);
return 0;
}
