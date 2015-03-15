// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 12时00分44秒

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
char  str[10][10];
int hsh[10];
int hsl[10];
int hshl[50];
int hslh[50];
int main(){
    while(scanf("%s",&str[1][1]) != EOF)
	{
	   for(int i = 2;i <= 8 ;i ++)
	   {
	     scanf("%s",&str[i][1]);
	   }
	   memset(hsh,0,sizeof(hsh));
	   memset(hsl,0,sizeof(hsh));
	   memset(hshl,0,sizeof(hshl));
	   memset(hslh,0,sizeof(hslh));
	   int ok = 0 ; 
	   for(int i= 1;i <= 8;i ++)
	   {
	      for(int j = 1;j <= 8 ;j ++)
		  {
			  if(str[i][j] == '.')
				  continue;
		      if(hsh[i] == 1)
			  {
			     ok = 1;  
			  }else{
			     hsh[i] = 1 ;
			  }
		      
			  if(hsl[j] == 1)
			  {
			     ok = 1;  
			  }else{
			     hsl[j] = 1 ;
			  }

		      if(hshl[j-i+25] == 1)
			  {
			     ok = 1;  
			  }else{
			     hshl[j-i +25] = 1 ;
			  }

		      if(hslh[j+i] == 1)
			  {
			     ok = 1;  
			  }else{
			     hslh[j+i] = 1 ;
			  }
		  }

	   }
	   if(ok == 1 )
		   printf("invalid\n");
	   else printf("valid\n");
	}
	 
	
	return 0;
}
