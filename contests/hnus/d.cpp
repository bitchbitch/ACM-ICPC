// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年09月12日 星期五 09时33分05秒

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
char str[300];
char temp[300];
char str1[300];
int main(){
   int n ;
   while(scanf("%d",&n) != EOF,n)
   {
	memset(str,0,sizeof(str));
	memset(str1,0,sizeof(str1));
	memset(temp,0,sizeof(temp));
    scanf("%s",str);
	scanf("%s",&str[n]);
	scanf("%s",str1);
	int ok = 0 ;
    for(int i = 1;i <= 2*n;i ++)
	{
	   int b1 = 0 ;
	   int b2 = n;
	   int t = -1;
	   for(int j = 1;j <= n;j ++)
	   {
	      t ++ ;
		  temp[t] = str[b2];
		  b2 ++ ;
		  t ++;
		  temp[t] = str[b1];
		  b1 ++ ; 
	   }
	   //puts(temp);
	   if(strcmp(temp,str1) == 0 )
	   {
	     ok  = 1 ; 
		 printf("%d\n",i);
		 break;
	   }
	   strcpy(str,temp);
	}
    if(!ok)
	   printf("-1\n");
   }
return 0;
}
