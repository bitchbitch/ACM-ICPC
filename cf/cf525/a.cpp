// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 00时44分21秒

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
char str[1000005];
int hs[1000];
int main(){
   int n ;
   scanf("%d",&n);
   scanf("%s",&str[1]);
   int sum = 0; 
   for(int i = 1;i <= 2*n-2;i ++ )
   {
       if(str[i] <= 'z' && str[i] >= 'a') 
	   {
	     hs[str[i] -'a'] ++ ;
	   }else{
	     if(hs[str[i]-'A'] == 0 )
			 sum ++;
		 else hs[str[i]-'A'] -- ; 
	   }
   }
   printf("%d\n",sum);
return 0;
}
