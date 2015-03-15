// File Name: ans.cpp
// Author: darkdream
// Created Time: 2014年11月27日 星期四 20时32分41秒

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
char ans[20];
char str[20];
int x;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
   int n ;
   while(scanf("%d",&n) != EOF)
   {
	  int mi = 0 ; 
      for(int i = 1;i <= n;i ++)
	  {
	     scanf("%s %d",str,&x);
		 if(x > mi)
		 {
			 mi = x; 
			 memcpy(ans,str,sizeof(str));
		 }
	  }
	  printf("%s\n",ans);
   }
return 0;
}
