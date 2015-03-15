// File Name: a.c
// Author: darkdream
// Created Time: 2013年05月21日 星期二 16时46分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define ll long long 
ll p,q,n,a[1000];
void swap(ll *a, ll *b)
{
    ll temp;
	temp = *a; 
	*a = *b ; 
	*b = temp;
}
bool ck()
{
  for(ll i = 1 ;i <=n;i ++)
  {
     if(q == 0 ) return false;
	 if((p/q) <a[i])  return false;
	 p -= q*a[i];
	 swap(&p,&q);
  }
  return (q== 0);
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%lld %lld %lld",&p,&q,&n);
  
  for(ll i = 1; i <= n; i ++)
   {
      scanf("%lld",&a[i]);
	  
   }
   if(ck())
	   printf("YES\n");
   else
	   printf("NO\n");
return 0 ;
}
