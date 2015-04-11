// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年11月07日 星期五 19时01分47秒

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
int n ; 
int main(){
    srand(time(NULL));
    freopen("in","w",stdout);	
	int n = 5; 
	int m = 20000; 
	printf("%d %d\n",n,m);
	for(int i = 1;i <= n;i ++)
	{
	  printf("%d ",rand()%200 -100);
	}
	printf("\n");
    while(m--)
	{
	   int p = rand()%5;
	   if(p == 1)
	   {
		   int k = rand()%n +1; 
		   int st;
		   if(k != n )
		      st = rand()%(n-k) + 1; 
		   else st = 1; 
		   printf("MAKE-SAME %d %d %d\n",k,st,rand()%200-100);
	   }else if(p == 2 ){ 
		   int k = rand()%n +1; 
		   int st; 
		   if(k != n )
		    st= rand()%(n-k) + 1; 
		   else st = 1; 
		   printf("REVERES %d %d\n",k,st); 
	   }else if(p == 3){
		   int k = rand()%n +1; 
		   int st ; 
		   if(k != n )
		    st = rand()%(n-k) + 1; 
		   else st = 1; 
		   printf("GET-SUM %d %d\n",k,st);
	   }else printf("MAX-SUM\n");
	}
	return 0;
}
