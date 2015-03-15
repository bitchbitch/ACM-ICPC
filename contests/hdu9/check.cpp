// File Name: chack.cpp
// Author: darkdream
// Created Time: 2014年08月12日 星期二 15时21分38秒

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
char str[100];
char str1[100];
char str2[100];
int main(){
  FILE *p = fopen("output","r");
  FILE *p1 = fopen("output1","r");
  FILE *p2 = fopen("input.txt","r");
  fgets(str2,100,p2);
  int t = 0;
  while(fgets(str,100,p))
  {
     fgets(str2,100,p2);
     fgets(str1,100,p1);
	 if(strcmp(str1,str) == 0)
	 {
		 t ++ ;
		 printf("****%d\n",t);
	     printf("%s %s\n",str,str1);
	     puts(str2);
	 }
  }
return 0;
}

