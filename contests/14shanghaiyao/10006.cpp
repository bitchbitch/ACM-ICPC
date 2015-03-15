// File Name: 10006.cpp
// Author: darkdream
// Created Time: 2014年11月15日 星期六 14时50分49秒

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
int a[12];
char b[20] = "0pqruvwxyz";
int main(){
   int n ;
   scanf("%d",&n);
   while(n --)
   {
	  int ok = 0 ; 
	  for(int i= 1;i <= 10 ;i ++)
	  {
	    scanf("%d",&a[i]);
		if(a[i] != 0)
		{
		  ok = 1; 
		}
	  }
	  if(ok == 0)
	  {
		  printf("0\n");
		  continue;;
	  }
	  ok = 0 ; 
     for(int i = 1;i <= 9;i ++)
	 {
		 if(abs(a[i]) == 1 )
		 {
		   if(a[i] > 0)
		   {
			if(ok)
               printf("+%c",b[i]);
			else {
			   printf("%c",b[i]);
			}
		   }
		   else printf("-%c",b[i]);
		   ok = 1; 
		   continue;
		 }
		 if(a[i] != 0)
		 {
		    if(a[i] > 0 )
			{
			  if(ok != 0 )
			  {
				printf("+%d",a[i]);
			  }else {
			   printf("%d",a[i]) ;
			   ok = 1 ; 
			  }
			}
			else{ printf("%d",a[i]);
			  ok = 1; 

			}
			printf("%c",b[i]);
		 }
	 }
	 int i = 10;
	 if(a[10] != 0)
	 {
		    if(a[i] > 0 )
			{
			  if(ok != 0 )
			  {
				printf("+%d",a[i]);
			  }else {
			   printf("%d",a[i]) ;
			   ok = 1 ; 
			  }
			}
			else printf("%d",a[i]);
	 }
	 printf("\n");
   }
return 0;
}
