// File Name: 313b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 08时02分38秒

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
char str[100005];
int  sum[100005];
int main(){
   scanf("%s",&str[1]);
   int len = strlen(&str[1]);
   sum[1] = 0 ; 
   for(int i =1;i <= len ;i ++)
   {
     if(str[i+1] == str[i])
      {
	    sum[i] = sum[i-1] + 1;  ; 
	  }else{
	    sum[i] = sum[i-1];
	  }
   }
   int m ; 
   scanf("%d",&m);
   for(int i =1 ;i <= m ;i ++)
   {
      int l, r; 
	  scanf("%d %d",&l,&r);
	  printf("%d\n",sum[r-1]- sum[l-1]);
   }
return 0;
}
