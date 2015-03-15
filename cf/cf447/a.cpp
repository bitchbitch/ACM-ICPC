// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年07月13日 星期日 20时47分08秒

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
#include<climits>
#include<queue>

using namespace std;
int hs[1000];
int a[1000];
int main(){
   int ok = -1; 
   int n , m ; 
   memset(hs,0,sizeof(hs));
   scanf("%d %d",&m,&n);
   for(int i =1 ;i <= n;i  ++)
   {
      scanf("%d",&a[i]);
   }
   for(int i = 1;i <= n;i ++){
	  if(hs[a[i]% m] == 1)
	  {
	    ok = i;
		break;
	  }else hs[a[i]%m] = 1; 
   }
   printf("%d\n",ok);
return 0;
}
