// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年11月01日 星期六 09时03分03秒

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
#define eps  1e-8
using namespace std;
struct node{
  char str[20];
  int v; 
}a[1005];
int cmp(int x,int y)
{
  int tt = strcmp(a[x].str,a[y].str);
  if(tt < 0 )
	  return 1;
  else if(tt > 0 )
	  return 0 ; 
  else {
    return a[x].v > a[y].v;
  }
}
int tr[1005];
int lowbit(int x)
{
  return x & (-x);
}
void update(int x )
{
  while(x <= 1002)
	{
	   tr[x] ++;
	   x += lowbit(x);
	}
}
int getsum(int r)
{
	int sum = 0; 
    while(r >= 1)
	{
	   sum += tr[r];
	   r -= lowbit(r);
	}
	return sum;
}
int b[1005];
int main(){
    int n;
	scanf("%d",&n);
	
	for(int i =1 ;i <= n;i ++)
	{
	    scanf("%s %d",a[i].str,&a[i].v);
	    b[i] = i ; 
	}

	sort(b+1,b+1+n,cmp);
    
	
	int num = 0;
	for(int i = 1;i <= n;i ++)
	{
	  if(strcmp(a[b[i]].str,a[b[i-1]].str)!= 0 )
	  {
		num ++;
	    update(a[b[i]].v+1);
	  }
	}
	printf("%d\n",num);
	for(int i = 1;i <= n;i ++)
	{
	  if(strcmp(a[b[i]].str,a[b[i-1]].str)!= 0 )
	  {
	      int x = getsum(a[b[i]].v);
		  printf("%s ",a[b[i]].str);
		  double tt = x*1.0/num;
		  double tt1 = getsum(a[b[i]].v+1)*1.0/num;
		  if(tt1 >= 0.99 - eps)
		  {
		    puts("pro");
		  }else if(tt1 >= 0.9 -eps && 1-tt1 > 0.01 )
		  {
		    puts("hardcore");
		  }else if(tt1 >= 0.8 -eps&& 1- tt1 > 0.1){
		     puts("average"); 
		  }else if((tt1 >= 0.5 -eps&& 1 - tt1 > 0.2)){
		    puts("random");
		  }else {//if(tt > 0.5){
		    puts("noob");
		  }
	  }
	   
	}

	return 0;
}
