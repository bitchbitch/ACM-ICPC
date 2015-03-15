// File Name: kmp.cpp
// Author: darkdream
// Created Time: 2013年12月12日 星期四 22时33分18秒

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
int p[100] = {0};
void kmp(char *a,char *b)
{
  int n = strlen(a);
  int m = strlen(b);
  int q = -1; 
  for(int i= 0;i < n;i ++)
  {
     while(q >= 0 && b[q+1] != a[i])
		 q = p[q];
	 if(b[q+1] == a[i])
		 q = q + 1;
	 if(q == m -1 )
	 {	 
		 printf("%d",i-m+1);
	     q = p[q];
	 }
  }
}
int main(){
  char str1[100000];
  char str[100];
  scanf("%s %s",str1,str);
  int m = strlen(str);
  int k = -1 ; 
  p[0] = -1 ; 
  for(int i = 1;i < m;i ++)
  {
     while(k >= 0 && str[k+1] != str[i] )
		 k = p[k];
	  if(str[k+1] == str[i])
		  k = k +1;
       p[i] = k ;
  }
  kmp(str1,str);

return 0;
}
