// File Name: runaroundnumbers.cpp
// Author: darkdream
// Created Time: 2013年11月30日 星期六 14时35分49秒
/*
ID: dream.y1
PROG: runround
LANG: C++
*/
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

int is(int n)
{
   //printf("%d\n",n);
   int a[11];
   int hs[10] = {0};
   int hsnum[10] = {0};
   int len = -1; 
   while(n)
   {
     len ++ ; 
	 if(hsnum[n%10] == 1 || n%10 == 0)
		 return 0;
	 else  hsnum[n%10] = 1 ;
	 a[len] = n % 10 ; 
	 n = n /10;
   }
   for(int i = 0;i <= len/2;i ++)
   {
      int temp = a[i];
	  a[i] = a[len-i];
	  a[len-i] = temp;

   }
   //for(int  i = 0;i <= len ;i ++)
	 //  printf("%d",a[i]);
  // printf("\n");
   int sum = 0 ; 
   int k = 0 ;
   while(1)
   {
	 int temp = (k + a[k]) % (len +1);
     if(hs[temp] == 0)
	 {
	      hs[temp] = 1;
          sum ++;
		  k = temp;
	//	  printf("%d\n",k);
	 }else break;
   }
   if(sum == len + 1)
		 return 1;
   return 0; 

}
int main(){
    //freopen("runround.in","r",stdin); 
    //freopen("runround.out","w",stdout); 
	int n ; 
	scanf("%d",&n);
    for(;;)
	{
	   n++;
	   if(is(n))
	   {
	     printf("%d\n",n);
		 break;
	   }
	}
	return 0 ; 
}
