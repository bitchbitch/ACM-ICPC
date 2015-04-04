/************************************************************
 * Author : darkdream
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-04-04 13:33
 * Filename : d.cpp
 * Description :
 * *********************************************************/
// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 13时07分48秒

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
int t,n,m,l,r; 
int mpxy[100][100][2];
int mpxx[100][100][2];
char str[10];
void change(int i , int j)
{
   int tmp = 0 ; 
   int len = strlen(str);
   int flag = 1;
   int s = 0 ; 
   if(str[0] == '-')
   {
	   flag = -1;
	   s = 1 ;
   }
   for(;s < len;s ++)
   {
      tmp = tmp *10 +(str[s] - '0');
   }
   tmp = tmp * flag;
   mpxy[i][j][0] = l - tmp;    
   mpxy[i][j][1] = r - tmp;
}
int main(){
	scanf("%d",&t);
	while(t--)
	{
	   scanf("%d %d %d %d",&n,&m,&l,&r);
       for(int i = 1; i <= n;i ++)
	   {
	       for(int j = 1;j <= m ;j ++)  
		   {
			   scanf("%s",str);
			   if(str[0] == 'X')
			   {
				   mpxy[i][j][0] = -1e9;
				   mpxy[i][j][1] = 1e9  ;
			   }else{
			       change(i,j);
			   }
			   printf("(%d,%d) ",mpxy[i][j][0],mpxy[i][j][1]);
		   }
		   printf("\n");
	   }
	}
return 0;
}
