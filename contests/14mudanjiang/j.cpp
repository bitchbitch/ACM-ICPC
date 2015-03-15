// File Name: j.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 12时46分06秒

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
char temp[100];
char str[100];
char a[100];
char b[100];
char c[100];
int len ;
void jiea(int l , int r){
  memset(a,0,sizeof(a));
  int n = -1;
  for(int i = l ;i <= r ;i ++)
	  a[++n] = str[i];
}
void jieb(int l ,int r)
{
  memset(b,0,sizeof(b));
  int n = -1;
  for(int i = l ;i <= r ;i ++)
	  b[++n] = str[i];
}
void jiec(int l , int r)
{
  memset(c,0,sizeof(c));
  int n = -1;
  for(int i = l ;i <= r ;i ++)
	  c[++n] = str[i];
}
void jie(int l, int r)
{
  memset(temp,0,sizeof(temp));
  int n = -1;
  for(int i = l ;i <= r ;i ++)
	  temp[++n] = str[i];
}
int solve1(int x, int y )
{
  jie(0,x-1);
  if(strcmp(a,temp) != 0 )
	  return 0 ;
  jie(x,x+y-1);
  if(strcmp(temp,b) != 0 )
	  return 0 ;
  jie(x+y,2*x+y -1);
  if(strcmp(a,temp) != 0 )
	  return 0 ;
  jie(2*x+y ,2*x+2*y -1);
  if(strcmp(b,temp) != 0 )
	  return 0 ;
  jie(2*x+2*y,3*x+2*y-1);
  if(strcmp(a,temp) != 0 )
	  return 0 ;
  return 1;
}
int n ;
int solve2(int x, int y)
{
  jie(0,x-1);
  if(strcmp(a,temp) != 0 )
	  return 0 ;
  jie(x,x+y-1);
  if(strcmp(temp,b) != 0 )
	  return 0 ;
  jie(x+y,2*x+y -1);
  if(strcmp(a,temp) != 0 )
	  return 0 ;
  jie(2*x+y ,2*x+2*y -1);
  if(strcmp(b,temp) != 0 )
	  return 0 ;
  jie(n-x-y,n-y-1);
  if(strcmp(a,temp) != 0 )
	  return 0; 
  jie(n-y,n-1);
  if(strcmp(b,temp) != 0)
	  return 0;
  return 1;
}
int main(){
    int t; 
	scanf("%d",&t);
	getchar();
	while(t--)
	{
	   memset(str,0,sizeof(str));
	   memset(a,0,sizeof(a));
	   memset(b,0,sizeof(b));
	   gets(temp);
       //puts(temp);
	   n = -1;
	   int len = strlen(temp);
	   int ok = 0 ; 
	   for(int i = 0 ;i < len ;i ++)
	   {
		 // printf("%c",temp[i]);
	      if((temp[i] <= 'z' && temp[i] >= 'a')||(temp[i] >= 'A' && temp[i] <= 'Z')) 
		  {
			//printf("*");
		    str[++n] = temp[i];
		  }
	   }
	   //puts(str);
	   n ++ ;
	   for(int i = 1;i <= n;i ++  )
		   for(int j = 1;j <= n;j ++)
		   {
		      if(3*i + 2*j == n)
			  {
				  jiea(0,i-1);
				  jieb(i,i+j-1);
				  if(solve1(i,j) && strcmp(a,b) != 0 )
				  { 
					  ok = 1; 
				  }
			  }
			  if(3*i + 3*j < n)
			  {
				  jiea(0,i-1);
				  jieb(i,i+j-1);
				  jiec(2*i+2*j,n-i-j-1);
			     if(solve2(i,j) && strcmp(a,b) != 0 && strcmp(b,c) != 0 && strcmp(a,c) != 0)
				 {
					 ok = 1;
				 }
			  }
		   }
	   if(ok)
		   printf("Yes\n");
	   else printf("No\n");
	}
return 0;
}
