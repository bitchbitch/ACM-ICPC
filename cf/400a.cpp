// File Name: 400a.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 08时48分04秒

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
char str[100];
int is(int i , int j )
{
   for(int k = i;k <= 12;k += j)
   {
      if(str[k] == 'O')
		  return 0;
   }
   return 1 ; 
}
int main(){
    int n;
	scanf("%d",&n);
	for(int i =1;i<= n; i ++)
	{	
		scanf("%s",&str[1]);
	    int sum = 0 ;
		int ok ; 
		ok = 0;
		int a[10] = {0};
		for(int i =1;i <= 1;i ++)
		{
		   if(is(i,1))
			   ok = 1 ; 
		}
		if(ok)
			a[1]++ ;
		sum += ok ;
		ok = 0;
		for(int i =1;i <= 2;i += 1)
		{
		   if(is(i,2))
			   ok = 1 ; 
		}
		if(ok)
			a[2]++ ;
		sum += ok ;
		ok = 0;
		for(int i =1;i <= 3;i +=1)
		{
		   if(is(i,3))
			   ok = 1 ; 
		}
		if(ok)
			a[3]++ ;
		sum += ok ;
		ok = 0;
		for(int i =1;i <= 4;i ++)
		{
		   if(is(i,4))
			   ok = 1 ; 
		}
		if(ok)
			a[4]++ ;
		sum += ok ;
		ok = 0;
		for(int i =1;i <= 6;i ++)
		{
		   if(is(i,6))
			   ok = 1 ; 
		}
		if(ok)
			a[5]++ ;
		sum += ok ;
		ok = 0;
		for(int i =1;i <= 12;i ++ )
		{
		   if(is(i,12))
			   ok = 1 ; 
		}
		if(ok)
			a[6]++ ;
		sum += ok ;
		printf("%d ",sum);
	    if(a[6])
			printf("1x12 ");
	    if(a[5])
			printf("2x6 ");
	    if(a[4])
			printf("3x4 ");
	    if(a[3])
			printf("4x3 ");
	    if(a[2])
			printf("6x2 ");
	    if(a[1])
			printf("12x1 ");
		printf("\n");
	}     
return 0;
}
