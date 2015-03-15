// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年09月15日 星期一 21时37分53秒

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
  freopen("in","w",stdout);
  srand(time(NULL));
  int t = 1000 ;
  for(int i =1;i <= t;i ++)
  {
     int n = rand()%10 + 1;
	 printf("%d\n",n);
	 for(int i = 1;i <= n;i ++)
	 {
	   int k = rand()% 5 +1;
	   for(int i = 1;i <= k;i ++)
	   {
	     int t = rand()% 4;
		 if(t == 0 )
			 printf("A");
		 else if(t == 1 )
			 printf("T");
		 else if(t == 2 )
			 printf("G");
		 else printf("C");
	   }
	   printf("\n");
	 }
	 int k = rand()%10  + 1; 
	   for(int i = 1;i <= k;i ++)
	   {
	     int t = rand()% 4 ;
		 if(t == 0 )
			 printf("A");
		 else if(t == 1 )
			 printf("T");
		 else i
			 printf("G");
		 else printf("C");
	   }
	   printf("\n");

  }
  printf("0\n");
return 0;
}
