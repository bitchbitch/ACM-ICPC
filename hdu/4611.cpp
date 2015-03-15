// File Name: 4611.cpp
// Author: darkdream
// Created Time: 2013年08月09日 星期五 15时58分50秒

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
char str[1000005];
int main(){
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int t ;
  scanf("%d",&t);
  while(t--)
  {
     scanf("%s",str);
	 int len = strlen(str);
	 int ok = 1; 
	 if(str[0] != 'M' )
		 ok =0 ; 
	 long long total = 0 ;
	 for(int i = 1;i < len ;i ++)
	 {
        if(str[i] == 'M')
			ok = 0;
	    else if(str[i] == 'U')
		   total += 3;
		else total += 1; 
	 }
	 long long  k = 1; 
	 int ok1 = 0 ;
     for(int i = 1; i <= 50;i ++)
	 {
	   if( k >= total  && (k - total) % 6 == 0 )
		   ok1 = 1; 
	   k *= 2;
	     
	 }
	 if(ok1 && ok)
	    printf("Yes\n");
	 else printf("No\n");
  
  }
return 0;
}
