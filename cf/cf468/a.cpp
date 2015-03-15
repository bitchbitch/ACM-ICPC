// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月20日 星期六 20时57分23秒

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
    int n ; 
	scanf("%d",&n);
	if(n <= 3 )
	{
		printf("NO");
	    return 0 ;
	}
    if(n % 4 == 1)
	{
	   puts("YES");
       int num  = 0 ;
	   for(int i = n ;i > 5;i -= 2)
	   {
	         printf("%d - %d = %d\n",i,i-1,1);
			 num ++ ;
	   }
	   for(int i = 1;i <= num/2;i ++ )
	   { 
	         printf("1 - 1 = 0\n");   
	   }
	   puts("4 * 5 = 20");
	   puts("2 - 1 = 1");
	   puts("3 + 1 = 4");
	   puts("20 + 4 = 20");
	   for(int i = 1;i <= num/2 ;i ++)
		   printf("24 + 0 = 24\n");
	}
	if(n % 4 == 2 )
	{
	   puts("YES");
       int num  = 0 ;
	   for(int i = n ;i > 6;i -= 2)
	   {
	         printf("%d - %d = %d\n",i,i-1,1);
			 num ++ ;
	   }
	   for(int i = 1;i <= num/2;i ++ )
	   { 
	         printf("1 - 1 = 0\n");   
	   }
	   puts("4 * 5 = 20");
	   puts("6 - 3 = 3");
	   puts("2 - 1 = 1");
	   puts("3 + 1 = 4");
	   puts("20 + 4 = 24");
	   for(int i = 1;i <= num/2 ;i ++)
		   printf("24 + 0 = 24\n");
	}
	if(n % 4 == 3)
	{
       puts("YES");
	   int num  = 0 ;
	   for(int i = n ;i > 7;i -= 2)
	   {
	         printf("%d - %d = %d\n",i,i-1,1);
			 num ++ ;
	   }
	   for(int i = 1;i <= num/2;i ++ )
	   { 
	         printf("1 - 1 = 0\n");   
	   }
	   puts("4 * 5 = 20");
	   puts("7 - 6 = 1");
	   puts("2 * 1 = 2");
	   puts("3 - 1 = 2");
	   puts("2 + 2 = 4");
	   puts("20 + 4 = 24");
	   for(int i = 1;i <= num/2 ;i ++)
		   printf("24 + 0 = 24\n");
	    
	}
	if(n % 4 ==  0)
	{
	   puts("YES");
       int num  = 0 ;
	   for(int i = n ;i > 5;i -= 2)
	   {
	         printf("%d - %d = %d\n",i,i-1,1);
			 num ++ ;
	   }
	   for(int i = 1;i <= num/2;i ++ )
	   { 
	         printf("1 - 1 = 0\n");   
	   }
	   puts("1 * 2 = 2");
	   puts("2 * 3 = 6");
	   puts("6 * 4 = 24");
	   for(int i = 1;i <= num/2 ;i ++)
		   printf("24 + 0 = 24\n");
	}
return 0;
}
