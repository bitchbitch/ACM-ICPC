// File Name: 489c.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 08时47分56秒

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
int str[1005];
int main(){
   int m , s; 
   scanf("%d %d",&m,&s);
   int k = s /9;
   if(m*9 < s)
   {
	   printf("-1 -1\n");
       return 0 ; 
   }
   if(s == 0 )
   {
     if(m == 1)
		 printf("0 0\n");
	 else printf("-1 -1\n");
	 return 0  ;
   }
   int t = s - k * 9;
   if(t == 0 )
   {
      k = k -1; 
	  t = 9;
   }
   if(m - k <=  1)
   {
     if(m - k == 1 )
         printf("%d",t);
	 for(int i = 1;i <= k;i ++)
		 printf("9");
   }else{
     printf("1");
	 for(int i = 1;i <= m-k -2 ;i ++)
		 printf("0");
	 printf("%d",t-1);
	 for(int i = 1;i <= k ;i ++)
		 printf("9");
   }
   printf(" ");
   for(int i = 1;i <= k; i ++)
	   printf("9");
   if(k != m)
   printf("%d",t);
   for(int i = 1;i <= m - k - 1; i ++)
	   printf("0");
return 0;
}
