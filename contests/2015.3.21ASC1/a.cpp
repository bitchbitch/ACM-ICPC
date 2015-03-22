// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 23时08分24秒

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
char str[2005];
int num[2005];
int len ;
void solve()
{
   for(int i = 0 ;i <= len; i++)
	   num[i] = str[i] - '0';
   for(int i = 0 ;i <= len/2 ;i ++ )
   {
       swap(num[i],num[len-i]); 
   }
}
void chu(){
  int tmp = 0 ; 
  for(int i= len ;i >= 0; i --)
  {
      int k = (tmp * 10 + num[i]);
	  num[i] = k /2; 
	  tmp = k % 2; 
  }
  if(num[len] == 0 )
	  len -- ; 
}
void jian(){
   for(int i = 0 ;i <= len ;i ++)
   {
       if(num[i] == 0 )
		   num[i] = 9;
	   else{num[i] -- ; 
	       break;
	   }
   }
   if(num[len] == 0)
	  len -- ; 
}
void print()
{
  for(int i = len; i >= 0 ;i --)
  {
    printf("%d",num[i]);
  }
  printf("\n");
}
int main(){
	freopen("china.in","r",stdin);
	freopen("china.out","w",stdout);
	scanf("%s",str);
    len = strlen(str);
	len-- ;
	solve();
	if(num[0] % 2 == 1)
	{
	   chu();
	   print();
	   return 0 ; 
	}
    chu();
	jian();
	while(num[0]%2 == 0)
		jian();
	print();
return 0;
}
