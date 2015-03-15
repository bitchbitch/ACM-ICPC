// File Name: duipai.cpp
// Author: darkdream
// Created Time: 2014年07月23日 星期三 20时21分37秒

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

int main(){
  FILE *p = fopen("out1.txt","r");
  FILE *p1 = fopen("output.txt","r");
  char str[1000];
  char str1[1000];
  while(fgets(str,1000,p))
  {
       fgets(str1,1000,p1);
	   if(strcmp(str,str1) != 0 )
	   {
	    printf("***\n");
	   }
  }
return 0;
}
