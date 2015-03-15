// File Name: 163div2.b.cpp
// Author: darkdream
// Created Time: 2013年01月22日 星期二 23时42分21秒

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
  char a[100];
  int  n ,k ,i,j;
  char temp;
  scanf("%d %d",&n,&k);
  getchar();
  gets(a);
  for (i =1 ; i <= k ; i++ )
  {
    for (j = 0 ;j < n-1 ;j++)
	{
	  if (a[j]== 'B' && a[j+1] == 'G')
	  {
	     temp = a[j];
		 a[j] = a[j+1];
		 a[j+1] = temp;
		 j = j + 1; 
	  }

	}
  }
  puts(a);
return 0;
}
