// File Name: duipai.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 20时37分56秒

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
  FILE *p = fopen("output.bl","r");
  FILE *p1 = fopen("output","r");
  char str[1000];
  char str1[1000];
  int tt
  while(fgets(str,1000,p))
  {
       fgets(str1,1000,p1);
       if(strcmp(str,str1) != 0 )
       {
        printf("***\n");
		printf("%s %s\n",str,str1);
       }
  }
return 0;
}
