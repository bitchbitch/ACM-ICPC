// File Name: h.cpp
// Author: darkdream
// Created Time: 2015年04月19日 星期日 13时58分56秒

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

int a[4];
int solve(int k )
{
	 if(k == 1)
	 {
		 a[1] = (a[3] + 2*a[2])/2;
         return a[1];
	 }else if(k == 2){
		 a[2] = (a[1] * 2 - a[3])/2;
		 return a[2];
	 }else {
		 a[3] = (a[1] - a[2])*2;
		 return a[3];
	 }
}
char str[100];
int ch(int l ,int r )
{
	 int ans = 0 ; 
	 for(int i = l ;i <= r;i ++)
	 {
	    ans = ans * 10 + str[i] - '0';
	 }
	 return ans ;
}
int main(){
    int n ; 
	scanf("%d",&n);
	while(n--){
		int ok = 0 ; 
		for(int i = 1;i <= 3;i ++)
		{
		   scanf("%s",str);
		   if(str[0] == '?')
		   {
		      ok = i ; 
		   }
		   a[i] = ch(0,strlen(str)-1);
		   
		}
		printf("%d\n",solve(ok));
	}
return 0;
}
