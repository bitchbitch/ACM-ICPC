// File Name: fuck.cpp
// Author: darkdream
// Created Time: 2014年08月05日 星期二 15时01分56秒

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
   FILE *p = fopen("output.txt","r");
   FILE *p1 = fopen("output1.txt","r");
   char str[100];
   char str1[100];
  int t = 1 ; 
   while(fgets(str,100,p))
   {
      fgets(str1,100,p1);
	  if(strcmp(str,str1) != 0 )
		  printf("%d****\n",t);
	  t++;
   }
return 0;
}
