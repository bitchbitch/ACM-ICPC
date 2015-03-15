// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年12月24日 星期二 21时56分14秒

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
char str[1000000];
int main(){
  scanf("%s",str);
  int len  = strlen(str); 
  __int64  suma = 0 ; 
  __int64  sumb = 0 ;
  int k, i , j; 
  for( k =0;k  < len;k ++)
	  if(str[k] == '^')
		  break;
  for( i = 0 ;i  < k;i ++)
	  if(str[i] !='=')
		 suma += (str[i]- '0' )*(k-i);
  for( j = k+1;j  < len;j ++)
	if(str[j] != '=')
	     sumb += (str[j] - '0') * (j-k);
  if(suma == sumb )
	  printf("balance\n");
  else if(suma > sumb)
	  printf("left\n");
  else printf("right");
return 0;
}
