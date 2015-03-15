// File Name: 对拍.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 20时52分22秒

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
  FILE * X = fopen("/home/plac/problem/output1.txt","r");
  FILE * Y =fopen("/home/plac/problem/output.txt","r");
  char str[100],str1[100];
  for(int i = 1;i <= 1000000;i ++)
  {
    fgets(str,100,X);
	fgets(str1,100,Y);
    if(strcmp(str,str1) != 0)
		printf("%d\n",i);
  }

return 0;
}
